#include "pch.h"
#include "Bezier.h"
#include <cmath>

Bezier::Bezier(Point3D inP0, Point3D inP1, Point3D inP2, Point3D inP3) :
    mP0(inP0),
    mP1(inP1),
    mP2(inP2),
    mP3(inP2)
{

}

Bezier::~Bezier()
{

}

void Bezier::drawCurve(Point3D inP0, Point3D inP1, Point3D inP2, Point3D inP3, std::vector<float>& mVertices, std::vector<float>& mColors)
{
    for (float t = 0; t <= 1; t += 0.001)
    {

        float x = pow(1 - t, 3) * inP0.x() + 3 * pow(1 - t, 2) * t * inP1.x() + 3 * (1 - t) * pow(t, 2) * inP2.x() + pow(t, 3) * inP3.x();
        float y = pow(1 - t, 3) * inP0.y() + 3 * pow(1 - t, 2) * t * inP1.y() + 3 * (1 - t) * pow(t, 2) * inP2.y() + pow(t, 3) * inP3.y();
        float z = pow(1 - t, 3) * inP0.z() + 3 * pow(1 - t, 2) * t * inP1.z() + 3 * (1 - t) * pow(t, 2) * inP2.z() + pow(t, 3) * inP3.z();

        mVertices.push_back(x);
        mVertices.push_back(y);
        mVertices.push_back(z);

        mVertices.push_back(x);
        mVertices.push_back(y);
        mVertices.push_back(z);

        mColors.push_back(0.0f);
        mColors.push_back(1.0f);
        mColors.push_back(0.0f);

        mColors.push_back(0.0f);
        mColors.push_back(1.0f);
        mColors.push_back(0.0f);

    }

}