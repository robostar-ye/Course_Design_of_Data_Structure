//
// Created by robos on 2020/12/23.
//

#ifndef COURSE_DESIGN_OF_DATA_STRUCTURE_MAINWINDOW_H
#define COURSE_DESIGN_OF_DATA_STRUCTURE_MAINWINDOW_H
#include <QMainWindow>
#include "../Sources/ui_mainwindow.h"
#include "place_graph.h"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_button_west_gate_clicked();


    void on_button_min_path_clicked();

    void on_button_song_restaurant_clicked();

    void on_button_mei_restaurant_clicked();

    void on_button_tao_restaurant_clicked();

    void on_button_library_clicked();

    void on_button_teching_building_clicked();

    void on_button_deer_park_clicked();

    void on_button_academy_building_clicked();

    void on_button_confucius_statue_clicked();

    void on_button_east_gate_clicked();

private:
    QAction *openAction;
    Ui::MainWindow *ui;
    School CUMT;
    QMessageBox msg_intro;
};
#endif// COURSE_DESIGN_OF_DATA_STRUCTURE_MAINWINDOW_H
