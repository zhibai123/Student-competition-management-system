#ifndef COMPETITION_INFORMATION_H
#define COMPETITION_INFORMATION_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QDataStream>
#include <QDebug>
//#include "score_inquiry.h"

namespace Ui {
class competition_information;
}

class competition_information : public QDialog
{
    Q_OBJECT

public:
    explicit competition_information(QWidget *parent = 0);
    ~competition_information();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::competition_information *ui;
    QSqlTableModel* model;
    QDialog * dialog;
    // score_inquiry *si= new score_inquiry;
};

#endif // COMPETITION_INFORMATION_H
