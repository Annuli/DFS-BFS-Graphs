#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <list>
#include <vector>

class BFS_Graph {

private:
	// Number of vertices
	int vertices;

	// Pointer to list of vertices (adjacency list)
	std::vector<std::list<int>> adjacency;

public:
	// Constructors
	BFS_Graph();
	BFS_Graph(int v);

	// Destructor
	~BFS_Graph();

	// Method to add an edge
	void addEdge(int vertices, int edges);

	// Method for BFS traversal given a data point and array
	void BFS(std::string *city, int dataPoint);

	// Create 'edges' to be used for DFS traversal
	void BFScreateEdges();

};

#endif // !BFS_H

