#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Create second window
    tool_widget = new ToolWindowWIdget();
    tool_widget->show();

    //Connect Aurora controller worker and thread
    aurora_controller_thread = new QThread;
    aurora_controller = new AuroraControlWorker();
    aurora_controller->moveToThread(aurora_controller_thread);
    connect(aurora_controller_thread, SIGNAL(started()),
            aurora_controller, SLOT(process()));
    connect(aurora_controller, SIGNAL(finished()),
            aurora_controller_thread, SLOT(quit()));
    connect(aurora_controller, SIGNAL(finished()),
            aurora_controller_thread, SLOT(deleteLater()));
    connect(aurora_controller_thread, SIGNAL(finished()),
            aurora_controller_thread, SLOT(deleteLater()));

    //Connect Visualizer worker and thread
    visualizer_thread = new QThread;
    visualizer = new SceneVisualizer(NULL, this->ui->qvtkWidget,
                                     tool_widget->GetQVTKWidget());
    visualizer->moveToThread(visualizer_thread);
    connect(visualizer_thread, SIGNAL(started()),
            visualizer, SLOT(process()));
    connect(visualizer, SIGNAL(finished()),
            visualizer_thread, SLOT(quit()));
    connect(visualizer, SIGNAL(finished()),
            visualizer_thread, SLOT(deleteLater()));
    connect(visualizer_thread, SIGNAL(finished()),
            visualizer_thread, SLOT(deleteLater()));

    //Connect UI widgets
    connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)),
            this, SLOT(OpacityDSpinChanged(double)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            this, SLOT(OpacitySliderChanged(int)));
    connect(ui->actionLoad_STL_mesh, SIGNAL(triggered()),
            this, SLOT(LoadSTLDialog()));
    connect(ui->groupBox_4, SIGNAL(toggled(bool)),
            this, SLOT(TriggerToolView(bool)));

    //connect with other objects
    connect(this, SIGNAL(LoadSTLMesh(QString)),
            visualizer, SLOT(LoadSTLModel(QString)));

    aurora_controller_thread->start();
    visualizer_thread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete aurora_controller_thread;
    delete aurora_controller;
    delete visualizer;
    delete visualizer_thread;
}


void MainWindow::TriggerToolView(bool state)  {
    if (state)  {
        visualizer->setToolRender(1);
        tool_widget->show();
    }  else  {
        visualizer->setToolRender(0);
        tool_widget->hide();
    }
}

void MainWindow::OpacitySliderChanged(int value)  {
    ui->doubleSpinBox->blockSignals(true);
    ui->doubleSpinBox->setValue( ((double)value)/100.0 );
    ui->doubleSpinBox->blockSignals(false);
}


void MainWindow::OpacityDSpinChanged(double value)  {
    ui->horizontalSlider->blockSignals(true);
    ui->horizontalSlider->setValue( (int)(100 * value) );
    ui->horizontalSlider->blockSignals(false);
}


void MainWindow::LoadSTLDialog()  {
    QString path = QFileDialog::getOpenFileName(this, tr("Open STL model"),
                                                ".stl", tr(""));
    if (path == "")
        return;
    emit LoadSTLMesh(path);
}
