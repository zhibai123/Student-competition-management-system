#ifndef SCORE_INQUIRY_ALL_H
#define SCORE_INQUIRY_ALL_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QDataStream>
#include "competition_information_teacher.h"

namespace Ui {
class score_inquiry_all;
}

class score_inquiry_all : public QDialog
{
    Q_OBJECT

public:
    explicit score_inquiry_all(QWidget *parent = 0);
    ~score_inquiry_all();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::score_inquiry_all *ui;
    QSqlTableModel* model;
    competition_information_teacher * cit =new competition_information_teacher;
    QDialog * dialog;
};

#endif // SCORE_INQUIRY_ALL_H
