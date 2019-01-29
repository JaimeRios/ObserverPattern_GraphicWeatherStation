#ifndef HEATINDEXDISPLAY_H
#define HEATINDEXDISPLAY_H

#include <QMainWindow>
#include "observer.h"
#include "displayelement.h"
#include "subject.h"

namespace Ui {
class HeatIndexDisplay;
}

class HeatIndexDisplay : public QMainWindow, public Observer, DisplayElement
{
    Q_OBJECT

public:
    explicit HeatIndexDisplay(Subject * weatherData=nullptr, QWidget *parent = nullptr);
    ~HeatIndexDisplay();
    float computeHeatIndex(float t, float rh);
    void update(float temperature, float humidity, float pressure);
    void display();

private:
    Ui::HeatIndexDisplay *ui;
    float temperature;
    float humidity;
    float pressure;
    float heatIndex = 0.0;
    Subject *weatherData;
};

#endif // HEATINDEXDISPLAY_H
