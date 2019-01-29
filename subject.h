#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"

class Subject
{
public:
    Subject();
    virtual ~Subject();
    virtual void registerObserver(Observer *o)=0;
    virtual void removeObserver(Observer *o)=0;
    virtual void notifyObservers()=0;
};

#endif // SUBJECT_H
