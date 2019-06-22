#ifndef COMPETITION_INFORMATION_TEACHER_H
#define COMPETITION_INFORMATION_TEACHER_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QDataStream>
#include "competition_information_release.h"
namespace Ui {
class competition_information_teacher;
}

class competition_information_teacher : public QDialog
{
    Q_OBJECT

public:
    explicit competition_information_teacher(QWidget *parent = 0);
    ~competition_information_teacher();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    //void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

private:
    Ui::competition_information_teacher *ui;
    QSqlTableModel* model;
    competition_information_release *cir=new competition_information_release;
    QDialog * dialog;
};

#endif // COMPETITION_INFORMATION_TEACHER_H
