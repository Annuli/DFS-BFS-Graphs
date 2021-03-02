#include "DFS.h"
#include "BFS.h"

#include <string>
#include <iostream>
#include <conio.h>

int main() {

	const int TOTAL_VERTICES = 12;
	char differentDataSet = 'Y';
	int startingVertex = -1;

	// Populate the array with data needed for the graph
	std::string cityVertices[TOTAL_VERTICES] = { "Seattle", "San Francisco", "Los Angeles", "Denver", "Kansas City", "Chicago", "Boston", "New York City", "Atlanta", "Miami", "Dallas", "Houston" };

	// Create objects of the two classes
	DFS_Graph DFS_graph(TOTAL_VERTICES);
	BFS_Graph BFS_graph(TOTAL_VERTICES);

	// Create the graph with the given data
	DFS_graph.DFScreateEdges();
	BFS_graph.BFScreateEdges();

	// Create heading
	std::cout << "\n* * Graph Traversals * *" << std::endl;

	// Use while loop to carry process forward
	while (differentDataSet == 'Y' || differentDataSet == 'y') {

		// Get information from user
		std::cout << "Enter starting city using number from 0 - 11: ";
		std::cin >> startingVertex;

		// Let user know which city they are starting at
		std::cout << "\nYou entered city name: " << cityVertices[startingVertex];

		// Display the beginning output for the DFS and BFS
		std::cout << "\n\nStarting with " << cityVertices[startingVertex] << ", " << "the cities in a depth-first search order: \n";
		DFS_graph.DFS(cityVertices, startingVertex);

		std::cout << "\n\nStarting with " << cityVertices[startingVertex] << ", " << "the cities in a breadth-first search order: \n";
		BFS_graph.BFS(cityVertices, startingVertex);

		// Ask if the user wants to try again
		std::cout << "\nWant to start from a different city? (Y/N): ";
		std::cin >> differentDataSet;

		// Decide if user wishes to continue
		if (differentDataSet == 'Y' || differentDataSet == 'y')
			continue;
		else
			std::cout << "\nThanks for playing!!" << std::endl;
	}
	_getch();
	return 0;
}




