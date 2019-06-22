#ifndef COMPETITION_INFORMATION_RELEASE_H
#define COMPETITION_INFORMATION_RELEASE_H

#include <QDialog>
#include <QDebug>
#include <QtWidgets>
#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QDataStream>
//#include "score_inquiry_all.h"

namespace Ui {
class competition_information_release;
}

class competition_information_release : public QDialog
{
    Q_OBJECT

public:
    explicit competition_information_release(QWidget *parent = 0);
    ~competition_information_release();
    void clear1();
signals:
    void mysignal();
private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();
    //    void sendMysignal();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::competition_information_release *ui;
    // score_inquiry_all *si= new score_inquiry_all;
    QDialog * dialog;
};

#endif // COMPETITION_INFORMATION_RELEASE_H
