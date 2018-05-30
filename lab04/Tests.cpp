#include "Graph.h"
#include <iostream>
#include <time.h>

int main() {
  srand(time(0));

  // DIRECTED GRAPHS
  std::cout << "DIRECTED GRAPHS" << std::endl;
  Graph directedRandomGraph(Directed);

  int minVertices = 10;
  int maxVertices = 10;
  int minProbability = 20;
  int maxProbability = 40;

  int chosenVertices, chosenProbability;
  directedRandomGraph.generateRandomNP(minVertices, maxVertices, minProbability, maxProbability, chosenVertices, chosenProbability);

  std::cout << "Vertices: " << chosenVertices << ", probability: " << chosenProbability << "%" << std::endl << std::endl;

  directedRandomGraph.print();

  std::cout << "\nSaving graph to directedRandomGraph.txt" << std::endl;
  directedRandomGraph.saveGraph("directedRandomGraph.txt");

  std::cout << std::endl << std::endl;


  // STRONGLY CONNECTED COMPONENTS
  std::cout << "STRONGLY CONNECTED COMPONENTS" << std::endl;
  std::vector<int> components = directedRandomGraph.Kosaraju();
  std::cout << std::endl;
  for(unsigned int i = 0; i < components.size(); i++) std::cout << components[i] << " ";
  std::cout << std::endl << std::endl;

  //BELLMAN FORD
  std::cout << "BELLMAN FORD" << std::endl;
  Graph example(Directed);
  //example.readFile("example_bellman_ford.txt");
  example.print();
  example.generateRandomNP(minVertices, maxVertices, minProbability, maxProbability, chosenVertices, chosenProbability);
  example.generateRandomWeights(-5, 10);
  example.printWeights();
  int vert = example.getVertexCount()-1;
  unsigned int startVertex=Graph::intRand(0, vert);
  std::cout << "Finding shortest path distances from vertex " << startVertex+1 << " to every other vertex..." <<std::endl<<std::endl;
  std::vector<int> v=example.BellmanFord(startVertex);

  std::cout << "JOHNSON" << std::endl;
  Graph test(Directed);
  test.generateRandomNP(minVertices, maxVertices, minProbability, maxProbability, chosenVertices, chosenProbability);
  test.generateRandomWeights(1, 10);
  test.Johnson();
}
