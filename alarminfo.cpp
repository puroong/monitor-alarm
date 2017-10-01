#include "alarminfo.h"

AlarmInfo::AlarmInfo(QTime time, AlarmType type)
{
    this->time = time;
    this->type = type;
}

QTime AlarmInfo::getTime()
{
    return this->time;
}

AlarmType AlarmInfo::getType()
{
    return this->type;
}
