#pragma once
#include "Point3D.h"
#include <vector>
#include "pch.h"

class GEOMETRY_API Line
{
public:
	Line(Point3D inP1, Point3D inP2);
	~Line();

	void drawLine(std::vector<double>& vertices, std::vector<double>& colors);

private:
	Point3D mP1;
	Point3D mP2;
};

