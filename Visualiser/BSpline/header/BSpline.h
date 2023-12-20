#include <vector>
#include <utility>
#include "Point3D.h"
#include "pch.h"

class BSPLINE_API BSpline {
public:
    BSpline(int degree);
    std::vector<Point3D> evaluate(std::vector<Point3D>& control_points, float t);

private:
    std::vector<float> generateUniformKnots(int num_control_points);
    float bSplineBasis(int i, int k, float t, const std::vector<float>& knots);

private:
    int mDegree;
};
