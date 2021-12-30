#include "gpi_thread_updater.hpp"

#include <QDebug>

gpi_thread_updater::gpi_thread_updater(QString threadName) :
    name(threadName)
{

}

void gpi_thread_updater::run()
{
    for (int i = 0; i <= 100; i++ ) {
        qDebug() << name << " " << i;
    }
}
