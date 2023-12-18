#pragma once
#include "Point3D.h"
#include <vector>
#include "pch.h"


class ALGORITHM_API SimpleDDA
{
public:
	SimpleDDA();
	~SimpleDDA();

	void plotLine(Point3D inP1, Point3D inP2, std::vector<Point3D>& inPoints);
};

