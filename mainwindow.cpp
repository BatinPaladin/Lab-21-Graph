#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openGlW = new myGlWidget(this);
    ui->verticalLayout->addWidget(openGlW);
}

MainWindow::~MainWindow()
{
    delete ui;
}

