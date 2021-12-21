#ifndef GPI_GAMEWINDOW_HPP
#define GPI_GAMEWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class gpi_GameWindow;
}

enum gpi_fields{
    gpi_err,
    gpi_wall,
    gpi_floor,
    gpi_player,
    gpi_finPlayer,
    gpi_box,
    gpi_finBox,
    gpi_finish,
};

class gpi_GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit gpi_GameWindow(QWidget *parent = nullptr);
    ~gpi_GameWindow();

private:
    Ui::gpi_GameWindow *ui;
    QPainter* gpi_painter;
    QVector <QVector<gpi_fields>> gpi_map;
    void gpi_generate(QStringList gpi_str_map);
    int gpi_xPlayer;
    int gpi_yPlayer;
    int gpi_mapHeight;
    int gpi_mapWidth;
};

QStringList gpi_get_1_level();

#endif // GPI_GAMEWINDOW_HPP
