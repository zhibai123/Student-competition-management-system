#include "score_inquiry_all.h"
#include "ui_score_inquiry_all.h"
#include <competition_information_teacher.h>
#include <competition_information_release.h>
score_inquiry_all::score_inquiry_all(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::score_inquiry_all)
{
    ui->setupUi(this);
}

score_inquiry_all::~score_inquiry_all()
{
    delete ui;
}

void score_inquiry_all::on_pushButton_6_clicked()
{
    QString   name=ui->lineEdit->text();

    model = new QSqlTableModel (this);
    model->setTable("performance");
    model->setFilter(QString("pr_name= '%1'").arg(name));
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

void score_inquiry_all::on_pushButton_4_clicked()///竞赛信息
{
    this->hide();
    cit->show();
    cit->exec();
}

void score_inquiry_all::on_pushButton_2_clicked()///退出登陆
{
    this->close();
}

void score_inquiry_all::on_pushButton_clicked()///竞赛报名信息
{
    dialog=new competition_information_teacher(this);
    this->hide();
    dialog->show();
}

void score_inquiry_all::on_pushButton_7_clicked()
{
    dialog=new competition_information_release(this);
    this->hide();
    dialog->show();
}
