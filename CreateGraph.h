/*
Joseph Calise
ID#: 2380565
calise@chapman.edu
CPSC-350 Section 03
PA6: Spanning The Gamut
*/
#ifndef CREATEGRAPH_H
#define CREATEGRAPH_H
#include "Edge.h"
#include "WGraph.h"
#include <string>

class CreateGraph{
    public:
    CreateGraph();
    CreateGraph(std::string inputFile);
    ~CreateGraph();
    int arraySize;
    int matrixSize;
    std::string inputFile;
    Edge* findMSTPath();
    WGraph createMSTGraph();
    





};





#endif