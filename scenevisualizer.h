#ifndef SCENEVISUALIZER_H
#define SCENEVISUALIZER_H

#include <QObject>
#include <QString>
#include <QVTKWidget.h>

#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkAxesActor.h>
#include <vtkSTLReader.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkTransform.h>


class SceneVisualizer : public QObject
{
    Q_OBJECT
public:
    explicit SceneVisualizer(QObject *parent = 0,
                             QVTKWidget *_qvtkWidgetMain = 0,
                             QVTKWidget *_qvtkWidgetTool = 0);
    void setToolRender(int state);
    
signals:
    void finished();

public slots:
    void LoadSTLModel(const QString &path);
    void process();

private:
    bool show_tool_window;
    QVTKWidget *qvtkWidgetMain;
    QVTKWidget *qvtkWidgetTool;
    vtkSmartPointer<vtkRenderer> rendererMain;
    vtkSmartPointer<vtkRenderer> rendererTool;

    vtkSmartPointer<vtkAxesActor> axesActor;

    vtkSmartPointer<vtkTransform> STLModelTransform;
    vtkSmartPointer<vtkActor> STLActor;
};

#endif // SCENEVISUALIZER_H
