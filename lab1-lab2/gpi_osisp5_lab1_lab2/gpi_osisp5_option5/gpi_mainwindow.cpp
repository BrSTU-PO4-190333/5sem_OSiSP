#include "gpi_mainwindow.hpp"
#include "gpi_gamewindow.hpp"
#include "ui_gpi_mainwindow.h"

gpi_MainWindow::gpi_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gpi_MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon (QIcon (":/@/_assets/gpi_favicon.png"));
}

gpi_MainWindow::~gpi_MainWindow()
{
    delete ui;
}

// gpi_ Функция, которая открывает окно с игрой (GameWindow)
void gpi_MainWindow::on_gpi_pushButton_start_clicked()
{
gpi_GameWindow* gpi_gw;
// = = = = = = = = = = = = = = = =
    gpi_gw = new gpi_GameWindow(this);  // gpi_ Создаем объект окна
    gpi_gw->show();                     // gpi_ Делаем окно видимым
}

// gpi_ Функция, которая закрывает окно меню (MainWindow)
void gpi_MainWindow::on_gpi_pushButton_close_clicked()
{
    this->close();                      // gpi_ Закрытия окна
}
