#include "gpi_gamewindow.hpp"
#include "ui_gpi_gamewindow.h"

gpi_GameWindow::gpi_GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gpi_GameWindow)
{
QTimer* gpi_timer;
// = = = = = = = = = = = = = = = =
    ui->setupUi(this);

    // gpi_ Устанавливаю таймер
    gpi_timer = new QTimer(this);
    connect (gpi_timer, SIGNAL(timeout()), this, SLOT(gpi_animate()));
    gpi_timer->start(100);

    //
    connect(
        ui->gpi_action_align,
        SIGNAL(triggered()),
        this,
        SLOT(gpi_on_gpi_action_align_triggered())
    );

    gpi_generate(gpi_get_1_level());
    gpi_on_gpi_action_align_triggered();
}

gpi_GameWindow::~gpi_GameWindow()
{
    delete ui;
}

// gpi_ Функция, которая возвращает текстовый первый уровень
QStringList gpi_get_1_level()
{
QStringList gpi_str_map;
// = = = = = = = = = = = = = = = =
    gpi_str_map = {
        "xxxxxxxxxxxxxxx",
        "xxxxxxxxxxxxxxx",
        "xxxxxxxxxxxxxxx",
        "xxxxxxxxxxxxxxx",
        "xxxxxx...xxxxxx",
        "xxxxf@b..xxxxxx",
        "xxxxxx.bfxxxxxx",
        "xxxxfxxb.xxxxxx",
        "xxxx.x.f.xxxxxx",
        "xxxxb.Bbbfxxxxx",
        "xxxx...f..xxxxx",
        "xxxxxxxxxxxxxxx",
        "xxxxxxxxxxxxxxx",
        "xxxxxxxxxxxxxxx",
        "xxxxxxxxxxxxxxx"
    };
    return gpi_str_map;
}

// gpi_ Функция, которая генерирует уровень
void gpi_GameWindow::gpi_generate(QStringList gpi_str_map)
{
int gpi_i;
int gpi_j;
int gpi_max_width;
// = = = = = = = = = = = = = = = = =

    // gpi_ Определяет высоту карты
    this->gpi_mapHeight = gpi_str_map.length();
    qDebug() << "gpi_mapHeight: " << this->gpi_mapHeight;

    // gpi_ Определяем ширину карты
    gpi_max_width = 0;
    for (gpi_i = 0; gpi_i < gpi_str_map.length(); ++gpi_i)
    {
        if (gpi_max_width < gpi_str_map[gpi_i].length())
        {
            gpi_max_width = gpi_str_map[gpi_i].length();
        }
    }
    this->gpi_mapWidth = gpi_max_width;
    qDebug() << "gpi_mapWidth: " << this->gpi_mapWidth;

    // gpi_ Заполняем карту
    for (gpi_i = 0; gpi_i < this->gpi_mapHeight; ++gpi_i)
    {
        QVector<gpi_fields> gpi_1d_arr;
        for (gpi_j = 0; gpi_j < this->gpi_mapWidth; ++gpi_j)
        {
            gpi_1d_arr.push_back(gpi_err);
        }

        this->gpi_map.push_back(gpi_1d_arr);
    }

    // gpi_ Проходимся по массиву строк
    for (gpi_i = 0; gpi_i < this->gpi_mapHeight; ++gpi_i)
    {
        // gpi_ Проходимся по строке
        for (gpi_j = 0; gpi_j < this->gpi_mapWidth; ++gpi_j)
        {
            // gpi_ Если это пол
            if (gpi_str_map[gpi_i][gpi_j] == '.')
            {
                this->gpi_map[gpi_i][gpi_j] = gpi_floor;
                continue;
            }

            // gpi_ Если это стена
            if (gpi_str_map[gpi_i][gpi_j] == 'x')
            {
                this->gpi_map[gpi_i][gpi_j] = gpi_wall;
                continue;
            }

            // gpi_ Если это игрок
            if (gpi_str_map[gpi_i][gpi_j] == '@')
            {
                this->gpi_map[gpi_i][gpi_j] = gpi_player;
                this->gpi_xPlayer = gpi_i;
                this->gpi_yPlayer = gpi_j;
                continue;
            }

            // gpi_ Если это финиш
            if (gpi_str_map[gpi_i][gpi_j] == 'f')
            {
                this->gpi_map[gpi_i][gpi_j] = gpi_finish;
                continue;
            }

            // gpi_ Если это игрок на финише
            if (gpi_str_map[gpi_i][gpi_j] == 'A')
            {
                this->gpi_map[gpi_i][gpi_j] = gpi_finPlayer;
                this->gpi_xPlayer = gpi_i;
                this->gpi_yPlayer = gpi_j;
                continue;
            }

            // gpi_ Если это коробка
            if (gpi_str_map[gpi_i][gpi_j] == 'b')
            {
                this->gpi_map[gpi_i][gpi_j] = gpi_box;
                continue;
            }

            // gpi_ Если это коробка на финише
            if (gpi_str_map[gpi_i][gpi_j] == 'B')
            {
                this->gpi_map[gpi_i][gpi_j] = gpi_finBox;
                continue;
            }
        }
        qDebug() << gpi_i << gpi_str_map[gpi_i];
    }

    qDebug() << this->gpi_map;
}

