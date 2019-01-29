#include "weatherdata.h"
#include "ui_weatherdata.h"
#include <iostream>


WeatherData::WeatherData(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WeatherData)
{
    ui->setupUi(this);
}

WeatherData::~WeatherData()
{
    delete ui;
}

void WeatherData::registerObserver(Observer *o)
{
    observers.push_back(o);
    this->notifyObserversIds();
}

void WeatherData::removeObserver(Observer *o)
{
    observers.removeOne(o);
    this->notifyObserversIds();
    std::cout<<"remove called"<<std::endl;
}

void WeatherData::notifyObservers()
{
    QList<Observer *>::Iterator it;

    for(it = observers.begin(); it != observers.end(); ++it)
    {
        Observer *observer = (*it);
        observer->update(temperature, humidity, pressure);
    }
}

void WeatherData::notifyObserversIds()
{
    QList<Observer *>::Iterator it;
    int currentId=1;
    int totalIds= observers.length();

    for(it = observers.begin(); it != observers.end(); ++it)
    {
        Observer *observer = (*it);
        observer->updateId(currentId,totalIds);
        currentId++;
    }
}

void WeatherData::measurementsChanged()
{
    notifyObservers();
}

void WeatherData::setMeasurements(float temperature, float humidity, float pressure)
{
    this->temperature = temperature;
    this->humidity = humidity;
    this->pressure = pressure;
    measurementsChanged();
}

void WeatherData::on_updateValues_clicked()
{
    this->temperature = ui->temperatureDoubleSpinBox->value();
    this->humidity = ui->humidityDoubleSpinBox->value();
    this->pressure = ui->pressureDoubleSpinBox->value();
    measurementsChanged();
}
