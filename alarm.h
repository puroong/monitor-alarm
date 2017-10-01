#ifndef ALARM_H
#define ALARM_H

#include <QObject>
#include "alarminfo.h"

class Alarm : public QObject
{
    Q_OBJECT
public:
    explicit Alarm(QObject *parent = nullptr);
signals:

public slots:
    virtual void ring() = 0;
};

#endif // ALARM_H
