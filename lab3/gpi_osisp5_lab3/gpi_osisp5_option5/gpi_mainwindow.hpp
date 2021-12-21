#ifndef GPI_MAINWINDOW_HPP
#define GPI_MAINWINDOW_HPP

#include <QMainWindow>
#include <QMessageBox>
#include <QLibrary>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class gpi_MainWindow; }
QT_END_NAMESPACE

class gpi_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    gpi_MainWindow(QWidget *parent = nullptr);
    ~gpi_MainWindow();

private slots:
    void on_gpi_pushButton_start_clicked();
    void on_gpi_pushButton_close_clicked();
    void gpi_on_gpi_action_about_triggered();

private:
    Ui::gpi_MainWindow *ui;
};
#endif // GPI_MAINWINDOW_HPP
