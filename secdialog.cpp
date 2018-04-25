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
    QString  uid, Sname, graduation, major;
    uid=ui->uid->text();
    Sname=ui->sname->text();
    graduation=ui->grad->text();
    major=ui->major->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into Students (uid,Sname,graduation,major) values ('"+uid+"','"+Sname+"','"+graduation+"','"+major+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Save"), tr("Information Saved."));
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
    QString  uid, Sname, graduation, major;
    uid=ui->uid->text();
    Sname=ui->sname->text();
    graduation=ui->grad->text();
    major=ui->major->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update Students set uid='"+uid+"',Sname='"+Sname+"',graduation='"+graduation+"',major='"+major+"' where uid='"+uid+"'");

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

void SecDialog::on_pushButton_3_save_c_clicked()
{
    QString  crn, cname, department, credits, days, time, semester;
    crn=ui->crn->text();
    cname=ui->cname->text();
    department=ui->dept->text();
    credits=ui->credits->text();
    days=ui->days->text();
    time=ui->time->text();
    semester=ui->semester->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into Courses (CRN,Cname,departmentID,Credit,Days,Time,semester) values ('"+crn+"','"+cname+"','"+department+"','"+credits+"','"+days+"','"+time+"','"+semester+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Save"), tr("Information Saved."));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}

void SecDialog::on_pushButton_2_update_c_clicked()
{
    QString  crn, cname, department, credits, days, time, semester;
    crn=ui->crn->text();
    cname=ui->cname->text();
    department=ui->dept->text();
    credits=ui->credits->text();
    days=ui->days->text();
    time=ui->time->text();
    semester=ui->semester->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update Courses set CRN='"+crn+"',Cname='"+cname+"',DepartmentID='"+department+"',Credit='"+credits+"',Days='"+days+"',Time='"+time+"',semester='"+semester+"' where CRN='"+crn+"'");

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

void SecDialog::on_pushButton_3_delete_c_clicked()
{
    QString  crn;
    crn=ui->crn->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("delete from Courses where CRN=='"+crn+"'");

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

void SecDialog::on_pushButton_4_refresh_c_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.school);

    qry->prepare("select * from Courses");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_3->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());
}

void SecDialog::on_pushButton_save_f_clicked()
{
    QString  uid_faculty, fname, fdept;
    uid_faculty=ui->uid_faculty->text();
    fname=ui->fname->text();
    fdept=ui->fdept->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into Teachers (UID,name,DeptID) values ('"+uid_faculty+"','"+fname+"','"+fdept+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Save"), tr("Information Saved."));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}

void SecDialog::on_pushButton_2_update_f_clicked()
{
    QString  uid_faculty, fname, fdept;
    uid_faculty=ui->uid_faculty->text();
    fname=ui->fname->text();
    fdept=ui->fdept->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update Teachers set UID='"+uid_faculty+"',name='"+fname+"',DeptID='"+fdept+"' where UID='"+uid_faculty+"'");

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

void SecDialog::on_pushButton_3_delete_f_clicked()
{
    QString  uid_faculty;
    uid_faculty=ui->uid_faculty->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("delete from Teachers where UID=='"+uid_faculty+"'");

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

void SecDialog::on_pushButton_4_refresh_f_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.school);

    qry->prepare("select * from Teachers");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_4->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());
}

void SecDialog::on_pushButton_save_g_clicked()
{
    QString  uid_g, crn_g, semester_g, grade;
    uid_g=ui->uid_g->text();
    crn_g=ui->crn_g->text();
    semester_g=ui->semester_g->text();
    grade=ui->grade->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into Grades (uid,CRN,semester,Grade) values ('"+uid_g+"','"+crn_g+"','"+semester_g+"','"+grade+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Save"), tr("Information Saved."));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}

void SecDialog::on_pushButton_2_update_g_clicked()
{
    QString  uid_g, crn_g, semester_g, grade;
    uid_g=ui->uid_g->text();
    crn_g=ui->crn_g->text();
    semester_g=ui->semester_g->text();
    grade=ui->grade->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update Grades set uid='"+uid_g+"',CRN='"+crn_g+"',semester='"+semester_g+"',Grade='"+grade+"' where uid=='"+uid_g+"' and CRN=='"+crn_g+"' and semester=='"+semester_g+"'");

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

void SecDialog::on_pushButton_3_delete_g_clicked()
{
    QString  uid_g,crn_g,semester_g;
    uid_g=ui->uid_g->text();
    crn_g=ui->crn_g->text();
    semester_g=ui->semester_g->text();

    //SecDialog secDlog;

    if(!conn.connOpen())
    {
       qDebug()<<"Failed to open Database";
       return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("delete from Grades where uid=='"+uid_g+"' and CRN=='"+crn_g+"' and semester=='"+semester_g+"'");

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

void SecDialog::on_pushButton_4_refresh_g_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.school);

    qry->prepare("select Students.UID, Students.Sname, Courses.CRN, Courses.Cname, Grades.semester, Grades.Grade from Students,Courses,Grades where Students.UID=Grades.uid and Courses.CRN=Grades.CRN");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_5->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());
}

void SecDialog::on_pushButton_4_average_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.school);

    qry->prepare("select Students.UID, Students.Sname AS Name, avg(Grades.Grade) AS Average from Students,Grades where Students.UID=Grades.uid");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_6->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());
}

