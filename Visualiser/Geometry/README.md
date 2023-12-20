# Geometry
## Overview
This project contains various geomteric entities such as `Point`, `Line`, `Rectanglee` which are used for impelementation of other projects such as Symmetric DDA, Sutherland Cohen line cliping algorithm. 

## Files
Geometry.h: Header file containing the declaration of the Geometry class.
Geometry.cpp: Source file containing the implementation of the Geometry class methods.

Point3D.h: Header file containing the declaration of the Point3D class.
Point3D.cpp: Source file containing the implementation of the Point3D class methods.

Line.h: Header file containing the declaration of the Point3D class.
Line.cpp: Source file containing the implementation of the Point3D class methods.

Rectanglee.h: Header file containing the declaration of the Point3D class.
Rectanglee.cpp: Source file containing the implementation of the Point3D class methods.

pch.h: Precompiled header file.
Other dependencies: Ensure that you have necessary dependencies installed or included in your project.

`Point3D()` Constructor will take three float as input which represent the coordinates of point.

`Line()`    Constructor will take two `Points` as input and assign it to data member of class.

`Rectanglee()` Constructor will take coordinates of the diagonal of rectangle and generate all the four points of rectangle.
 
### Main Program (main.cpp)
   - `main.cpp`: Entry point for the application.