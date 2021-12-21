#ifndef GPI_GAMEWINDOW_HPP
#define GPI_GAMEWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class gpi_GameWindow;
}

class gpi_GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit gpi_GameWindow(QWidget *parent = nullptr);
    ~gpi_GameWindow();

private:
    Ui::gpi_GameWindow *ui;
};

#endif // GPI_GAMEWINDOW_HPP
