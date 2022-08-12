#include "room_dialog.h"
#include "game_control.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game_Control* my_control = game_Control::create_game_Control();

    return a.exec();
}
