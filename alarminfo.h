#ifndef ALARMINFO_H
#define ALARMINFO_H

#include "common.h"
#include "alarmtype.h"

class AlarmInfo
{
public:
    AlarmInfo(QTime time, AlarmType type);
    QTime getTime();
    AlarmType getType();
private:
    QTime time;
    AlarmType type;
};

#endif // ALARMINFO_H
