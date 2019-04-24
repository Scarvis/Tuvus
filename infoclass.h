#ifndef INFOCLASS_H
#define INFOCLASS_H
#include <QVector>

class InfoClass
{
public:
    InfoClass();
    InfoClass(int number, int x, int y, int width, int height, QVector<InfoClass> answers);
    //InfoClass(InfoClass infoClass);
    int number() const;
    int x() const;
    int y() const;
    int width() const;
    int height() const;
    QVector<InfoClass> answers() const;
    void setNumber(int Number);
    void setX(int X);
    void setY(int Y);
    void setWidth(int Width);
    void setHeight(int Height);
    void setAnswers(QVector<InfoClass> Answers);
private:
    int Number;
    int X, Y, Width, Height;
    QVector<InfoClass> Answers;

};

#endif // INFOCLASS_H
