#include "stdafx.h"
#include "OpenGLWindow.h"
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>
#include "SimpleDDA.h"
#include "SymDDA.h"
#include "Grid.h"
#include "Line.h"

OpenGLWindow::OpenGLWindow(const QColor& background, QMainWindow* parent) :
    mBackground(background)
{
    setParent(parent);
    setMinimumSize(500, 250);
}

OpenGLWindow::~OpenGLWindow()
{
    reset();
}

void OpenGLWindow::reset()
{
    // And now release all OpenGL resources.
    makeCurrent();
    delete mProgram;
    mProgram = nullptr;
    delete mVshader;
    mVshader = nullptr;
    delete mFshader;
    mFshader = nullptr;
    mVbo.destroy();
    doneCurrent();

    // We are done with the current QOpenGLContext, forget it. If there is a
    // subsequent initialize(), that will then connect to the new context.
    QObject::disconnect(mContextWatchConnection);
}

void OpenGLWindow::paintGL()
{
    QPushButton* inputButtonSimple = new QPushButton("Simple DDA Input", this);
    inputButtonSimple->setGeometry(QRect(QPoint(50, 25), QSize(150, 50)));
    connect(inputButtonSimple, &QPushButton::released, this, &OpenGLWindow::getUserInputSimple);

    QPushButton* inputButtonSym = new QPushButton("Symmetric DDA Input", this);
    inputButtonSym->setGeometry(QRect(QPoint(250, 25), QSize(150, 50)));
    connect(inputButtonSym, &QPushButton::released, this, &OpenGLWindow::getUserInputSym);

    glClear(GL_COLOR_BUFFER_BIT);

    mProgram->bind();

    // Adjust the orthographic projection
    QMatrix4x4 matrix;
    matrix.ortho(-25.0f, 25.0f, -25.0f, 25.0f, 0.1f, 100.0f);
    matrix.translate(0, 0, -2);

    mProgram->setUniformValue(m_matrixUniform, matrix);
    std::vector<double> vertices;
    std::vector<double> colors;

    // Endpoints of line
    Point3D p1 = Point3D(mFloatInputs[0], mFloatInputs[1]);
    Point3D p2 = Point3D(mFloatInputs[2], mFloatInputs[3]);

    std::vector<Point3D> pixels;
    if (mChoice == 1) {
        // Simple DDA
        pixels.clear();
        SimpleDDA line1 = SimpleDDA();
        line1.plotLine(p1, p2, pixels);
    }
    else if(mChoice == 2){
        // Symmetrical DDA
        pixels.clear();
        SymDDA line2 = SymDDA();
        line2.plotLine(p1, p2, pixels);
    }

    fillDAA(pixels);
    Grid grid = Grid();
    grid.drawGrid(40, vertices, colors);

    Line line = Line(p1, p2);
    line.drawLine(vertices, colors);

    QVector<GLfloat> QVertices = QVector<GLfloat>(vertices.begin(), vertices.end());
    QVector<GLfloat> QColors = QVector<GLfloat>(colors.begin(), colors.end());

    GLfloat* verticesData = QVertices.data();
    GLfloat* colorsData = QColors.data();

    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, verticesData);
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(GL_LINES, 0, vertices.size() / 2);

    glDisableVertexAttribArray(m_colAttr);
    glDisableVertexAttribArray(m_posAttr);
}

void OpenGLWindow::fillDAA(std::vector<Point3D> pixels) {
    int i = 0;
    std::vector<Point3D> pixel;
    while (i < pixels.size())
    {
        pixel.clear();
        pixel.push_back(pixels[i]);
        i++;
        pixel.push_back(pixels[i]);
        i++;
        pixel.push_back(pixels[i]);
        i++;
        pixel.push_back(pixels[i]);
        i++;
        Point3D color(1.0f, 0.0f, 1.0f);
        fillPixel(pixel, color);
    }
}

void OpenGLWindow::fillPixel(const std::vector<Point3D>& pixel, Point3D& color)
{
    QVector<GLfloat> vertices;
    QVector<GLfloat> colors;

    // Convert QVector<QVector2D> to QVector<GLfloat>
    for (Point3D point : pixel)
    {
        vertices.push_back(point.x());
        vertices.push_back(point.y());

        colors.push_back(color.x());
        colors.push_back(color.y());
        colors.push_back(color.z());
    }

    GLfloat* verticesData = vertices.data();
    GLfloat* colorsData = colors.data();

    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, verticesData);
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size() / 2);

    glDisableVertexAttribArray(m_colAttr);
    glDisableVertexAttribArray(m_posAttr);
}

void OpenGLWindow::initializeGL()
{
    static const char* vertexShaderSource =
        "attribute highp vec4 posAttr;\n"
        "attribute lowp vec4 colAttr;\n"
        "varying lowp vec4 col;\n"
        "uniform highp mat4 matrix;\n"
        "void main() {\n"
        "   col = colAttr;\n"
        "   gl_Position = matrix * posAttr;\n"
        "}\n";

    static const char* fragmentShaderSource =
        "varying lowp vec4 col;\n"
        "void main() {\n"
        "   gl_FragColor = col;\n"
        "}\n";

    initializeOpenGLFunctions();

    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();
    m_posAttr = mProgram->attributeLocation("posAttr");
    Q_ASSERT(m_posAttr != -1);
    m_colAttr = mProgram->attributeLocation("colAttr");
    Q_ASSERT(m_colAttr != -1);
    m_matrixUniform = mProgram->uniformLocation("matrix");
    Q_ASSERT(m_matrixUniform != -1);

}

void OpenGLWindow::getUserInputSimple() {
    bool ok;
    mChoice = 1;
    // Get a multi-line text input from the user
    QString inputText = QInputDialog::getMultiLineText(this, "User Input", "Enter 4 float values (separated by spaces):", "", &ok);

    if (ok) {
        // Parse the input string into 4 float values
        QStringList inputList = inputText.split(' ');
        if (inputList.size() == 4) {
            bool conversionOk;
            for (int i = 0; i < 4; ++i) {
                mFloatInputs[i] = inputList[i].toFloat(&conversionOk);
                if (!conversionOk) {
                    return;
                }
            }
        }
    }
}

void OpenGLWindow::getUserInputSym() {
    bool ok;
    mChoice = 2;
    // Get a multi-line text input from the user
    QString inputText = QInputDialog::getMultiLineText(this, "User Input", "Enter 4 float values (separated by spaces):", "", &ok);

    if (ok) {
        // Parse the input string into 4 float values
        QStringList inputList = inputText.split(' ');
        if (inputList.size() == 4) {
            bool conversionOk;
            for (int i = 0; i < 4; ++i) {
                mFloatInputs[i] = inputList[i].toFloat(&conversionOk);
                if (!conversionOk) {
                    return;
                }
            }
        }
    }
}
