#ifndef ALARMLIST_H
#define ALARMLIST_H

#include "common.h"
#include <QObject>
#include "alarminfo.h"
#include <QLinkedList>

class AlarmList : public QObject
{
    Q_OBJECT
public:
    explicit AlarmList(QObject *parent = nullptr);
    static AlarmList* getInstance();
    void addAlarm(AlarmInfo* a);
    void removeNextAlarm();
    void clear();
    AlarmInfo& getNextAlarm();
    QLinkedList<AlarmInfo*>::iterator begin();
    QLinkedList<AlarmInfo*>::iterator end();
signals:
    void updateAlarmList();
public slots:

private:
    static AlarmList* instance;
    QLinkedList<AlarmInfo*> alarmList;
};

#endif // ALARMLIST_H
