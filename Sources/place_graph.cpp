//
// Created by robos on 2020/12/23.
//

#include "../Headers/place_graph.h"

#include <utility>
/*
 * 按照选题要求，创建校园对象
 * 共10个节点
 * 17条边
 */
Place::Place(std::string name, std::string introduction, int num) : name_(std::move(name)),
                                                                    introduction_(std::move(introduction)),
                                                                    num_(num) {}

void School::Init() {
    num_edges = 17;
    num_vertex = 10;
    adjacency_matrix = {
            {0, 1, 5, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
            {1, 0, 3, 7, 5, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
            {5, 3, 0, INT_MAX, 1, 7, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
            {INT_MAX, 7, INT_MAX, 0, 2, INT_MAX, 3, INT_MAX, INT_MAX, INT_MAX},
            {INT_MAX, 5, 1, 2, 0, 3, 6, 9, INT_MAX, INT_MAX},
            {INT_MAX, INT_MAX, 7, INT_MAX, 3, 0, INT_MAX, 5, INT_MAX, INT_MAX},
            {INT_MAX, INT_MAX, INT_MAX, 3, 6, INT_MAX, 0, 2, 7, INT_MAX},
            {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 9, 5, 2, 0, 4, INT_MAX},
            {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 7, 4, 0, 1},
            {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 1, 0}};

    Place west_gate(names_places::str1, names_places::str2, 0);
    vertexes.emplace_back(west_gate);
    Place song_restaurant(names_places::str3, names_places::str4, 1);
    vertexes.emplace_back(song_restaurant);
    Place mei_restaurant(names_places::str5, names_places::str6, 2);
    vertexes.emplace_back(mei_restaurant);
    Place tao_restaurant(names_places::str7, names_places::str8, 3);
    vertexes.emplace_back(tao_restaurant);
    Place library(names_places::str9, names_places::str10, 4);
    vertexes.emplace_back(library);
    Place erudite_building(names_places::str11, names_places::str12, 5);
    vertexes.emplace_back(erudite_building);
    Place deer_park(names_places::str13, names_places::str14, 6);
    vertexes.emplace_back(deer_park);
    Place academy_building(names_places::str15, names_places::str16, 7);
    vertexes.emplace_back(academy_building);
    Place confucius_statue(names_places::str17, names_places::str18, 8);
    vertexes.emplace_back(confucius_statue);
    Place east_gate(names_places::str19, names_places::str20, 9);
    vertexes.emplace_back(east_gate);// 尾部插入
}

std::vector<Place> School::ShortestPath(Place start_point, Place end_point) {// 计算两点的最短路径，采用Dijstra算法
    std::vector<Place> vertexes_s;                                           // 最短路径已经确定的顶点集合
    std::vector<Place> vertexes_u;                                           // 最短路径尚未确定的顶点集合
    std::vector<Place> vertexes_path;

    std::vector<int> distance;
    distance.emplace_back(0);//起点到起点的距离为0

    vertexes_s.emplace_back(start_point);
    vertexes_u = vertexes;
    vertexes_u.erase(vertexes_u.begin() + start_point.num());

    for (int i = 0; i < num_vertex; i++) {
        distance.emplace_back(adjacency_matrix[0][i]);
    }

    vertexes_path.emplace_back(start_point);
    while (vertexes_s.back().num() != end_point.num()) {//遍历到目标顶点时停止遍历
        int num_temp_u = vertexes_u.size();             //未遍历顶点个数
        int num_temp_s = vertexes_s.size();             //已遍历顶点数
        int num_dis_min = 0;                            //下一个最短路径点在vertexes_u中的下标，在下方for循环更新；
        vertexes_path.emplace_back(vertexes_u[0]);

        for (int j = 0; j < num_temp_u; j++) {
            for (int i = 0; i < num_temp_s; i++) {
                int num_temp = distance[i] + adjacency_matrix[i][j];
                if (distance[num_temp_s] < num_temp) {
                    distance[num_temp_s] = num_temp;
                    num_dis_min = j;
                    vertexes_path.pop_back();
                    vertexes_path.emplace_back(vertexes_u[j]);
                }
            }
        }
        vertexes_s.emplace_back(vertexes_u[num_dis_min]);  //添加当前最短路径点
        vertexes_u.erase(vertexes_u.begin() + num_dis_min);//去除当前最短路径点
    }

    return vertexes_path;
}

void School::Ppath(std::vector<int> path, int i, int v, std::vector<Place> &vertexe_path) {

    //std::cout<<"path size is:"<<path.size()<<"  "<<v<<"  "<<path[i]<<std::endl;
    int k;
    //int m = path.size();
    k = path[i];
    //std::cout<<k<<std::endl;
    if (k == v)
        return;
    Ppath(path, k, v, vertexe_path);
    std::cout<<vertexes[k].name()<<std::endl;
    vertexe_path.emplace_back(vertexes[k]);
}

std::vector<Place> School::ShortestPath(int num_start_point, int num_end_point) {
    std::vector<int> distance;
    std::vector<int> path;
    std::vector<Place> vertexes_s;
    distance.reserve(num_vertex);
    path.reserve(num_vertex);

    for (int i = 0; i < num_vertex; i++) {
        distance.emplace_back(adjacency_matrix[num_start_point][i]);
        path.emplace_back(num_start_point);
        vertexes[i].InitFlag();
        //std::cout<<"flag1:"<<vertexes[i].flag()<<std::endl;
    }
    vertexes[num_start_point].InverseFlag();
//    std::cout<<"flag2:"<<vertexes[num_start_point].flag()<<std::endl;
    vertexes_s.emplace_back(vertexes[num_start_point]);

    while (vertexes_s.size() != num_vertex) {
//        std::cout<<"bool flag";
//        for(int i = 0; i <10; i++){
//            std::cout<<vertexes[i].flag();
//        }
//        std::cout<<std::endl;
        int num_min = INT_MAX;
        int flag_min;
        for (int i = 0; i < num_vertex; i++) {
            if ((vertexes[i].flag() == false) &&(num_min > distance[i])) {
                num_min = distance[i];
                flag_min = i;
            }
        }
        vertexes[flag_min].InverseFlag();
        vertexes_s.emplace_back(vertexes[flag_min]);
        //std::cout<<"flag3:"<<flag_min<<"    "<<vertexes[flag_min].flag()<<std::endl;

        for (int i = 0; i < num_vertex; i++) {
            if ((vertexes[i].flag() == false)&& adjacency_matrix[i][flag_min] != INT_MAX &&(distance[i] > distance[flag_min] + adjacency_matrix[i][flag_min])) {
                distance[i] = distance[flag_min] + adjacency_matrix[i][flag_min];
                path[i] = flag_min;
            }
        }
        //std::cout<<"flag4:"<<path[flag_min]<<"  "<<vertexes[path[flag_min]].flag()<<std::endl;
    }

//    std::cout<<"path size is:"<<path.size()<<"num_vertex:"<<num_vertex<<std::endl;
//    int temp = path.size();
//    while(temp--){
//        std::cout<<path[temp];
//    }
//    std::cout<<std::endl;
    std::vector<Place> vertexes_path;
    vertexes_path.emplace_back(vertexes[num_start_point]);
    Ppath(path, num_end_point, num_start_point, vertexes_path);
    vertexes_path.emplace_back(vertexes[num_end_point]);

    return vertexes_path;
}


namespace names_places {
    std::string str1 = "西门";
    std::string str2 = "学校西门";

    std::string str3 = "松苑餐厅";
    std::string str4 = "松苑餐厅，二食堂，靠近松苑，杏苑，竹苑";

    std::string str5 = "梅苑餐厅";
    std::string str6 = "梅苑餐厅，三食堂，靠近竹苑，梅苑，杏苑，兰苑";

    std::string str7 = "桃苑餐厅";
    std::string str8 = "桃苑餐厅，一食堂，靠近松苑，桃苑";

    std::string str9 = "图书馆";
    std::string str10 = "学校的图书馆";

    std::string str11 = "博学楼";
    std::string str12 = "即教学楼，学生们上课的地方";

    std::string str13 = "鹿苑";
    std::string str14 = "可以看到梅花鹿";

    std::string str15 = "学院楼";
    std::string str16 = "老师们办公，科研，学生做实验的地方";

    std::string str17 = "夫子像";
    std::string str18 = "孔夫子的雕像";

    std::string str19 = "东门";
    std::string str20 = "学校东门";
}// namespace names_places