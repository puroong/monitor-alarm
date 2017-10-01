#include "alarminfo.h"

AlarmInfo::AlarmInfo()
{

}

QTime AlarmInfo::getTime()
{
    return this->time;
}

AlarmType AlarmInfo::getType()
{
    return this->type;
}
