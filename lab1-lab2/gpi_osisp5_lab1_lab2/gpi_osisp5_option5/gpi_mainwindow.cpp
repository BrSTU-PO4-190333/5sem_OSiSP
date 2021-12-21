#include "gpi_mainwindow.hpp"
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

