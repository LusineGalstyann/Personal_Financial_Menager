#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_Exit_clicked()
{
    close();
}

void MainWindow::on_Add_clicked()
{
    hide();
    window = new Add_Transfer(this);
    window->show();
}

void MainWindow::on_View_clicked()
{
    hide();
    vwindow = new View(this);
    vwindow->show();
}

