#include "infoclass.h"

InfoClass::InfoClass()
{

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

QVector<InfoClass> InfoClass::answers() const
{
    return Answers;
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

void InfoClass::setAnswers(QVector<InfoClass> Answers)
{
    this->Answers = Answers;
}
