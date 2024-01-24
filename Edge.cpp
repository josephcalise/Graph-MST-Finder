/*
Joseph Calise
ID#: 2380565
calise@chapman.edu
CPSC-350 Section 03
PA6: Spanning The Gamut
*/
#include "Edge.h"

Edge::Edge(){
    this->x = 0;
    this->y = 0;
    this->weight = 0;
}

Edge::Edge(int x, int y, float weight){
    this->x = x;
    this->y = y;
    this->weight = weight;
}

Edge::~Edge(){

}

