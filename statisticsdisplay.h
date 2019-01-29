#ifndef STATISTICSDISPLAY_H
#define STATISTICSDISPLAY_H

#include <QMainWindow>
#include "observer.h"
#include "displayelement.h"
#include "subject.h"

namespace Ui {
class StatisticsDisplay;
}

class StatisticsDisplay : public QMainWindow, public Observer, DisplayElement
{
    Q_OBJECT

public:
    explicit StatisticsDisplay(Subject * weatherData=nullptr, QWidget *parent = nullptr);
    ~StatisticsDisplay();
    void updateId(int id, int totalIds);
    void update(float temperature, float humidity, float pressure);
    void display();

private slots:
    void on_unsubscribeButton_clicked();

private:
    Ui::StatisticsDisplay *ui;
    float maxTemp = 0.0;
    float minTemp = 200;
    float tempSum = 0.0;
    int numReadings;
    Subject *weatherData;
};

#endif // STATISTICSDISPLAY_H
