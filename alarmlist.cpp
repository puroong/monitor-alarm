#include "alarmlist.h"

AlarmList* AlarmList::instance = 0;

AlarmList::AlarmList(QObject *parent) : QObject(parent)
{

}

AlarmList* AlarmList::getInstance()
{
    if(instance == 0)
    {
        instance = new AlarmList();
    }

    return instance;
}

void AlarmList::addAlarm(AlarmInfo *a)
{
    qDebug() << "AlarmList::addAlarm; trying to add time: " << a->getTime();
    QLinkedList<AlarmInfo*>::iterator iter;
    for(iter = alarmList.begin();iter!=alarmList.end();iter++)
    {
        if((*iter)->getTime() == a->getTime())
        {
            qDebug() << "AlarmList::addAlarm;error: same alarm exists";
            return;
        }
        else if((*iter)->getTime() > a->getTime())
        {
            break;
        }
    }

    alarmList.insert(iter, a);
    emit updateAlarmList();
}

void AlarmList::removeNextAlarm()
{
    alarmList.pop_front();
    emit updateAlarmList();
}

void AlarmList::clear()
{
    alarmList.clear();
}

AlarmInfo& AlarmList::getNextAlarm()
{
    return *alarmList.first();
}

QLinkedList<AlarmInfo*>::iterator AlarmList::begin()
{
    return alarmList.begin();
}

QLinkedList<AlarmInfo*>::iterator AlarmList::end()
{
    return alarmList.end();
}
