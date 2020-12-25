//
// Created by robos on 2020/12/23.
//

#ifndef COURSE_DESIGN_OF_DATA_STRUCTURE_PLACE_G_H
#define COURSE_DESIGN_OF_DATA_STRUCTURE_PLACE_G_H
#include <iostream>
#include <string>
#include <vector>



class Place {
public:
    Place(std::string name, std::string introduction, int num);
    ~Place(){};
    std::string const name() { return name_; };
    std::string const introduction() { return introduction_; };
    int const num() { return num_; };
    void InverseFlag(){flag_ = !flag_;}
    void InitFlag(){flag_ = false;}
    bool const flag(){return flag_;}

private:
    std::string name_;
    std::string introduction_;
    int num_;
    bool flag_ = false;
};


class School {
public:
    School(){}; //  创建一个校园风景区
    ~School(){};
    void Init();
    std::vector<Place> ShortestPath(Place start_point, Place end_point); //
    std::vector<Place> ShortestPath(int num_start_point, int num_end_point);
    void Ppath(std::vector<int> path, int i, int v, std::vector<Place> &vertexe_path);
    //std::string introduction_place(int num)(return vertexes[num].introduction(););
private:
    std::vector<Place>vertexes;//顶点表
    std::vector<std::vector<int>>adjacency_matrix;//邻接矩阵，相当于边表
    int num_vertex = 0; // 顶点数
    int num_edges = 0;  // 边数
};



namespace names_places{
    extern std::string str1 ;//= "西门";
    extern std::string str2 ;//= "学校西门";

    extern std::string str3 ;//= "松苑餐厅";
    extern std::string str4 ;//= "松苑餐厅，二食堂，靠近松苑，杏苑，竹苑";

    extern std::string str5 ;//= "梅苑餐厅";
    extern std::string str6 ;//= "梅苑餐厅，三食堂，靠近竹苑，梅苑，杏苑，兰苑";

    extern std::string str7 ;//= "桃苑餐厅";
    extern std::string str8 ;//="桃苑餐厅，一食堂，靠近松苑，桃苑";

    extern std::string str9 ;//= "图书馆";
    extern std::string str10 ;//= "学校的图书馆";

    extern std::string str11 ;//= "博学楼";
    extern std::string str12 ;//= "即教学楼，学生们上课的地方";

    extern std::string str13 ;//= "鹿苑";
    extern std::string str14 ;//= "可以看到梅花鹿";

    extern std::string str15 ;//= "学院楼";
    extern std::string str16 ;//= "老师们办公，科研，学生做实验的地方";

    extern std::string str17 ;//= "夫子像";
    extern std::string str18 ;//= "孔夫子的雕像";

    extern std::string str19 ;//= "东门";
    extern std::string str20 ;//= "学校东门";
}

#endif// COURSE_DESIGN_OF_DATA_STRUCTURE_PLACE_G_H
