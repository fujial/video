#include "ccontrol.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CControl* my_control = CControl::createControl();
//    Login_Dialog w;
//    w.show();
    return a.exec();
}
