#ifndef BUTTON
#define BUTTON

#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMouseEvent>

class QMyPushButton : public QPushButton
{
        Q_OBJECT
public:
        QMyPushButton(QWidget *parent = 0) : QPushButton(parent){};
signals:
        void rClicked();
protected:
        void mouseReleaseEvent(QMouseEvent *event)
        {
        if(event->button() == Qt::RightButton)
                {
                emit rClicked();
                }
        }
};

#endif // BUTTON

