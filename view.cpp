#include "view.h"
#include "ui_view.h"
#include "add_transfer.h"

View::View(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    Add_Transfer addTransferInstance;

    model=new QSqlTableModel(this, addTransferInstance.getDatabase());
    model->setTable("Show_transaction");
    model->select();

    ui->tableView -> setModel (model);
}

View::~View()
{
    delete ui;
}

void View::on_VBack_clicked()
{
    close();
    parentWidget()->show();
}


void View::on_delete_2_clicked()
{

    if (row >= 0 && row < model->rowCount()) {
        model->removeRow(row);
        if (model->submitAll()) {
            model->select();
        }
    }

}

void View::on_tableView_clicked(const QModelIndex &index)
{
    row=index.row();
}

