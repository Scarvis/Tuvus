#ifndef INFOCLASS_H
#define INFOCLASS_H
#include <QVector>
#include <QRect>
class InfoClass
{
public:
    InfoClass();
    InfoClass(int x, int y, int width, int height);
    InfoClass(int number, int x, int y, int width, int height, QVector<InfoClass> answers);
    //InfoClass(InfoClass infoClass);
    int number() const;
    int x() const;
    int y() const;
    int width() const;
    int height() const;
	int isQuest() const; //bool
    QVector<InfoClass> answers() const;
    QRect getQRect();
    void setNumber(int Number);
    void setX(int X);
    void setY(int Y);
    void setWidth(int Width);
    void setHeight(int Height);
	void setQuest(int IsQuest);
    void setAnswers(QVector<InfoClass> Answers);
private:
    int Number;
    int X, Y, Width, Height;
	int IsQuest = 0;
    QVector<InfoClass> Answers;
};

#endif // INFOCLASS_H
