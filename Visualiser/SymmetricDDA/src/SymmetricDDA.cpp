#include "pch.h"
#include "SymmetricDDA.h"
#include <vector>
#include "Point3D.h"

SymmetricDDA::SymmetricDDA()
{

}

SymmetricDDA::~SymmetricDDA()
{

}

void SymmetricDDA::plotLine(Point3D inP1, Point3D inP2, std::vector<Point3D>& inPoints)
{
    float dx = abs(inP2.x() - inP1.x());
    float dy = abs(inP2.y() - inP1.y());

    float deltaX;
    float deltaY;

    deltaX = dy > dx ? dx / dy : dx / dx;
    deltaY = dy > dx ? dy / dy : dy / dx;

    float x1 = inP1.x();
    float y1 = inP1.y();

    float x2 = inP2.x();
    float y2 = inP2.y();
    while (x1 < x2)
    {
        inPoints.push_back(Point3D(round(x1), round(y1)));
        inPoints.push_back(Point3D(round(x1) + 1, round(y1)));
        inPoints.push_back(Point3D(round(x1) + 1, round(y1) + 1));
        inPoints.push_back(Point3D(round(x1), round(y1) + 1));
        x1 = x1 + deltaX;
        y1 = y1 + deltaY;
    }
}
