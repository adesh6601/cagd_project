#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <qmainwindow.h>
#include "Point3D.h"

class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;

class QOpenGLPaintDevice;

class OpenGLWindow :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGLWindow(const QColor& background, QMainWindow* parent);
    ~OpenGLWindow();

protected:
    void paintGL() override;
    void initializeGL() override;

private:
    void reset();
    void fillDAA(std::vector<Point3D> pixels);
    void fillPixel(const std::vector<Point3D>& pixel, Point3D& color);
    void getUserInputSimple();
    void getUserInputSym();

private:
    bool mAnimating = false;
    QOpenGLContext* mContext = nullptr;
    QOpenGLPaintDevice* mDevice = nullptr;

    QOpenGLShader* mVshader = nullptr;
    QOpenGLShader* mFshader = nullptr;
    QOpenGLShaderProgram* mProgram = nullptr;

    QList<QVector3D> mVertices;
    QList<QVector3D> mNormals;
    QOpenGLBuffer mVbo;
    int mVertexAttr;
    int mNormalAttr;
    int mMatrixUniform;
    QColor mBackground;
    QMetaObject::Connection mContextWatchConnection;
    float mFloatInputs[4];
    int mChoice = 0;

    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;
};
