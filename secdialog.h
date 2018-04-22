#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    MainWindow conn;
    explicit SecDialog(QWidget *parent = 0);
    ~SecDialog();

private slots:
    void on_SaveInput_accepted();

    void on_pushButton_4_load_table_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_refresh_clicked();

private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H
