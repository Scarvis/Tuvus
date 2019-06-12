#include "infoclass.h"

InfoClass::InfoClass()
{

}

InfoClass::InfoClass(int x, int y, int width, int height)
{
    this->X = x;
    this->Y = y;
    this->Width = width;
    this->Height = height;
}

InfoClass::InfoClass(int number, int x, int y, int width, int height, QVector<InfoClass> answers)
{
    this->Number = number;
    this->X = x;
    this->Y = y;
    this->Width = width;
    this->Height = height;
    this->Answers = answers;
}

InfoClass::InfoClass(QString x, QString y, QString width, QString height)
{
	this->X = x.toInt();
	this->Y = y.toInt();
	this->Width = width.toInt();
	this->Height = height.toInt();
}

int InfoClass::number() const
{
    return Number;
}

int InfoClass::x() const
{
    return X;
}

int InfoClass::y() const
{
    return Y;
}

int InfoClass::width() const
{
    return Width;
}

int InfoClass::height() const
{
    return Height;
}

int InfoClass::isQuest() const
{
	return IsQuest;
}

QVector<InfoClass> InfoClass::answers() const
{
    return Answers;
}

QRect InfoClass::getQRect()
{
    return QRect(X, Y, Width, Height);
}

void InfoClass::setNumber(int Number)
{
    this->Number = Number;
}

void InfoClass::setX(int X)
{
    this->X = X;
}

void InfoClass::setY(int Y)
{
    this->Y = Y;
}

void InfoClass::setWidth(int Width)
{
    this->Width = Width;
}

void InfoClass::setHeight(int Height)
{
    this->Height = Height;
}

void InfoClass::setQuest(int IsQuest)
{
	this->IsQuest = IsQuest;
}

void InfoClass::setAnswers(QVector<InfoClass> Answers)
{
    this->Answers = Answers;
}
