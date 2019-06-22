#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialog.h"
#include <QMainWindow>
#include <QtWidgets>
#include "user_main.h"
#include "teacher_main.h"
#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QDataStream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init_sql();
private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *d=new Dialog ;
    user_main *u = new user_main;
    teacher_main *t=new teacher_main;
    // use_main *u = new Dialog;
};

#endif // MAINWINDOW_H
