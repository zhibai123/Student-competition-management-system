#ifndef USER_MAIN_H
#define USER_MAIN_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include "score_inquiry.h"
#include "competition_information.h"
namespace Ui {
class user_main;
}

class user_main : public QDialog
{
    Q_OBJECT

public:
    explicit user_main(QWidget *parent = 0);
    ~user_main();
    void clear1();
private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::user_main *ui;
    score_inquiry *si= new score_inquiry;
    competition_information *ci=new competition_information;
};

#endif // USER_MAIN_H
