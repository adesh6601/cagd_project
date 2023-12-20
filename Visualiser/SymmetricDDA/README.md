# Symmetric DDA Line Drawing Algorithm
 
## Overview
This project is a graphical application developed in C++ using the Qt framework with OpenGL for rendering. Its primary goal is to function as a visualization tool for drawing line in grid. 
 

### 2. Files
   - `SymmetricDDA.h` and `SymmetricDDA.cpp`: Implementation of the SymmetricDDA Line Drawing Algorithm.

   - `drawLineBySymmetricDDA()` function takes line as input with the help of end points of line remaining points are generated using algorithm.
 
   - **Responsibility:** The core line drawing algorithm processes user input and computes the line.
 
   - **User Interface (UI):** Provides users with the ability to input line coordinates .
   
   - **Functionality:** Upon clicking the "Draw line" button, the application renders the line within the Grid and grid takes range from '
   -25 to +25.
 
### 3. Main Program (main.cpp)
   - `main.cpp`: Entry point for the application.

   