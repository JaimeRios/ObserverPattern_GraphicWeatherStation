#include "currentconditionsdisplay.h"
#include "ui_currentconditionsdisplay.h"
#include <cmath>


CurrentConditionsDisplay::CurrentConditionsDisplay(Subject * weatherData, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CurrentConditionsDisplay)
{
    ui->setupUi(this);
    this->weatherData = weatherData;
    this->weatherData->registerObserver(this);
}

CurrentConditionsDisplay::~CurrentConditionsDisplay()
{
    delete ui;
}

void CurrentConditionsDisplay::update(float temperature, float humidity, float pressure)
{
    this->temperature = temperature;
    this->humidity = humidity;
    display();
}

void CurrentConditionsDisplay::display()
{
    double value;
    ui->lcdTemperatureDisplay->display(temperature);
    ui->lcdTemperatureDecimalDisplay->display(modf(temperature,&value)*100);
    ui->lcdHumidityDisplay->display(humidity);
}
