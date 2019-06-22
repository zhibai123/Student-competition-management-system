#include "user_main.h"
#include "ui_user_main.h"

user_main::user_main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_main)
{
    ui->setupUi(this);
}

user_main::~user_main()
{
    delete ui;
}

void user_main::on_pushButton_5_clicked()
{
    this->hide();
    si->show();
    si->exec();
}

void user_main::on_pushButton_4_clicked()
{
    this->hide();
    ci->show();
    ci->exec();
}

void user_main::on_pushButton_2_clicked()
{
    this->close();
}

void user_main::on_pushButton_7_clicked()///竞赛报名
{
    QString st_no=ui->lineEdit_5->text();
    QString st_name=ui->lineEdit_6->text();
    QString st_class=ui->comboBox->currentText();
    QString pr_name=ui->comboBox_2->currentText();
    QString phone=ui->lineEdit_7->text();
    QString email=ui->lineEdit_8->text();
    if(st_no!=""&&st_name!=""&&st_class!=""&&pr_name!=""&&phone!="")
    {
        qDebug()<<" * "<<st_no<<" * "<<st_name<<" * "<<st_class<<" * "<<pr_name<<" * "<<phone<<" * "<<email;
        QSqlQuery query;
        query.prepare("replace into student_registration(st_no,st_name,class_name,pr_name,st_phone,st_email) "
                      "values(:str1,:str2,:str3,:str4,:str5,:str6)");
        query.bindValue(":str1", st_no);
        query.bindValue(":str2", st_name);
        query.bindValue(":str3", st_class);
        query.bindValue(":str4", pr_name);
        query.bindValue(":str5", phone);
        query.bindValue(":str6", email);
        query.exec();
        QMessageBox::warning(this,tr("恭喜！！！"),tr("报名成功!"),QMessageBox::Yes);
        clear1();
       // close();
    }
    else
    {
        QMessageBox::warning(this,tr("警告！！！"),tr("信息不全，请补全!"),QMessageBox::Yes);
    }

}
void user_main::clear1()
{
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
}

void user_main::on_pushButton_8_clicked()
{
    clear1();
}
