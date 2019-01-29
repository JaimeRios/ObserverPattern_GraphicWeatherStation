#include "forecastdisplay.h"
#include "ui_forecastdisplay.h"

ForecastDisplay::ForecastDisplay(Subject * weatherData, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ForecastDisplay)
{
    ui->setupUi(this);
    this->weatherData = weatherData;
    this->weatherData->registerObserver(this);
}

ForecastDisplay::~ForecastDisplay()
{
    delete ui;
}

void ForecastDisplay::updateId(int id, int totalIds)
{
    ui->labelId->setText(QString("Observer # %1/%2").arg(id).arg(totalIds));
}

void ForecastDisplay::update(float temperature, float humidity, float pressure)
{
    this->temperature = temperature;
    this->humidity = humidity;
    lastPressure = currentPressure;
    currentPressure = pressure;
    display();
}

void ForecastDisplay::display()
{
    QString message;
    if(currentPressure > lastPressure)
        message= "Improving weather on the way!";
    else if(currentPressure == lastPressure)
        message= "More of the same";
    else
        message= "Watchout for cooler, rainy weather!";

    ui->messageLabel->setText(message);
}

void ForecastDisplay::on_unsubscribeButton_clicked()
{
    Observer *current = this;
    this->weatherData->removeObserver(current);
}
