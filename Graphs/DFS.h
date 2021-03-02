#ifndef DFS_H
#define DFS_H

#include <iostream>
#include <list>
#include <string>

class DFS_Graph {
private:

	// Number of vertices used in the graph
	int vertices;

	// Pointer to list of vertices (adjacency list)
	std::list<int> *adjacency;

	// DFS helper function
	void DFS_helper(std::string *city, int dataPoint, bool *visited);

public:

	// Constructors
	DFS_Graph();
	DFS_Graph(int v);

	// Destructor
	~DFS_Graph();

	// Method to add an edge
	void addEdge(int vertices, int edges);

	// Method for DFS traversal given a data point and array
	void DFS(std::string *city, int dataPoint);

	// Create the edges from the vertices
	void DFScreateEdges();
};


#endif // !DFS_H
