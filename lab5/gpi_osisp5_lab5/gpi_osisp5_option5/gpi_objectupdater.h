#ifndef GPI_OBJECTUPDATER_H
#define GPI_OBJECTUPDATER_H

#include <QObject>
#include <QNetworkReply>

//QT_BEGIN_NAMESPACE
//namespace Ui { class gpi_MainWindow; }
//QT_END_NAMESPACE

class gpi_ObjectUpdater : public QObject
{
    Q_OBJECT

public:
    explicit gpi_ObjectUpdater(QObject *parent = nullptr);
    void gpi_update();
    QNetworkAccessManager *networkManager;

public slots:
    void onResult(QNetworkReply *reply);

private:
  //  Ui::gpi_MainWindow *ui;
};

#endif // GPI_OBJECTUPDATER_H
