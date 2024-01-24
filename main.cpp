/*
Joseph Calise
ID#: 2380565
calise@chapman.edu
CPSC-350 Section 03
PA6: Spanning The Gamut
*/
#include "CreateGraph.h"
#include "WGraph.h"
#include <iostream>

int main(int argc, char** argv){
    if (argc == 1){
        CreateGraph graphMaker = CreateGraph();
        graphMaker.findMSTPath();
        WGraph graph = graphMaker.createMSTGraph();
        graph.printGraph();
        graph.computeMST();
    }else{
        std::string inputFile = argv[1];
        CreateGraph graphMaker = CreateGraph(inputFile);
        graphMaker.findMSTPath();
        WGraph graph = graphMaker.createMSTGraph();
        graph.printGraph();
        graph.computeMST();
    }

}

/*
Set 1 does not have x or y: check set 2 / if set two has x or y add the oposite
set 1 has (x or y) check set 2 for the other.
Set 1 has x add y
set 1 has y add x
Set 2 has x add y
set 2 has y add x

*/
