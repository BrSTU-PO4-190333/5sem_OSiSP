#include "gpi_thread_updater.hpp"
#include "gpi_objectupdater.h"

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
    gpi_ObjectUpdater* gpi_ou = new gpi_ObjectUpdater();
    //gpi_ou->gpi_update();
}
