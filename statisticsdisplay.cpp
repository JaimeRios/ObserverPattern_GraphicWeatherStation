#include "statisticsdisplay.h"
#include "ui_statisticsdisplay.h"
#include <cmath>

StatisticsDisplay::StatisticsDisplay(Subject * weatherData, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StatisticsDisplay)
{
    ui->setupUi(this);
    this->weatherData = weatherData;
    this->weatherData->registerObserver(this);
}

StatisticsDisplay::~StatisticsDisplay()
{
    delete ui;
}

void StatisticsDisplay::update(float temperature, float humidity, float pressure)
{
    tempSum += temperature;
    numReadings++;

    if(temperature > maxTemp)
        maxTemp = temperature;

    if(temperature < minTemp)
        minTemp = temperature;

    display();
}

void StatisticsDisplay::display()
{
    double value;
    ui->lcdAverageDisplay->display((tempSum/numReadings));
    ui->lcdAverageDecimalDisplay->display(modf((tempSum/numReadings),&value)*100);
    ui->lcdMaxDisplay->display(maxTemp);
    ui->lcdMaxDecimalDisplay->display(modf(maxTemp,&value)*100);
    ui->lcdMinDisplay->display(minTemp);
    ui->lcdMinDecimalDisplay->display(modf(minTemp,&value)*100);
}
