#include "mypainter.h"
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QtMath>

const int knot_count = 7;
const int text_size = 24;
const int graph_R = 200;
const double pi = 3.1415;
const int shift_x = 250;
const int shift_y = 250;
const int knot_R = 34;

myPainter::myPainter()
{
    shape = QBrush(QColor(168, 168, 129));
    background = QBrush(QColor(235, 235, 235));
    textPen = QPen(QColor(71, 98, 68));
    glFont.setPixelSize(text_size);
}

void myPainter::draw(QPainter *painter, QPaintEvent *event, int adj_matrix[knot_count-1][knot_count-1])
{
    painter->fillRect(event->rect(), background);
    painter->setBrush(shape);
    painter->setPen(textPen);
    painter->setFont(glFont);
    textPen.setWidth(4);
    for (int i = 0; i < knot_count-1; i++)
    {
        double angel = pi * 3/2 + pi * 2 / knot_count * i;
        int knot_x = cos(angel) * graph_R + shift_x;
        int knot_y = sin(angel) * graph_R + shift_y;
        painter->drawEllipse(QRectF(knot_x - knot_R, knot_y - knot_R,
                                    2 * knot_R, 2 * knot_R));
        QString text;
        int text_x = knot_x - knot_R / 2;
        int text_y = knot_y - text_size / 2;
        text.setNum(i + 1);
        painter->drawText(QRect(text_x, text_y, knot_R, text_size),
                          Qt::AlignCenter, text);
        for (int k = 0; k < knot_count-1; k++)
        {
            if (adj_matrix[i][k] > 0)
            {
                angel = pi * 3/2 + pi * 2 / knot_count * k;
                double line_x = cos(angel) * graph_R + shift_x;
                double line_y = sin(angel) * graph_R + shift_y;
                double line_length = sqrt((line_x - knot_x) *
                                          (line_x - knot_x) +
                                          (line_y - knot_y) *
                                          (line_y - knot_y));
                int l_x1 = (line_x - knot_x) / line_length * knot_R
                            + knot_x;
                int l_y1 = (line_y - knot_y) / line_length * knot_R
                            + knot_y;
                int l_x2 = line_x - (line_x - knot_x) / line_length *
                           knot_R;
                int l_y2 = line_y - (line_y - knot_y) / line_length *
                           knot_R;
                painter->drawLine(l_x1, l_y1, l_x2, l_y2);
                text_x = (l_x2 + l_x1) / 2 - knot_R / 2;
                text_y = (l_y2 + l_y1) / 2 - text_size / 2;
                text.setNum(adj_matrix[i][k]);
                painter->drawRect(QRectF(text_x, text_y, knot_R, text_size));
                painter->drawText(QRect(text_x, text_y, knot_R, text_size),
                                Qt::AlignCenter, text);
            }
        }
    }
}
