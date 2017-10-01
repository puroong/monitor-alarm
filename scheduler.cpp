#include "scheduler.h"

Scheduler::Scheduler(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
}


Scheduler::Scheduler(QTime startTime, QTime endTime, int period, int frequentPeriod, QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    rAlarm = new RegularAlarm(startTime, endTime, period);
    fAlarm = new FrequentAlarm(startTime, frequentPeriod);

    connect(timer, SIGNAL(timeout()), this, SLOT(checkAlarm()));
    connect(this, SIGNAL(ringFrequentAlarm()), fAlarm, SLOT(ring()));
    connect(this, SIGNAL(ringRegularAlarm()), rAlarm, SLOT(ring()));
}

Scheduler::~Scheduler()
{
    AlarmList::getInstance()->clear();

    timer->stop();

    delete timer;
    delete rAlarm;
    delete fAlarm;
}

void Scheduler::run()
{
    timer->start(1000);
}

void Scheduler::checkAlarm()
{
    AlarmInfo alarmInfo = AlarmList::getInstance()->getNextAlarm();

    int alarmTimeSec = alarmInfo.getTime().msecsSinceStartOfDay() / 1000;
    int currentTimeSec = QTime::currentTime().msecsSinceStartOfDay() / 1000;

    if(abs(alarmTimeSec - currentTimeSec) <= 5)
    {
        if(alarmInfo.getType() == AlarmType::frequent)
        {
            emit ringFrequentAlarm();
        }
        else
        {
            emit ringRegularAlarm();
        }
    }

    qDebug() << "Scheduler::checkAlarm; alarmTime: " << alarmInfo.getTime() << " currentTime: " << QTime::currentTime();
}
