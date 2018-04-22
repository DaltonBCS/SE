#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase school;
    void connClose()
    {
        school.close();
        school.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        school=QSqlDatabase::addDatabase("QSQLITE");
        school.setDatabaseName("C:/Users/eleaz/Downloads/sqlite-tools-win32-x86-3220000/sqlitestudio-3.1.1/SQLiteStudio/platforms/School.db");

        if(!school.open()){
              qDebug()<<("Failed to open the database");
              return false;
          }
          else {
              qDebug()<<("Connected...");
              return true;
          }
    }

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
