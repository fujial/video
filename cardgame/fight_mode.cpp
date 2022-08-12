#include "fight_mode.h"

fight_mode::fight_mode(QObject *parent) : QObject(parent)
{

}

fight_mode_standard::fight_mode_standard():roomid(0),playerid(0),enemyid(0)
{

}

fight_mode_standard::~fight_mode_standard()
{

}
