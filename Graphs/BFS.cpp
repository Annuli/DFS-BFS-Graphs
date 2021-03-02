#include "BFS.h"

#include <iostream>
#include <string>
#include <list>
#include <queue>


// Default constructor
BFS_Graph::BFS_Graph() {}

// Constructer with vertices, list
BFS_Graph::BFS_Graph(int v) {

	// Set the number of vertices
	vertices = v;

	// Resize the number of adjaceny lists
	adjacency.resize(v);
}

// Destructor
BFS_Graph::~BFS_Graph() {}

// Implementation to add edges
void BFS_Graph::addEdge(int vertices, int edges) {

	adjacency[vertices].push_back(edges);
}

// Look for data points; mark when found
void BFS_Graph::BFS(std::string *city, int dataPoint) {

	// Use static counter to clarify display
	static int BFScounter = 0;

	// Start with all vertices as not visited
	std::vector<bool> visited(vertices);

	// Create a queue for the BFS traversal
	std::list<int> queue;

	// Display the first city before being moved to back of queue
	std::cout << BFScounter << ". " << city[dataPoint] << std::endl;
	++BFScounter;

	// Mark the vertex as visited and add to the queue
	visited[dataPoint] = true;
	queue.push_back(dataPoint);

	// Continue with queue traversal until the queue is empty
	while (!queue.empty()) {

		// Pop the front of the queue
		dataPoint = queue.front();
		queue.pop_front();

		// Locate all adjacent vertices from the data point
		for (auto i : adjacency[dataPoint]) {

			// Look for vertices not yet visited
			if (!visited[i]) {
				std::cout << BFScounter << ". " << city[i] << std::endl;

				// Update the counter
				++BFScounter;

				// Mark data point as visited
				visited[i] = true;

				// Push back to check data point's adjacent vertices
				queue.push_back(i);
			}
		} // WHERE IS BEST PLACE TO DEQUEUE??
	}
	// Reset the BFS counter
	BFScounter = 0;
}

// Create 'edges' to be used for BFS traversal
void BFS_Graph::BFScreateEdges() {

	// Create 'edges' to be used for DFS traversal

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