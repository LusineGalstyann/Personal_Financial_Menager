#ifndef ADD_TRANSFER_H
#define ADD_TRANSFER_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>


namespace Ui {
class Add_Transfer;
}

class Add_Transfer : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Transfer(QWidget *parent = nullptr);
    ~Add_Transfer();
    QSqlDatabase getDatabase() const;


private slots:
    void on_Back_clicked();
    void on_Save_clicked();

private:
    Ui::Add_Transfer *ui;
    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // ADD_TRANSFER_H
