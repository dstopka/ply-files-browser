#include <Toolpack.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>

Data readFile(char *path)
{
    Data data;
    std::ifstream file;
    std::cout << path << std::endl;
    file.open(path);
    if(!file.good() || file.eof())
        exit(0);
    std::string str;
    int verticesNumber;
    int elementsNumber;
    while(str != "end_header")
    {
        file >> str;
        if(str == "vertex")
            file>>verticesNumber;
        if(str == "face")
            file>>elementsNumber;
    }
    for(auto [i, vertex] = std::tuple(0, 0.0); i < verticesNumber * 3; ++i)
    {
        file>>vertex;
        data.vertices.push_back(vertex);
    }
    std::cout << "Vertices loaded!" << std::endl;
    for(auto [i, type, element] = std::tuple(0, 0, 0); i < elementsNumber; ++i)
    {
        file>>type;
        if(type == 3)
            for (auto j = 0; j < type; ++j)
            {
                file >> element;
                data.triangleElements.push_back(element);
            }
        else if(type == 4)
            for (auto j = 0; j < type; ++j)
            {
                file >> element;
                data.polygonElements.push_back(element);
            }
        file.ignore(256, '\n');
    }
    data.minMaxValues = findMinMax(data.vertices);
    normalise(data);
    data.minMaxValues = findMinMax(data.vertices);
    file.close();
    return data;
}

Dimension<std::pair<float, float>> findMinMax(std::vector<GLfloat> &vertices)
{
    Dimension<std::pair<float, float>> minMax;
    minMax.x.first = minMax.x.second = vertices[0];
    minMax.y.first = minMax.y.second = vertices[1];
    minMax.z.first = minMax.z.second = vertices[2];

    for(int i = 3; i < vertices.size(); i += 3)
    {
        if(vertices[i] < minMax.x.first)
            minMax.x.first = vertices[i];
        if(vertices[i] > minMax.x.second)
            minMax.x.second = vertices[i];
        if(vertices[i+1] < minMax.y.first)
            minMax.y.first = vertices[i+1];
        if(vertices[i+1] > minMax.y.second)
            minMax.y.second = vertices[i+1];
        if(vertices[i+2] < minMax.z.first)
            minMax.z.first = vertices[i+2];
        if(vertices[i+2] > minMax.z.second)
            minMax.z.second = vertices[i+2];
    }
    std::cout << std::endl;
    std::cout << "x.max " << minMax.x.second << std::endl;
    std::cout << "y.max " << minMax.y.second << std::endl;
    std::cout << "z.max " << minMax.z.second << std::endl;
    std::cout << "x.min " << minMax.x.first << std::endl;
    std::cout << "y.min " << minMax.y.first << std::endl;
    std::cout << "z.min " << minMax.z.first << std::endl << std::endl;
    return minMax;
}

void normalise(Data &data)
{
    float delta = data.minMaxValues.z.second - data.minMaxValues.z.first;
    for(int i = 0; i < data.vertices.size(); i += 3)
    {
        data.vertices[i] = (data.vertices[i] - data.minMaxValues.x.first) / delta;
        data.vertices[i+1] = (data.vertices[i+1] - data.minMaxValues.y.first) / delta;
        data.vertices[i+2] = (data.vertices[i+2] - data.minMaxValues.z.first) / delta;
    }
}
