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

    void on_pushButton_2_update_clicked();

    void on_pushButton_3_delete_clicked();

    void on_pushButton_3_save_c_clicked();

    void on_pushButton_2_update_c_clicked();

    void on_pushButton_3_delete_c_clicked();

    void on_pushButton_4_refresh_c_clicked();

    void on_pushButton_save_f_clicked();

    void on_pushButton_2_update_f_clicked();

    void on_pushButton_3_delete_f_clicked();

    void on_pushButton_4_refresh_f_clicked();

    void on_pushButton_save_g_clicked();

    void on_pushButton_2_update_g_clicked();

    void on_pushButton_3_delete_g_clicked();

    void on_pushButton_4_refresh_g_clicked();

    void on_pushButton_4_average_clicked();
    
private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H
