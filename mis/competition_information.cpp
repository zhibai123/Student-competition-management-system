#include "competition_information.h"
#include "ui_competition_information.h"
#include <user_main.h>
#include <score_inquiry.h>

competition_information::competition_information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::competition_information)
{
    ui->setupUi(this);

}


competition_information::~competition_information()
{
    delete ui;
}


void competition_information::on_pushButton_6_clicked()///检索
{
    model = new QSqlTableModel (this);
    model->setTable("project");
    //model->setFilter(QString("id= '%1'").arg(name));
    // model->setSort(0, Qt::DescendingOrder);
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

void competition_information::on_pushButton_5_clicked()///成绩查询
{
    dialog=new score_inquiry(this);
    this->hide();
    dialog->show();
}

void competition_information::on_pushButton_2_clicked()
{
    this->close();
}

void competition_information::on_pushButton_clicked()
{
    dialog=new user_main(this);
    this->hide();
    dialog->show();
}
