# Hermite Curve Implementation
## Overview
This C++ code presents an implementation of a cubic `Hermite curve``, a mathematical curve defined by four control points. The Hermite curve interpolation is widely employed in computer graphics and animation to craft seamless paths with predefined tangent vectors at each control point.

## Files
Hermite.h: Header file containing the declaration of the Hermite class.
Hermite.cpp: Source file containing the implementation of the Hermite class methods.
pch.h: Precompiled header file.
Other dependencies: Ensure that you have necessary dependencies installed or included in your project.

`drawCurve()` function is used to draw the curve using the four points provided by user and genrate all the points on curve by using bezier algorithm.

- **User Interface (UI):** Provides users with the ability to input the coordinates of four points.
   
- **Functionality:** Upon clicking the "Hermite Curve" button, the application renders the Curve.
 
###  Main Program (main.cpp)
   - `main.cpp`: Entry point for the application.