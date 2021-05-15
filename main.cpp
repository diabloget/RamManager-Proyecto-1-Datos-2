#include <QApplication>
#include <QPushButton>
#include "RamClient.h"
#include "Memory.h"

/**
 * @file main.cpp
 * @authors Diabloget, Jjvv21
 */

int main(int argc, char *argv[]) {
    RamClient* ramsito = RamClient().GetInstance();
    ramsito->initReader();

    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
