//
// Created by robos on 2020/12/23.
//

#include <QApplication>
#include "../Headers/main_window.h"
#include "../Headers/place_graph.h"

int main(int argc, char *argv[]) {
    //gui
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("校园风景自助查询平台");
    w.show();
    return a.exec();
}
