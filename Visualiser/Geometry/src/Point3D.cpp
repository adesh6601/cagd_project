#include "pch.h"
#include "Point3D.h"

Point3D::Point3D(double inX, double inY, double inZ)
	:mX(0),
	mY(0),
	mZ(0)
{
	mX = inX;
	mY = inY;
	mZ = inZ;
}

Point3D::~Point3D()
{

}

double Point3D::x()
{
	return mX;
}

double Point3D::y()
{
	return mY;
}

double Point3D::z()
{
	return mZ;
}
