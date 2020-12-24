//
// Created by robos on 2020/12/23.
//

#include <QApplication>
#include "../Headers/main_window.h"
#include "../Headers/place_graph.h"

int main(int argc, char *argv[]) {
    School CUMT;
    CUMT.Init();
    std::vector<Place> vec_temp= CUMT.ShortestPath(0,9);
    int num_temp = vec_temp.size();
    for(int i = 0; i < num_temp; i++){
        std::cout<<vec_temp[i].name()<<vec_temp[i].num()<<" "<<std::endl;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
