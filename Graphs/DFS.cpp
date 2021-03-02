#include "DFS.h"

#include <iostream>
#include <list>

// Default constructor
DFS_Graph::DFS_Graph() {}

// Constructer with vertices, list
DFS_Graph::DFS_Graph(int v) {

	// Set number of vertices
	vertices = v;

	// Create new adjacency list
	adjacency = new std::list<int>[v];
}

// Destructor
DFS_Graph::~DFS_Graph() {}

// Implementation to add edges
void DFS_Graph::addEdge(int vertices, int edges) {
	adjacency[vertices].push_back(edges);
}

// Recursively call to visit each vertex
void DFS_Graph::DFS_helper(std::string *city, int dataPoint, bool *visited) {

	// Use static counter to clarify display
	static int DFScounter = 0;

	// Mark the current node as visited
	std::cout << DFScounter << ". " << city[dataPoint] << std::endl;
	visited[dataPoint] = true;

	// Increase counter
	++DFScounter;

	// Go through the adjacency list
	for (auto i = adjacency[dataPoint].begin(); i != adjacency[dataPoint].end(); i++) {

		// If not visited, recursively move to next vertex
		if (!visited[*i]) {
			DFS_helper(city, *i, visited);
		}
	}
	// Reset the DFS counter
	DFScounter = 0;
}

// Perform depth first search with a given vertex
void DFS_Graph::DFS(std::string *city, int dataPoint) {

	// Start with all vertices as not visited
	bool *visited = new bool[vertices];
	for (int i = 0; i < vertices; i++) {
		visited[i] = false;
	}

	// Beginning of recursive call
	DFS_helper(city, dataPoint, visited);
}

// Create 'edges' to be used for DFS traversal
void DFS_Graph::DFScreateEdges() {

	//From Seattle
	addEdge(0, 1);
	addEdge(0, 3);
	addEdge(0, 5);

	// From San Francisco
	addEdge(1, 2);
	addEdge(1, 3);
	addEdge(1, 0);

	// From Los Angeles
	addEdge(2, 10);
	addEdge(2, 4);
	addEdge(2, 3);
	addEdge(2, 1);

	// From Denver
	addEdge(3, 2);
	addEdge(3, 4);
	addEdge(3, 5);
	addEdge(3, 0);
	addEdge(3, 1);

	// From Kansas City
	addEdge(4, 10);
	addEdge(4, 8);
	addEdge(4, 7);
	addEdge(4, 5);
	addEdge(4, 3);
	addEdge(4, 2);

	// From Chicago
	addEdge(5, 4);
	addEdge(5, 7);
	addEdge(5, 6);
	addEdge(5, 0);
	addEdge(5, 3);

	// From Boston
	addEdge(6, 7);
	addEdge(6, 5);

	// From New York City
	addEdge(7, 8);
	addEdge(7, 6);
	addEdge(7, 5);
	addEdge(7, 4);

	// From Atlanta
	addEdge(8, 9);
	addEdge(8, 7);
	addEdge(8, 4);
	addEdge(8, 10);
	addEdge(8, 11);

	// From Miami
	addEdge(9, 8);
	addEdge(9, 11);

	// From Dallas
	addEdge(10, 11);
	addEdge(10, 8);
	addEdge(10, 4);
	addEdge(10, 2);

	// From Houston
	addEdge(11, 9);
	addEdge(11, 8);
	addEdge(11, 10);
}