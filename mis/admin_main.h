#ifndef ADMIN_MAIN_H
#define ADMIN_MAIN_H

#include <QDialog>
#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QDataStream>
#include <QDebug>


namespace Ui {
class admin_main;
}

class admin_main : public QDialog
{
    Q_OBJECT

public:
    explicit admin_main(QWidget *parent = 0);
    ~admin_main();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::admin_main *ui;


    QSqlTableModel* model;
};

#endif // ADMIN_MAIN_H
