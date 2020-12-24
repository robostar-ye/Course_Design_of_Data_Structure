//
// Created by robos on 2020/12/23.
//

#ifndef COURSE_DESIGN_OF_DATA_STRUCTURE_MAINWINDOW_H
#define COURSE_DESIGN_OF_DATA_STRUCTURE_MAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
};
#endif // COURSE_DESIGN_OF_DATA_STRUCTURE_MAINWINDOW_H
