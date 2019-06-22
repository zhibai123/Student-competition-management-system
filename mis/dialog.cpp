#include "dialog.h"
#include "ui_dialog.h"
#include<mainwindow.h>
#include<QMessageBox>
#include<QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit_5->setEchoMode(QLineEdit::Password);
    ui->lineEdit_6->setEchoMode(QLineEdit::Password);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_7_clicked()///注册
{
    QString dp_id;
    QString class_id;
    QString st_no=ui->lineEdit->text();
    QString st_name=ui->lineEdit_2->text();
    QString st_pwd=ui->lineEdit_5->text();
    QString st_pwd1=ui->lineEdit_6->text();
    QString st_sex=ui->comboBox_3->currentText();
    QString st_dep=ui->comboBox->currentText();
    QString st_class=ui->comboBox_2->currentText();
    if(st_no!=""&&st_name!=""&&st_pwd!="")
    {
        if(st_pwd!=st_pwd1)
        {
            QMessageBox::warning(this,tr("警告！！！"),tr("两次密码不同!"),QMessageBox::Yes);
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();

        }
        else
        {
            if(st_dep=="计算机科学与工程系")
                dp_id="1";
            else
                dp_id="2";
            if(st_class=="网络工程1班")
                class_id="1";
            else if(st_class=="网络工程2班")
                class_id="2";
            else if(st_class=="网络工程3班")
                class_id="3";
            else if(st_class=="物联网技术1班")
                class_id="4";
            else if(st_class=="物联网技术2班")
                class_id="5";
            else if(st_class=="计算机科学与技术1班")
                class_id="6";
            else
                class_id="7";

            QSqlQuery query;
            query.prepare("replace into student(st_no,st_password,st_name,st_sex,class_id,dp_id) "
                          "values(:str1,:str2,:str3,:str4,:str5,:str6)");
            query.bindValue(":str1", st_no);
            query.bindValue(":str2", st_pwd);
            query.bindValue(":str3", st_name);
            query.bindValue(":str4", st_sex);
            query.bindValue(":str5", class_id);
            query.bindValue(":str6", dp_id);
            query.exec();
            QMessageBox::warning(this,tr("恭喜！！！"),tr("注册成功!"),QMessageBox::Yes);
            clear1();
        }

    }
    else
    {
        QMessageBox::warning(this,tr("警告！！！"),tr("信息不全，请补全!"),QMessageBox::Yes);
    }


}
void Dialog::clear1()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->comboBox_3->clear();
    ui->comboBox->clear();
    ui->comboBox_2->clear();
}
void Dialog::on_pushButton_clicked()///用户登陆
{
     QMessageBox::warning(this,tr("警告！！！"),tr("可直接退出!"),QMessageBox::Yes);
}

void Dialog::on_pushButton_3_clicked()
{
    QMessageBox::warning(this,tr("警告！！！"),tr("你还没有登录，请登陆!"),QMessageBox::Yes);
}

void Dialog::on_pushButton_4_clicked()
{
    QMessageBox::warning(this,tr("警告！！！"),tr("你还没有登录，请登陆!"),QMessageBox::Yes);
}

void Dialog::on_pushButton_5_clicked()
{
    QMessageBox::warning(this,tr("警告！！！"),tr("你还没有登录，请登陆!"),QMessageBox::Yes);
}
