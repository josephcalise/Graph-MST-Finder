/*
Joseph Calise
ID#: 2380565
calise@chapman.edu
CPSC-350 Section 03
PA6: Spanning The Gamut
*/
#include "CreateGraph.h"
#include "Edge.h"
#include "Reader.h"
#include "WGraph.h"
#include "MinHeap.h"
#include "Set.h"
#include <iostream>
#include <string>

/*
CreateGraph is the constructor function for the class.
It contains the member variables arraySize and matrixSize.
These member variables are mostly used for ease of data transfering.
*/
CreateGraph::CreateGraph(){
    this->arraySize = 0;
    this->matrixSize = 0;
    this->inputFile = "input.txt";
}
//command line arg constructor
CreateGraph::CreateGraph(std::string inputFile){
    this->inputFile = inputFile;
    this->arraySize = 0;
    this->matrixSize = 0;
}

//Deconstructor
CreateGraph::~CreateGraph(){


}

/*
findMSTPath is a function that will use the input.txt file and find the MST weights
Once everything is imported, the function will put everything into a 2D array. 
From that array it will sort all paths from smallest weights to largest weight using a min-heap BST.
then each edge will be ran through a large conditional to ensure all connections are made.
This is done by using 2 sets and making sure they are connected.
If the weights are used then the edges will be placed into an array for usable edges.
*/
Edge* CreateGraph::findMSTPath(){
    Reader reader;
    reader.importFile(this->inputFile);
    double** matrix;
    matrix = reader.processArrays();
    MinHeap<Edge> heap = MinHeap<Edge>(reader.n*10);
    Set<int> set1 = Set<int>();
    Set<int> set2 = Set<int>();
    Edge* edgesToAdd = new Edge[50];
    int edgesAdded = 0;
    this->matrixSize = reader.n;
    int i;
    int j;
    for (i = 0; i < reader.n; i++){
        for(j = 0; j < reader.n; j++){
            if (matrix[i][j] > 0 && j >= i){ // j>=i will make sure we are not adding the other side of the edge.
                Edge edge = Edge(i, j, matrix[i][j]);
                heap.insert(edge);
            }
        }
    }
    Edge current = heap.dequeue();
    set1.add(current.x);
    set1.add(current.y);
    //std::cout << current.x << " " << current.y << " " << current.weight << std::endl;
    edgesToAdd[edgesAdded++] = current;
    //add this edge to the edge array
    bool connected = false;
    while (!heap.isEmpty()){
        Edge current = heap.dequeue();
        //std::cout << current.x << " " << current.y << " " << current.weight << std::endl;
        if (((set1.contains(current.x)) && (set1.contains(current.y))) || ((set2.contains(current.x)) && (set2.contains(current.y)))) {
        continue;
        } else if ((((set1.contains(current.x)) && (set2.contains(current.y))) || ((set1.contains(current.y)) && (set2.contains(current.x)))) && (connected == true)) {
            continue;
        } else if ((!set1.contains(current.x)) && (!set1.contains(current.y))) {
            if ((set2.contains(current.x)) && (!set2.contains(current.y))) {
                set2.add(current.y);
            } else if ((!set2.contains(current.x)) && (set2.contains(current.y))) {
                set2.add(current.x);
            } else if ((!set2.contains(current.x)) && (!set2.contains(current.y))) {
                set2.add(current.x);
                set2.add(current.y);
            }
            edgesToAdd[edgesAdded++] = current;
        } else if ((set1.contains(current.x)) && (!set1.contains(current.y))) {
            if (set2.contains(current.y)) {
                //std::cout << "Connection point" << std::endl;
                edgesToAdd[edgesAdded++] = current;
                connected = true;
            } else {
                set1.add(current.y);
                edgesToAdd[edgesAdded++] = current;
            }
        } else if ((!set1.contains(current.x)) && (set1.contains(current.y))) {
            if (set2.contains(current.x)) {
                //std::cout << "Connection point" << std::endl;
                edgesToAdd[edgesAdded++] = current;
                connected = true;
            } else {
                set1.add(current.x);
                edgesToAdd[edgesAdded++] = current;
            }
    
    }

    }
    //set1.printSet();
    //set2.printSet();
    this->arraySize = edgesAdded;
    double total;
    total = 0.0;
    for (i = 0; i < edgesAdded; i++){
        //std::cout << edgesToAdd[i].weight << std::endl;
        total += edgesToAdd[i].weight;
    }
    return edgesToAdd;
}

/*
createMSTGraph will take all the edges that were placed into the array above
and creates the graph with each of those elements.
*/
WGraph CreateGraph::createMSTGraph(){
    Edge *edgeArr = findMSTPath();
    WGraph graph = WGraph(this->matrixSize);
    int i;
    for (i = 0; i < this->arraySize; i++){
        graph.addEdge(edgeArr[i].x, edgeArr[i].y, edgeArr[i].weight);
    }
    return graph;
}