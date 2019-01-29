#ifndef CURRENTCONDITIONSDISPLAY_H
#define CURRENTCONDITIONSDISPLAY_H

#include <QMainWindow>
#include "observer.h"
#include "subject.h"
#include "displayelement.h"

namespace Ui {
class CurrentConditionsDisplay;
}

class CurrentConditionsDisplay : public QMainWindow, public Observer, public DisplayElement
{
    Q_OBJECT

public:
    explicit CurrentConditionsDisplay(Subject * weatherData=nullptr, QWidget *parent = nullptr);
    ~CurrentConditionsDisplay();
    void update(float temperature, float humidity, float pressure);
    void display();

private:
    Ui::CurrentConditionsDisplay *ui;
    float temperature;
    float humidity;
    Subject *weatherData;
};

#endif // CURRENTCONDITIONSDISPLAY_H
