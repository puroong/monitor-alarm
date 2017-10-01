#ifndef FREQUENTALARM_H
#define FREQUENTALARM_H

#include "common.h"
#include "alarm.h"

class FrequentAlarm : public Alarm
{
public:
    FrequentAlarm(QTime time, int frequentPeriod);
    ~FrequentAlarm();
    int generateRandomSec();
public slots:
    void ring() override;
    void addFrequentAlarm(QTime time);
private:
    QTime time;
    int frequentPeriod;
};

#endif // FREQUENTALARM_H
