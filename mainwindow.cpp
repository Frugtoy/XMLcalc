#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xmlparser.h"
#include <QFileDialog>
#include<QString>
#include<QVector>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->parse, &QPushButton::released, this, &MainWindow::parse);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::parse(){
    xmlparser machine;
    machine.write(QFileDialog::getSaveFileName(this,tr("Save"),"/home",tr(""))
   ,machine.parse(QFileDialog::getOpenFileName(this,tr("Open"),"/home",tr(""))));
}