// gpi_ Функция, которая перерисовывает окно
void gpi_GameWindow::gpi_animate()
{
    repaint();
}

// gpi_ Функция перерисовки окна
void gpi_GameWindow::paintEvent(QPaintEvent *event)
{
int gpi_i;
int gpi_j;
int gpi_xk;
int gpi_yk;
QString gpi_img_path;
// = = = = = = = = = = = = = = = = =
    // gpi_ Убираем предупреждение Qt о не использовании перемменной
    Q_UNUSED (event);

    QPainter gpi_painter(this);

    // gpi_ Определяем коэффициенты расшерения ячеек массива
    gpi_yk = this->height() / this->gpi_mapHeight;
    gpi_xk = this->width() / this->gpi_mapWidth;

    for (gpi_i = 0; gpi_i < this->gpi_mapHeight; ++ gpi_i)
    {
        for (gpi_j = 0; gpi_j < this->gpi_mapWidth; ++gpi_j)
        {
            gpi_img_path = get_image_path(this->gpi_map[gpi_i][gpi_j]);
            QPixmap gpi_pixmap(gpi_img_path);
            gpi_painter.drawPixmap(gpi_xk * gpi_i, gpi_yk * gpi_j, gpi_xk, gpi_yk, gpi_pixmap);
        }
    }
}

// gpi_ Функция для определение пути к картинке
QString get_image_path(gpi_fields gpi_f)
{
    // gpi_ Если это пол
    if (gpi_f == gpi_floor)
    {
        return ":/@/_assets/gpi_GameWindow__floor.png";
    }

    // gpi_ Если это стена
    if (gpi_f == gpi_wall)
    {
        return ":/@/_assets/gpi_GameWindow__wall.png";
    }

    // gpi_ Если это игрок
    if (gpi_f == gpi_player)
    {
        return ":/@/_assets/gpi_GameWindow__player.png";
    }

    // gpi_ Если это финиш
    if (gpi_f == gpi_finish)
    {
        return ":/@/_assets/gpi_GameWindow__finish.png";
    }

    // gpi_ Если это игрок на финише
    if (gpi_f == gpi_finPlayer)
    {
        return ":/@/_assets/gpi_GameWindow__finPlayer.png";
    }

    // gpi_ Если это коробка
    if (gpi_f == gpi_box)
    {
        return ":/@/_assets/gpi_GameWindow__box.png";
    }

    // gpi_ Если это коробка на финише
    if (gpi_f == gpi_finBox)
    {
        return ":/@/_assets/gpi_GameWindow__finBox.png";
    }

    return ":/@/_assets/gpi_GameWindow__err.png";
}

// gpi_ Функция для выравнивания окна
void gpi_GameWindow::gpi_on_gpi_action_align_triggered()
{
    this->resize(this->gpi_mapHeight * 32, this->gpi_mapWidth * 32);
}
