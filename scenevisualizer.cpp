#include "scenevisualizer.h"

SceneVisualizer::SceneVisualizer(QObject *parent, QVTKWidget *_qvtkWidgetMain,
                                 QVTKWidget *_qvtkWidgetTool) :
    QObject(parent)
{
    qvtkWidgetMain = _qvtkWidgetMain;
    qvtkWidgetTool = _qvtkWidgetTool;

    rendererMain = vtkSmartPointer<vtkRenderer>::New();
    rendererTool = vtkSmartPointer<vtkRenderer>::New();
    axesActor = vtkSmartPointer<vtkAxesActor>::New();

    STLModelTransform = vtkSmartPointer<vtkTransform>::New();

    rendererMain->SetAmbient(0.4, 0.4, 0.4);
    rendererTool->SetAmbient(0.4, 0.4, 0.4);

    rendererMain->AddActor(axesActor);

    qvtkWidgetMain->GetRenderWindow()->AddRenderer(rendererMain);
}


void SceneVisualizer::LoadSTLModel(const QString &path)  {
    vtkSmartPointer<vtkSTLReader> STLReader =
            vtkSmartPointer<vtkSTLReader>::New();
    STLReader->SetFileName(path.toLatin1().constData());
    STLReader->Update();

    STLModelTransform->Identity();
    vtkSmartPointer<vtkTransformPolyDataFilter> STLTransformFilter =
        vtkSmartPointer<vtkTransformPolyDataFilter>::New();
    STLTransformFilter->SetInputConnection(STLReader->GetOutputPort());
    STLTransformFilter->SetTransform(STLModelTransform);
    STLTransformFilter->Update();

    vtkSmartPointer<vtkPolyDataMapper> mapper =
      vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(STLTransformFilter->GetOutputPort());
    STLActor = vtkSmartPointer<vtkActor>::New();
    STLActor->SetMapper(mapper);
    rendererMain->AddActor(STLActor);
}


void SceneVisualizer::setToolRender(int state)  {
    //TODO: mutex
    show_tool_window = (state != 0);
}


void SceneVisualizer::process()  {
        ;
}
