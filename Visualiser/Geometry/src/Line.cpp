#include "pch.h"
#include "Line.h"

Line::Line(Point3D inP1, Point3D inP2)
    :mP1(0, 0),
    mP2(0, 0)
{
    mP1 = inP1;
    mP2 = inP2;
}

Line::~Line()
{

}

void Line::drawLine(std::vector<double>& vertices, std::vector<double>& colors)
{
    vertices.push_back(mP1.x());
    vertices.push_back(mP1.y());
    vertices.push_back(mP2.x());
    vertices.push_back(mP2.y());

    colors.push_back(255.0f);
    colors.push_back(255.0f);
    colors.push_back(255.0f);
    colors.push_back(255.0f);
    colors.push_back(255.0f);
    colors.push_back(255.0f);
}
