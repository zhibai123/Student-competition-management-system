#ifndef APPLY_GAME_H
#define APPLY_GAME_H

#include <QDialog>

namespace Ui {
class apply_game;
}

class apply_game : public QDialog
{
    Q_OBJECT

public:
    explicit apply_game(QWidget *parent = 0);
    ~apply_game();

private:
    Ui::apply_game *ui;
};

#endif // APPLY_GAME_H
