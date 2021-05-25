#include "myglwidget.h"
#include <QPainter>

myGlWidget::myGlWidget(QWidget *parent)
                       : QOpenGLWidget(parent)
{
    mypainter = new myPainter;
}

void myGlWidget::draw_new_graph()
{
    this->update();
}

void myGlWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    mypainter->draw(&painter, event, adj_matrix);
    painter.end();
}
