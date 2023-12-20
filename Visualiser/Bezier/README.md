# Bezier Curve Implementation
## Overview
This C++ code presents an implementation of a cubic `Bezier curve``, a mathematical curve defined by four control points. The Bezier curve is passing through end points and with the help of two remaning points we can calculate convex hull.

## Files
Bezier.h: Header file containing the declaration of the Bezier class.
Bezier.cpp: Source file containing the implementation of the Bezier class methods.
pch.h: Precompiled header file.
Other dependencies: Ensure that you have necessary dependencies installed or included in your project.

`drawCurve()` function is used to draw the curve using the four points provided by user and genrate all the points on curve by using bezier algorithm.

- **User Interface (UI):** Provides users with the ability to input the coordinates of four points.
   
- **Functionality:** Upon clicking the "Bezier Curve" button, the application renders the Curve.
 
###  Main Program (main.cpp)
   - `main.cpp`: Entry point for the application.