#include "stdafx.h"
#include "Visualizer.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("Qt QOpenGLWidget Stereoscopic Rendering Example");
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    //! [1]
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);

    // Enable stereoscopic rendering support
    format.setStereo(true);

    QSurfaceFormat::setDefaultFormat(format);
    //! [1]

    Visualizer visualizer;
    visualizer.show();
    return a.exec();
}
