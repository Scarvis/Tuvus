#include "documentslistmodel.h"
#include "documentslistmodule.h"

DocumentsListModel::DocumentsListModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int DocumentsListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;


    return mList->items().size();

    // FIXME: Implement me!
}

QVariant DocumentsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const documentsListItem item = mList->items().at(index.row());
    switch (role) {
    case PathFile:
        return QVariant(item.pathFile);
    case NameFile:
        return QVariant(item.nameFile);
    }
    return QVariant();
}

bool DocumentsListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!mList)
        return false;
    if (!hasIndex(index.row(), index.column(), index.parent()) || !value.isValid())
        return false;

    documentsListItem item = mList->items().at(index.row());
    switch (role) {
    case PathFile:
        item.pathFile = value.toString();
        break;
    case NameFile:
        item.nameFile = value.toString();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags DocumentsListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

QHash<int, QByteArray> DocumentsListModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[PathFile] = "pathFile";
    names[NameFile] = "nameFile";
    return names;
}

DocumentsListModule *DocumentsListModel::list() const
{
    return mList;
}

void DocumentsListModel::setList(DocumentsListModule *list)
{
    beginResetModel();
    if(mList)
        mList->disconnect(this);

    mList = list;

    if(mList)
    {
        connect(mList, &DocumentsListModule::preItemAppend, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });

        connect(mList, &DocumentsListModule::postItemAppend, this, [=]() {
            endInsertRows();
        });
    }
    endResetModel();
}
