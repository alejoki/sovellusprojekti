#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnShowCars_clicked()
{
    QString site_url="http://localhost:3000/car";
    QNetworkRequest request((site_url));
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getCarSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void MainWindow::getCarSlot (QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString car;
    car = "ID, Branch, Model\r\r";
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        car+=QString::number(json_obj["idcar"].toInt())+", "+json_obj["branch"].toString()+", "+json_obj["model"].toString()+"\r";
    }

    ui->textCars->setText(car);

    reply->deleteLater();
    getManager->deleteLater();
}

void MainWindow::on_btnNewCar_clicked()
{
    QJsonObject jsonObj;
    QString branchString = ui->textBranch->toPlainText();
    QString modelString = ui->textModel->toPlainText();
    jsonObj.insert("branch",branchString);
    jsonObj.insert("model",modelString);

    QString site_url="http://localhost:3000/car";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addCarSlot(QNetworkReply*)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::addCarSlot (QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    postManager->deleteLater();
}

void MainWindow::on_btnDeleteCar_clicked()
{
    QNetworkAccessManager *deleteManager = new QNetworkAccessManager(this);
    QString deleteString = ui->textId->toPlainText();
    QString site_url="http://localhost:3000/car/" + deleteString;
    QNetworkRequest request((site_url));
    reply = deleteManager->deleteResource(request);

}


void MainWindow::on_btnUpdateCar_clicked()
{
    QJsonObject jsonObj;
    QString branchString = ui->textBranch->toPlainText();
    QString modelString = ui->textModel->toPlainText();
    jsonObj.insert("branch",branchString);
    jsonObj.insert("model",modelString);
    QString idString = ui->textId->toPlainText();
    QString site_url="http://localhost:3000/car/" + idString;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    putManager = new QNetworkAccessManager(this);
    connect(putManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(updateCarSlot(QNetworkReply*)));

    reply = putManager->put(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::updateCarSlot (QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    putManager->deleteLater();
}
