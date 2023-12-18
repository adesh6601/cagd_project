// Algorithm.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Algorithm.h"


// This is an example of an exported variable
ALGORITHM_API int nAlgorithm=0;

// This is an example of an exported function.
ALGORITHM_API int fnAlgorithm(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
Algorithm::Algorithm()
{
    return;
}
