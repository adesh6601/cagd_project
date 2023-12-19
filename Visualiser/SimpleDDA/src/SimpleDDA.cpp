#include "pch.h"
#include "SimpleDDA.h"

SimpleDDA::SimpleDDA()
{

}

SimpleDDA::~SimpleDDA()
{

}

void SimpleDDA::plotLine(Point3D inP1, Point3D inP2, std::vector<Point3D>& inPoints)
{
    float dx = abs(inP2.x() - inP1.x());
    float dy = abs(inP2.y() - inP1.y());

    float steps = dx > dy ? dx : dy;

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = inP1.x();
    float y = inP1.y();
    for (int i = 0; i < steps; i++) {
        inPoints.push_back(Point3D(round(x), round(y)));
        inPoints.push_back(Point3D(round(x) + 1, round(y)));
        inPoints.push_back(Point3D(round(x) + 1, round(y) + 1));
        inPoints.push_back(Point3D(round(x), round(y) + 1));

        x += xInc;
        y += yInc;
    }
}
