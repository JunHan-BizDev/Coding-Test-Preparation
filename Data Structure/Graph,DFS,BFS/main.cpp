#include <iostream>
#include "GraphType.cpp"
using namespace std;

int main(){
    GraphType<const char*> graph;
    
    graph.AddVertex("dog");
    graph.AddVertex("cat");
    graph.AddVertex("animal");
    graph.AddVertex("verte");
    graph.AddVertex("oyster");
    graph.AddVertex("shellfish");
    graph.AddVertex("inverte");
    graph.AddVertex("crab");
    graph.AddVertex("poodle");
    graph.AddVertex("monekt");
    graph.AddVertex("dog");
    graph.AddVertex("dog");
    graph.AddVertex("dog");
    graph.AddVertex("dog");
    graph.AddVertex("dog");

    return 0;
}
