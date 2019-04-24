#ifndef DOCUMENTSLISTMODEL_H
#define DOCUMENTSLISTMODEL_H

#include <QAbstractListModel>

class DocumentsListModule;

class DocumentsListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(DocumentsListModule *list READ list WRITE setList)

public:
    explicit DocumentsListModel(QObject *parent = nullptr);

    enum {
        PathFile = Qt::UserRole,
        NameFile
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    DocumentsListModule *list() const;
    void setList(DocumentsListModule *list);

private:
    DocumentsListModule *mList;
};

#endif // DOCUMENTSLISTMODEL_H
