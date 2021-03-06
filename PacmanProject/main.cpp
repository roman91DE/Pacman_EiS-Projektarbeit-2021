#include "mainmenu.h"
#include <QApplication>

// with main menu
// --------------
int main(int argc, char *argv[])
{
    srand((time(NULL)));
    QApplication a(argc, argv);
    mainMenu w;
    w.show();
    return a.exec();
}



// skip main menu - directly load level 1
//// ---------------
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    gameWindow w("/txt_maps/level1.txt");
//    w.show();
//    return a.exec();
//}

