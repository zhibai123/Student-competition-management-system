#include "score_inquiry.h"
#include "ui_score_inquiry.h"
#include<user_main.h>

score_inquiry::score_inquiry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::score_inquiry)
{
    ui->setupUi(this);
}

score_inquiry::~score_inquiry()
{
    delete ui;
}

void score_inquiry::on_pushButton_6_clicked()//姓名查询学生成绩
{
    QString   name=ui->lineEdit->text();

    model = new QSqlTableModel (this);
    model->setTable("performance");
    model->setFilter(QString("st_name= '%1'").arg(name));
    model->select();
    model->setHeaderData(1, Qt::Horizontal, tr("比赛名称"));
    model->setHeaderData(2, Qt::Horizontal, tr("姓名"));
    model->setHeaderData(5, Qt::Horizontal, tr("成绩"));
    ui->tableView->setModel(model);
     ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(6);

}

void score_inquiry::on_pushButton_4_clicked()
{
    this->hide();
    ci->show();
    ci->exec();
}

void score_inquiry::on_pushButton_2_clicked()
{
    this->close();
}

void score_inquiry::on_pushButton_clicked()
{
    dialog=new user_main(this);
    this->hide();
    dialog->show();
}
