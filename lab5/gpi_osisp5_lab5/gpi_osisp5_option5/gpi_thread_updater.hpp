#ifndef GPI_THREAD_UPDATER_HPP
#define GPI_THREAD_UPDATER_HPP

#include <QObject>
#include <QThread>

class gpi_thread_updater : public QThread
{
public:
    gpi_thread_updater(QString threadName);
    void run();
private:
    QString name;
};

#endif // GPI_THREAD_UPDATER_HPP
