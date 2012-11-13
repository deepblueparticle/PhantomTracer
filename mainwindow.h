#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QFileDialog>
#include <QMessageBox>
#include <QObject>
#include <QtCore>
#include <QtGui>
#include <QVTKWidget.h>

#include "auroracontrolworker.h"
#include "scenevisualizer.h"
#include "toolwindowwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    ToolWindowWIdget *tool_widget;

    AuroraControlWorker *aurora_controller;
    QThread *aurora_controller_thread;

    SceneVisualizer     *visualizer;
    QThread *visualizer_thread;

signals:
    void LoadSTLMesh(const QString &path);

public slots:
    void OpacitySliderChanged(int value);
    void OpacityDSpinChanged(double value);
    void LoadSTLDialog();
    void TriggerToolView(bool state);
};

#endif // MAINWINDOW_H
