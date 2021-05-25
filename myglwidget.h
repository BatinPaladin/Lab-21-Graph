#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include "mypainter.h"

class myGlWidget : public QOpenGLWidget
{
public:
    myGlWidget(QWidget *parent);

public slots:
    void draw_new_graph();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    myPainter *mypainter;
    int adj_matrix[6][6] = {{-1, 12, 18, 5, 0, 34},
                            {12, -1, 16, 0, 53, 45},
                            {18, 16, -1, 3, 21, 0},
                            {5, 0, 3, -1, 0, 0},
                            {0, 53, 21, 0, -1, 0},
                            {34, 45, 0, 0, 0, -1}};;
};

#endif // MYGLWIDGET_H
