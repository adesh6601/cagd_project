#include "pch.h"
#include "Grid.h"

Grid::Grid()
{

}

Grid::~Grid()
{

}

void Grid::drawGrid(double size, std::vector<double>& vertices, std::vector<double>& colors)
{
   for (float y = -size / 2.0f; y <= size / 2.0f; y += 1.0)
    {
       vertices.push_back(-size / 2.0f);
       vertices.push_back(y);
       vertices.push_back(size / 2.0f);
       vertices.push_back(y);

       colors.push_back(1.0f);
       colors.push_back(1.0f);
       colors.push_back(1.0f);
       colors.push_back(1.0f);
       colors.push_back(1.0f);
       colors.push_back(1.0f);
    }

    for (float x = -size / 2.0f; x <= size / 2.0f; x += 1.0)
    {
        vertices.push_back(x);
        vertices.push_back(-size / 2.0f);
        vertices.push_back(x);
        vertices.push_back(size / 2.0f);

        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
    }
}
