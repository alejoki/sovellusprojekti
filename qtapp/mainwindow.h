#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "car.h"
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *getManager;
    QNetworkAccessManager *postManager;
    QNetworkAccessManager *putManager;
    QNetworkReply *reply;
    QByteArray response_data;


private slots:
    void getCarSlot (QNetworkReply *reply);
    void on_btnShowCars_clicked();
    void addCarSlot (QNetworkReply *reply);
    void on_btnNewCar_clicked();
    void on_btnDeleteCar_clicked();
    void updateCarSlot (QNetworkReply *reply);
    void on_btnUpdateCar_clicked();
};
#endif // MAINWINDOW_H
