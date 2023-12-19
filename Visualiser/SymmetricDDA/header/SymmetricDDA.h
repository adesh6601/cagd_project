#pragma once
#include "Point3D.h"
#include "pch.h"
#include <vector>

class SYMMETRICDDA_API SymmetricDDA
{
public:
	SymmetricDDA();
	~SymmetricDDA();

	void plotLine(Point3D inP1, Point3D inP2, std::vector<Point3D>& inPoints);
};
