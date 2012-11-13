#include "toolwindowwidget.h"
#include "ui_toolwindowwidget.h"

ToolWindowWIdget::ToolWindowWIdget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolWindowWIdget)
{
    ui->setupUi(this);
}


QVTKWidget* ToolWindowWIdget::GetQVTKWidget()  {
    return this->ui->qvtkWidget;
}

ToolWindowWIdget::~ToolWindowWIdget()
{
    delete ui;
}
