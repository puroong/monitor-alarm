#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "common.h"
#include <QObject>
#include "alarmlist.h"
#include "regularalarm.h"
#include "frequentalarm.h"

class Scheduler : public QObject
{
    Q_OBJECT
public:
    explicit Scheduler(QObject *parent = nullptr);
    explicit Scheduler(QTime startTime, QTime endTime, int period, int frequentPeriod, QObject *parent = nullptr);
    ~Scheduler();
    void run();
signals:
    void ringFrequentAlarm();
    void ringRegularAlarm();
public slots:
    void checkAlarm();
private:
    RegularAlarm* rAlarm;
    FrequentAlarm* fAlarm;
    QTimer* timer;
};

#endif // SCHEDULER_H
