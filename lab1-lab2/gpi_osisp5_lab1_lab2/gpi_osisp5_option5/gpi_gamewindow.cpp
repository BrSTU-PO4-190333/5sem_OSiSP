#include "gpi_gamewindow.hpp"
#include "ui_gpi_gamewindow.h"

gpi_GameWindow::gpi_GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gpi_GameWindow)
{
    ui->setupUi(this);
}

gpi_GameWindow::~gpi_GameWindow()
{
    delete ui;
}
