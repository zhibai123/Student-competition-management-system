#include "competition_information_teacher.h"
#include "ui_competition_information_teacher.h"
#include <QDebug>
#include<teacher_main.h>

competition_information_teacher::competition_information_teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::competition_information_teacher)
{
    ui->setupUi(this);
    //connect(ui->pushButton_7,competition_information_release::mysignal,this,competition_information_teacher::show);
}

competition_information_teacher::~competition_information_teacher()
{
    delete ui;
}

void competition_information_teacher::on_pushButton_6_clicked()
{
    model = new QSqlTableModel (this);
    model->setTable("project");
    //model->setFilter(QString("id= '%1'").arg(name));
    model->select();
    model->setHeaderData(1, Qt::Horizontal, tr("名称"));
    model->setHeaderData(2, Qt::Horizontal, tr("比赛时间"));
    model->setHeaderData(4, Qt::Horizontal, tr("报名开始时间"));
    model->setHeaderData(5, Qt::Horizontal, tr("报名结束时间"));
    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(6);
}

void competition_information_teacher::on_pushButton_5_clicked()///成绩查询
{
    dialog=new score_inquiry_all(this);
    this->hide();
    dialog->show();
}

void competition_information_teacher::on_pushButton_2_clicked()///退出登陆
{
    this->close();
}


void competition_information_teacher::on_pushButton_7_clicked()
{
    this->hide();
    cir->show();
    cir->exec();
}

void competition_information_teacher::on_pushButton_clicked()///竞赛报名信息
{
    dialog=new teacher_main(this);
    this->hide();
    dialog->show();
}
