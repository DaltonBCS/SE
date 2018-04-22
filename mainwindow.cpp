#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "secdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 //shows connected status to DB.
    if(!connOpen())
        ui->label_3->setText("Failed to open the database");
    else
        ui->label_3->setText("Connected...");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();
    //SecDialog secDlog;

    if(!connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from Login where username='"+username +"' and password='"+password +"'");

    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            ui->label_3->setText("username and password is correct");
            connClose();
            this->hide();
            SecDialog secDlog;
            secDlog.setModal(true);
            secDlog.exec();
        }
        if(count>1)
            ui->label_3->setText("Duplicate username and password");
        if(count<1)
            ui->label_3->setText("username and password is not correct");
    }

}
