#include "admin_main.h"
#include "ui_admin_main.h"
#include <QMessageBox>
#include <QSqlError>
#include<QTextEdit>
#include <QStandardItemModel>
#include <QTableView>

admin_main::admin_main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_main)
{
    ui->setupUi(this);
}

admin_main::~admin_main()
{
    delete ui;
}

void admin_main::on_pushButton_4_clicked()
{
        model = new QSqlTableModel(this);
        model->setTable("teacher");
        //设置保存策略
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);

        model->select(); //查询整张表

        ui->tableView->hideColumn(0);

        model->setHeaderData(1, Qt::Horizontal, QObject::tr("教师编号"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("密码"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("姓名"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("性别"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("系部号"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("信息"));




        ui->tableView->setModel(model);


}

void admin_main::on_pushButton_7_clicked()
{
    QSqlQuery query;
    query.prepare("set foreign_key_checks=0");
    query.exec();
//        int curRow = ui->tableView->currentIndex().row();
//        //获取选中的行
//        bool bF = model->removeRow(curRow);
//        //删除该行
//        int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定"
//                                                               "删除当前行吗？"),
//                             QMessageBox::Yes,QMessageBox::No);
//        if(ok == QMessageBox::No)
//        {
//           model->revertAll(); //如果不删除，则撤销
//        }
//        else
//            bF = model->submitAll(); //否则提交，在数据库中删除该行
//        query.prepare("set foreign_key_checks=1");
//        query.exec();
    //获取选中行
    int curRow = ui->tableView->currentIndex().row();
    //删除该行
    model->removeRow(curRow); //只是model中删除，还未提交到数据库

    int ok = QMessageBox::warning(this,QStringLiteral("删除当前行"),
                                  QStringLiteral("确定与否？"),
                                  QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
        model->revertAll();
    else
        model->submitAll();

}

void admin_main::on_pushButton_clicked()
{
    model->database().transaction();//开始事物操作
        if(model->submitAll())
            model->database().commit();
        else{
            model->database().rollback(); //回滚
            QMessageBox::warning(this,tr("tableModel"),
                                 QStringLiteral("数据库错误:")+tr("%1").arg(model->lastError().text()));
        }

}

void admin_main::on_pushButton_5_clicked()
{
    model = new QSqlTableModel(this);
    model->setTable("student");
    //设置保存策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->select(); //查询整张表

    ui->tableView->hideColumn(0);

    model->setHeaderData(1, Qt::Horizontal, QObject::tr("学号"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("密码"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("姓名"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("性别"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("班级号"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("系部号"));
    ui->tableView->setModel(model);
}

void admin_main::on_pushButton_2_clicked()
{
    //获取选中行
    int curRow = ui->tableView->currentIndex().row();
    //删除该行
    model->removeRow(curRow); //只是model中删除，还未提交到数据库

    int ok = QMessageBox::warning(this,QStringLiteral("删除当前行"),
                                  QStringLiteral("确定与否？"),
                                  QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
        model->revertAll();
    else
        model->submitAll();
}

void admin_main::on_pushButton_8_clicked()
{
    model->database().transaction();//开始事物操作
        if(model->submitAll())
            model->database().commit();
        else{
            model->database().rollback(); //回滚
            QMessageBox::warning(this,tr("tableModel"),
                                 QStringLiteral("数据库错误:")+tr("%1").arg(model->lastError().text()));
        }
}

void admin_main::on_pushButton_6_clicked()
{
    model = new QSqlTableModel(this);
    model->setTable("performance");
    //设置保存策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->select(); //查询整张表

        ui->tableView->hideColumn(0);

        model->setHeaderData(1, Qt::Horizontal, QObject::tr("竞赛名称"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("学生姓名"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("姓别"));
        ui->tableView->hideColumn(4);

        model->setHeaderData(5, Qt::Horizontal, QObject::tr("分数"));
        ui->tableView->hideColumn(6);

    ui->tableView->setModel(model);


}

void admin_main::on_pushButton_9_clicked()
{
    model->database().transaction();//开始事物操作
        if(model->submitAll())
            model->database().commit();
        else{
            model->database().rollback(); //回滚
            QMessageBox::warning(this,tr("tableModel"),
                                 QStringLiteral("数据库错误:")+tr("%1").arg(model->lastError().text()));
        }

}
