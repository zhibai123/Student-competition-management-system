#include "competition_information_release.h"
#include "ui_competition_information_release.h"
#include <teacher_main.h>
#include <score_inquiry_all.h>
#include <competition_information_teacher.h>

competition_information_release::competition_information_release(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::competition_information_release)
{
    ui->setupUi(this);
   // ui->pushButton_4->setParent(this);
}

competition_information_release::~competition_information_release()
{
    delete ui;
}

void competition_information_release::on_pushButton_7_clicked()///竞赛信息发布
{
    QString str1=ui->lineEdit->text();
    QString str2=ui->dateEdit->text();
    QString str3=ui->lineEdit_2->text();
    QString str4=ui->dateEdit_2->text();
    QString str5=ui->dateEdit_3->text();
    QString str6=ui->textEdit->toPlainText();
    qDebug()<<str1<<" * "<<str2<<" * "<<str3<<" * "<<str4<<" * "<<str5<<" * "<<str6;
    QSqlQuery query;
    query.prepare("replace into project (pr_name, pr_time,pr_trainaddress,pr_start,pr_end,pr_info) "
                  "values(:str1,:str2,:str3,:str4,:str5,:str6)");
    query.bindValue(":str1", str1);
    query.bindValue(":str2", str2);
    query.bindValue(":str3", str3);
    query.bindValue(":str4", str4);
    query.bindValue(":str5", str5);
    query.bindValue(":str6", str6);
    query.exec();


}
void competition_information_release::on_pushButton_8_clicked()
{
    clear1();
}

void competition_information_release::clear1()
{
    ui->lineEdit->clear();
    ui->dateEdit->clear();
    ui->lineEdit_2->clear();
   // ui->dateEdit_2->clear();
    //ui->dateEdit_3->clear();
    ui->textEdit->clear();

}

void competition_information_release::on_pushButton_5_clicked()///成绩查询
{
    dialog=new score_inquiry_all(this);
    this->hide();
    dialog->show();
}

void competition_information_release::on_pushButton_2_clicked()///关闭按钮
{
    this->close();
}

void competition_information_release::on_pushButton_4_clicked()
{
    dialog=new competition_information_teacher(this);
    this->hide();
    dialog->show();
}

void competition_information_release::on_pushButton_clicked()
{
    dialog=new teacher_main(this);
    this->hide();
    dialog->show();
}
