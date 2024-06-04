#include "add_transfer.h"
#include "ui_add_transfer.h"

Add_Transfer::Add_Transfer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add_Transfer)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./PFMDB.db");

    if(db.open())    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }
    query= new QSqlQuery(db);
    query->exec("Create Table Show_transaction(name text,price int,date VARCHAR)");
}
Add_Transfer::~Add_Transfer()
{
    delete ui;
}
void Add_Transfer::on_Back_clicked()
{
    close();
    parentWidget()->show();
}

void Add_Transfer::on_Save_clicked()
{

    QString name = ui->name->text();
    QString price = ui->price->text();

    QString currentDate = QDate::currentDate().toString(Qt::ISODate);

    QString insertQuery = "INSERT INTO Show_transaction (name, price, date) VALUES (:name, :price, :date)";
    query->prepare(insertQuery);
    query->bindValue(":name", name);
    query->bindValue(":price", price);
    query->bindValue(":date", currentDate);

    if (query->exec())
    {
        qDebug() << "Data inserted successfully";

        ui->name->clear();
        ui->price->clear();
    }
    else
    {
        qDebug() << "Failed to insert data";
    }


}
QSqlDatabase Add_Transfer::getDatabase() const {
    return db;
}
