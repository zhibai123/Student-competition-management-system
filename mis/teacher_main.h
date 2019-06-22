#ifndef TEACHER_MAIN_H
#define TEACHER_MAIN_H

#include <QDialog>

#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QDataStream>
#include "score_inquiry_all.h"
#include "competition_information_teacher.h"
#include "competition_information_release.h"
namespace Ui {
class teacher_main;
}

class teacher_main : public QDialog
{
    Q_OBJECT

public:
    explicit teacher_main(QWidget *parent = 0);
    ~teacher_main();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::teacher_main *ui;
    QSqlTableModel* model;
    score_inquiry_all *sia=new score_inquiry_all;
    competition_information_teacher * cit =new competition_information_teacher;
    competition_information_release *cir=new competition_information_release;
};

#endif // TEACHER_MAIN_H
