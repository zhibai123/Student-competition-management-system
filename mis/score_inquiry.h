#ifndef SCORE_INQUIRY_H
#define SCORE_INQUIRY_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QDataStream>
#include "competition_information.h"

namespace Ui {
class score_inquiry;
}

class score_inquiry : public QDialog
{
    Q_OBJECT

public:
    explicit score_inquiry(QWidget *parent = 0);
    ~score_inquiry();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::score_inquiry *ui;
    QSqlTableModel* model;
    competition_information *ci=new competition_information;
    QDialog * dialog;
};

#endif // SCORE_INQUIRY_H
