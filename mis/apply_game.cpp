#include "apply_game.h"
#include "ui_apply_game.h"

apply_game::apply_game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::apply_game)
{
    ui->setupUi(this);
}

apply_game::~apply_game()
{
    delete ui;
}
