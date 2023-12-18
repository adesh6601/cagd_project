#pragma once
#include "Point3D.h"
#include "pch.h"
#include <vector>

class ALGORITHM_API SymDDA
{
public:
	SymDDA();
	~SymDDA();

	void plotLine(Point3D inP1, Point3D inP2, std::vector<Point3D>& inPoints);
};

