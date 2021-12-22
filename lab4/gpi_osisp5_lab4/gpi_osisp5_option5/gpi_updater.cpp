#include "gpi_mainwindow.hpp"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>

void gpi_MainWindow::on_gpi_pushButton_update_clicked()
{
    qDebug() << "on_gpi_pushButton_update_clicked()";
    QMessageBox::information(this, "Процесс обновления", "Происходит запрос на сервер");
    networkManager = new QNetworkAccessManager();

    // Подключаем networkManager к обработчику ответа
    connect(networkManager, &QNetworkAccessManager::finished, this, &gpi_MainWindow::onResult);

    // Получаем данные, а именно JSON файл с сайта по определённому url
    networkManager->get(QNetworkRequest(QUrl("http://localhost:3002/versions")));
}

void gpi_MainWindow::onResult(QNetworkReply *reply)
{
    qDebug() << "onResult(QNetworkReply *reply)";

    QMessageBox::information(this, "Процесс обновления", "Происходит сверка версий");

    if (reply->error())
    {
        QMessageBox::critical(this, "Проблема со сервером", "Ошибка подключения к серверу");
    }

    // Если ошибки отсутсвуют
    if(!reply->error())
    {
        QString client_helper = "2.0.0";
        QString client_helper_class = "1.0.0";
        QString client_about = "1.0.0";

        QString server_helper = "";
        QString server_helper_class = "";
        QString server_about = "";

        // То создаём объект Json Document, считав в него все данные из ответа
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        QJsonObject json = document.object();
        qDebug() << "document:" << document;
        qDebug() << "json:" << json;

        server_helper = json.value("helper").toString();
        server_helper_class = json.value("helper_class").toString();
        server_about = json.value("about").toString();

        QString gpi_str_verions
            = client_helper + " ~ " + server_helper + " - helper.dll \n"
            + client_helper_class + " ~ " + server_helper_class + " - helper_class.dll \n"
            + client_about + " ~ " + server_about  + " - about.dll \n";

        QMessageBox::information(this, "Процесс обновления", gpi_str_verions);

        if (client_helper.compare(server_helper)) {
            QMessageBox::information(this, "Процесс обновления", "Найдено обновление helper.dll");
        }

        if (client_helper_class.compare(server_helper_class)) {
            QMessageBox::information(this, "Процесс обновления", "Найдено обновление helper_class.dll");
        }

        if (client_about.compare(server_about)) {
            QMessageBox::information(this, "Процесс обновления", "Найдено обновление about.dll");
        }

    }
    reply->deleteLater();
}
