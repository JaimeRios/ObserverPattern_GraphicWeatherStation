#include "weatherdata.h"
#include "currentconditionsdisplay.h"
#include "forecastdisplay.h"
#include "statisticsdisplay.h"
#include "heatindexdisplay.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WeatherData *weatherData = new WeatherData;
    weatherData->show();


    CurrentConditionsDisplay currentConditionDisplay(weatherData);
    currentConditionDisplay.show();
    ForecastDisplay forecastDisplay(weatherData);
    forecastDisplay.show();
    StatisticsDisplay statisticsDisplay(weatherData);
    statisticsDisplay.show();
    HeatIndexDisplay heatIndexDisplay(weatherData);
    heatIndexDisplay.show();



    return a.exec();
}
