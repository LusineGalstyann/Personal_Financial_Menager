#ifndef VIEW_H
#define VIEW_H

#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "add_transfer.h"

namespace Ui {
class View;
}

class View : public QDialog
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    ~View();

private slots:
    void on_VBack_clicked();
    void on_delete_2_clicked();
    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::View *ui;
    QSqlTableModel *model;
    Add_Transfer addTransferInstance;
    int row;
};

#endif // VIEW_H
