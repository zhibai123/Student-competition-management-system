#include "teacher_main.h"
#include "ui_teacher_main.h"

teacher_main::teacher_main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacher_main)
{
    ui->setupUi(this);
}

teacher_main::~teacher_main()
{
    delete ui;
}

void teacher_main::on_pushButton_5_clicked()///科目成绩查询
{
    this->hide();
    sia->show();
    sia->exec();
}

void teacher_main::on_pushButton_4_clicked()///竞赛信息
{
    this->hide();
    cit->show();
    cit->exec();
}

void teacher_main::on_pushButton_6_clicked()///竞赛信息发布
{
    this->hide();
    cir->show();
    cir->exec();
}

void teacher_main::on_pushButton_2_clicked()
{
    this->close();
}


void teacher_main::on_pushButton_7_clicked()///竞赛报名信息查询
{
    QString name=ui->lineEdit->text();
    model = new QSqlTableModel (this);
    model->setTable("student_registration");
    model->setFilter(QString("pr_name= '%1'").arg(name));
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("学号"));
    model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
    model->setHeaderData(4, Qt::Horizontal, tr("电话"));
    ui->tableView->setModel(model);
    ui->tableView->hideColumn(2);
    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
}
