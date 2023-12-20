# BSpline Curve Implementation
## Overview
This C++ code presents an implementation of a cubic `BSpline curve`, a mathematical curve defined by four control points.

## Files
BSpline3D.h: Header file containing the declaration of the BSpline3D class.
BSpline3D.cpp: Source file containing the implementation of the BSpline3D class methods.
pch.h: Precompiled header file.
Other dependencies: Ensure that you have necessary dependencies installed or included in your project.

`drawCurveBspline()` function is used to draw the curve.

`basisFunction()` used to generate basis value.

`evaluate()` function generate the coordinates on curve and add it to vertices vector.

- **User Interface (UI):** Provides users with the ability to input the coordinates of four points.
   
- **Functionality:** Upon clicking the "BSpline Curve" button, the application renders the Curve.

### Main Program (main.cpp)
   - `main.cpp`: Entry point for the application.