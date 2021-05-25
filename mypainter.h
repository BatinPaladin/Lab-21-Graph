#ifndef MYPAINTER_H
#define MYPAINTER_H


#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class myPainter
{
public:
    myPainter();

public:
    void draw(QPainter *painter, QPaintEvent *event, int adj_matrix[6][6]);
    QBrush shape;

private:
    QBrush background;
    QFont glFont;
    QPen textPen;
};

#endif // MYPAINTER_H
