#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QSqlRecord>
#include <string>
#include  "admin_main.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_sql();
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::init_sql()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("test1");
    db.setUserName("root");
    db.setPassword("xnxnxn12");
    db.open();
    if(!db.open())
    {
        qDebug()<<"不能连接"<<db.lastError().text();
        return;
    }
    else
    {
        qDebug()<<"mysql连接成功";
    }
}
void MainWindow::on_pushButton_7_clicked()//学生登陆
{
    QString use_id=ui->lineEdit->text();
    QString pwd=ui->lineEdit_2->text();
    QSqlQuery query;
    QString str = QString("select st_password from student where st_no='%1'").arg(use_id);
//    this->hide();
//    u->show();
//    u->exec();
           if(query.exec(str))
           {
               query.next();
               QSqlRecord s=query.record();
    //       // model->setQuery("select * from student where st_no = '%1'").arg(use_id);
    //           qDebug()<<"1234   "<<s;
    //           qDebug()<<"23456";
               QString str1=query.value(0).toString();
               qDebug()<<str1;
               if(str1==pwd&&pwd!="")
               {
                   this->hide();
                   u->show();


               }
               else
               {
                   QMessageBox::warning(this,tr("警告！！！"),tr("密码错误!"),QMessageBox::Yes);
                   ui->lineEdit->clear();
                   ui->lineEdit_2->clear();
               }
           }
           else
           {
               QMessageBox::warning(this,tr("警告！！！"),tr("账号错误!"),QMessageBox::Yes);
               ui->lineEdit->clear();
               ui->lineEdit_2->clear();
           }


}

void MainWindow::on_pushButton_8_clicked()///重置
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_pushButton_2_clicked()///用户注册
{
    this->hide();
    d->show();
    d->exec();
    this->show();
}

void MainWindow::on_pushButton_3_clicked()///竞赛信息发布
{
    QMessageBox::warning(this,tr("警告！！！"),tr("你还没有登录，请登陆!"),QMessageBox::Yes);
}

void MainWindow::on_pushButton_4_clicked()///竞赛信息
{
    QMessageBox::warning(this,tr("警告！！！"),tr("你还没有登录，请登陆!"),QMessageBox::Yes);
}

void MainWindow::on_pushButton_12_clicked()///成绩查询
{
    QMessageBox::warning(this,tr("警告！！！"),tr("你还没有登录，请登陆!"),QMessageBox::Yes);
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::warning(this,tr("警告！！！"),tr("你还没有登录，请登陆!"),QMessageBox::Yes);
}

void MainWindow::on_pushButton_9_clicked()///教师登陆
{
    QString use_id=ui->lineEdit->text();
    QString pwd=ui->lineEdit_2->text();
    QSqlQuery query;
    QString str = QString("select tc_password from teacher where tc_no='%1'").arg(use_id);
    if(query.exec(str))
    {
        query.next();
        QSqlRecord s=query.record();
        QString str1=query.value(0).toString();
        qDebug()<<str1;
        if(str1==pwd&&pwd!="")
        {
            this->hide();
            t->show();

        }
        else
        {
            QMessageBox::warning(this,tr("警告！！！"),tr("密码错误!"),QMessageBox::Yes);
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
        }
    }
    else
    {
        QMessageBox::warning(this,tr("警告！！！"),tr("账号错误!"),QMessageBox::Yes);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    }

}

///管理员登陆

void MainWindow::on_pushButton_10_clicked()
{
    QString use_id=ui->lineEdit->text();
    QString pwd=ui->lineEdit_2->text();
    QSqlQuery query;
    QString str = QString("select ad_password from admin where ad_name='%1'").arg(use_id);
    if(query.exec(str))
    {
        query.next();
        QSqlRecord s=query.record();
        QString str1=query.value(0).toString();
        qDebug()<<str1;
        if(str1==pwd&&pwd!="")
        {

            admin_main* c=new admin_main(this);
            this->hide();
            c->show();
        }
        else
        {
            QMessageBox::warning(this,tr("警告！！！"),tr("密码错误!"),QMessageBox::Yes);
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
        }
    }
    else
    {
        QMessageBox::warning(this,tr("警告！！！"),tr("账号错误!"),QMessageBox::Yes);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    }
}
