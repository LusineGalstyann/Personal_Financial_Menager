#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <add_transfer.h>
#include <view.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Exit_clicked();
    void on_Add_clicked();
    void on_View_clicked();

private:
    Ui::MainWindow *ui;
    Add_Transfer *window;
    View *vwindow;



};
#endif // MAINWINDOW_H
