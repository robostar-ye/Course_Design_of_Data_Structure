//
// Created by robos on 2020/12/23.
//

#include "../Headers/main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow) {
    CUMT = School();
    CUMT.Init();
    //  std::vector<Place> vec_temp= CUMT.ShortestPath(0,9);
    //  int num_temp = vec_temp.size();
    //  for(int i = 0; i < num_temp; i++){
    //      std::cout<<vec_temp[i].name()<<vec_temp[i].num()<<" "<<std::endl;
    //  }

    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_button_west_gate_clicked() {
    msg_intro.setText("学校的西门");
    msg_intro.exec();
}


void MainWindow::on_button_min_path_clicked() {
    int num_start_point = ui->lineEdit_num_start_point->text().toInt() - 1;
    int num_end_point = ui->lineEdit_num_end_point->text().toInt() - 1;

    if (!ui->lineEdit_num_start_point->text().isEmpty() && !ui->lineEdit_num_end_point->text().isEmpty() && num_start_point >= 0 && num_start_point <= 9 && num_end_point >= 0 && num_end_point <= 9) {
        std::vector<Place> result_temp = CUMT.ShortestPath(num_start_point, num_end_point);
        QString result_qstring;
        std::string result_string;
        int num_temp = result_temp.size();
        for (int i = 0; i < num_temp; i++) {
            result_string += result_temp[i].name();
            if (i != num_temp - 1) result_string += "->";
        }

        result_qstring = QString::fromStdString(result_string);

        ui->textBrowser_result_min_path->clear();
        ui->textBrowser_result_min_path->append(result_qstring);
    } else {
        msg_intro.setText("输入非法，请重新输入");
        msg_intro.exec();
    }

    //ui->textBrowser_result_min_path = ;
}

void MainWindow::on_button_song_restaurant_clicked() {
    msg_intro.setText("松苑餐厅，二食堂，靠近松苑，杏苑，竹苑");
    msg_intro.exec();
}

void MainWindow::on_button_mei_restaurant_clicked() {
    msg_intro.setText("梅苑餐厅，三食堂，靠近竹苑，梅苑，杏苑，兰苑");
    msg_intro.exec();
}

void MainWindow::on_button_tao_restaurant_clicked() {
    msg_intro.setText("桃苑餐厅，一食堂，靠近松苑，桃苑");
    msg_intro.exec();
}

void MainWindow::on_button_library_clicked() {
    msg_intro.setText("学校的图书馆");
    msg_intro.exec();
}

void MainWindow::on_button_teching_building_clicked() {
    msg_intro.setText("即教学楼，学生们上课的地方");
    msg_intro.exec();
}

void MainWindow::on_button_deer_park_clicked() {
    msg_intro.setText("可以看到梅花鹿");
    msg_intro.exec();
}

void MainWindow::on_button_academy_building_clicked() {
    msg_intro.setText("老师们办公，科研，学生做实验的地方");
    msg_intro.exec();
}

void MainWindow::on_button_confucius_statue_clicked() {
    msg_intro.setText("孔夫子的雕像");
    msg_intro.exec();
}

void MainWindow::on_button_east_gate_clicked() {
    msg_intro.setText("学校东门");
    msg_intro.exec();
}
