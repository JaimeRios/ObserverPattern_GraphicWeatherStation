#ifndef DISPLAYELEMENT_H
#define DISPLAYELEMENT_H


class DisplayElement
{
public:
    DisplayElement();
    virtual ~DisplayElement();
    virtual void display()=0;
};

#endif // DISPLAYELEMENT_H
