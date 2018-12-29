#ifndef API_TERMINAL_H
#define API_TERMINAL_H

#include <QObject>

class API_Terminal : public QObject
{
    Q_OBJECT
public:
    explicit API_Terminal(QObject *parent = nullptr);

signals:

public slots:
};

#endif // API_TERMINAL_H