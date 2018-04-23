#include "secdialog.h"
#include "ui_secdialog.h"
#include <QMessageBox>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    //shows connected status to DB.
       if(!conn.connOpen())
           ui->label_sec_status->setText("Failed to open the database");
       else
           ui->label_sec_status->setText("Connected...");
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_SaveInput_accepted()
{

}

void SecDialog::on_pushButton_4_load_table_clicked()
{

}

void SecDialog::on_pushButton_clicked()
{
    QString  uid, name, graduation;
    uid=ui->uid->text();
    name=ui->sname->text();
    graduation=ui->grad->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into Students (uid,name,graduation) values ('"+uid+"','"+name+"','"+graduation+"')");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Save"), tr("Information Saved."));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}

void SecDialog::on_pushButton_4_refresh_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.school);

    qry->prepare("select * from Students");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());
}

void SecDialog::on_pushButton_2_update_clicked()
{
    QString  uid, name, graduation;
    uid=ui->uid->text();
    name=ui->sname->text();
    graduation=ui->grad->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update Students set uid='"+uid+"',name='"+name+"',graduation='"+graduation+"' where uid='"+uid+"'");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Edit"), tr("Information Updated."));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}

void SecDialog::on_pushButton_3_delete_clicked()
{
    QString  uid, name, graduation;
    uid=ui->uid->text();
    //name=ui->sname->text();
    //graduation=ui->grad->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("delete from Students where uid=='"+uid+"'");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Delete"), tr("Information Deleted."));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}
