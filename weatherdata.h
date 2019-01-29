#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QMainWindow>
#include "subject.h"
#include "observer.h"
#include <QList>

namespace Ui {
class WeatherData;
}

class WeatherData : public QMainWindow, public Subject
{
    Q_OBJECT

public:
    explicit WeatherData(QWidget *parent = nullptr);
    ~WeatherData();
    void registerObserver(Observer *o);
    void removeObserver(Observer *o);
    void notifyObservers();
    void notifyObserversIds();
    void measurementsChanged();
    void setMeasurements(float temperature, float humidity, float pressure);

private slots:
    void on_updateValues_clicked();

private:
    Ui::WeatherData *ui;
    QList<Observer *> observers;
    float temperature;
    float humidity;
    float pressure;
};

#endif // WEATHERDATA_H
