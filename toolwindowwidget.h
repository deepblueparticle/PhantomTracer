#ifndef TOOLWINDOWWIDGET_H
#define TOOLWINDOWWIDGET_H

#include <QWidget>
#include <QVTKWidget.h>

namespace Ui {
class ToolWindowWIdget;
}

class ToolWindowWIdget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ToolWindowWIdget(QWidget *parent = 0);
    ~ToolWindowWIdget();

    QVTKWidget* GetQVTKWidget();

private:
    Ui::ToolWindowWIdget *ui;
};

#endif // TOOLWINDOWWIDGET_H
