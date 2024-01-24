/*
Joseph Calise
ID#: 2380565
calise@chapman.edu
CPSC-350 Section 03
PA6: Spanning The Gamut
*/
#ifndef EDGE_H
#define EDGE_H

#include <cstdlib>
#include <iostream>
#include <limits>

class Edge{
public:
    int x;
    int y;
    double weight;
    bool operator==(const Edge& other) const {
        return weight == other.weight;
    }
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
    bool operator<=(const Edge& other) const {
        return weight <= other.weight;
    }
    Edge();
    Edge(int x, int y, float weight);
    ~Edge();
};
#endif