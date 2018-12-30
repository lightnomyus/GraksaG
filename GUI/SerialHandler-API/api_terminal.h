#ifndef API_TERMINAL_H
#define API_TERMINAL_H

#include <QObject>

class API_Terminal : public QObject
{
    Q_OBJECT
public:
    explicit API_Terminal(QObject *parent = nullptr);

signals:
    void update_UI(QString message);

public slots:
    void receive_Message(QString message);
};

#endif // API_TERMINAL_H
