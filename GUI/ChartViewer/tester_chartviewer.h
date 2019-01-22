#ifndef TESTER_CHARTVIEWER_H
#define TESTER_CHARTVIEWER_H

#include <QObject>

class Tester_ChartViewer : public QObject
{
    Q_OBJECT
public:
    explicit Tester_ChartViewer(QObject *parent = nullptr);
    Q_INVOKABLE void send_data(float x, float y);

signals:
    void incoming_Data(float angle, float x, float y);

public slots:
};

#endif // TESTER_CHARTVIEWER_H
