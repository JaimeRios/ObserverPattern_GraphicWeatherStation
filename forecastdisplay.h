#ifndef FORECASTDISPLAY_H
#define FORECASTDISPLAY_H

#include <QMainWindow>
#include "observer.h"
#include "displayelement.h"
#include "subject.h"

namespace Ui {
class ForecastDisplay;
}

class ForecastDisplay : public QMainWindow, public Observer, public DisplayElement
{
    Q_OBJECT

public:
    explicit ForecastDisplay(Subject * weatherData=nullptr, QWidget *parent = nullptr);
    ~ForecastDisplay();
    void updateId(int id, int totalIds);
    void update(float temperature, float humidity, float pressure);
    void display();

private slots:
    void on_unsubscribeButton_clicked();

private:
    Ui::ForecastDisplay *ui;
    float temperature;
    float humidity;
    float lastPressure;
    float currentPressure = 29.92f;
    Subject *weatherData;
};

#endif // FORECASTDISPLAY_H
