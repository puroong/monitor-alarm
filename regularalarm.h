#ifndef REGULARALARM_H
#define REGULARALARM_H

#include "alarm.h"

class RegularAlarm : public Alarm
{
public:
    RegularAlarm(QTime startTime, QTime endTime, int period);
    ~RegularAlarm();
public slots:
    void ring() override;
private:
    QTime startTime;
    QTime endTime;
    int period;
};

#endif // REGULARALARM_H
