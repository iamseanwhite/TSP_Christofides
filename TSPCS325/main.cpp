#include "vertex.h"
#include "mstPrim.h"
#include "graphFileIO.h"
#include "greedyOddMatching.h"
#include "eulerTour.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {



	std::vector<vertex> graph = buildGraphFromFile("test-input-7.txt");
	mstPrim(graph);
	greedyOddMatching(graph);
	vertLink *tour = createEulerTour(graph);
	vertLink *itr = tour;
	std::vector<vertex*> tspTour;
	for (vertex &v : graph)
		v.visited = false;
	while (itr != nullptr) {
		if (!itr->vert->visited) {
			itr->vert->visited = true;
			tspTour.push_back(itr->vert);
		}
		itr = itr->next;
	}

	//For Testing
	for (vertex &v : graph)
		v.visited = false;

	int sum = 0;
	for (int i = 0; i < tspTour.size(); i++) {
		if (i < tspTour.size() - 1) {
			std::cout << tspTour[i]->id << std::endl;
			sum += getDistance(tspTour[i], tspTour[i + 1]);
			tspTour[i]->visited = true;
		}
		else {
			tspTour[i]->visited = true;
			sum += getDistance(tspTour[i], tspTour[0]);
		}
	}

	for (vertex v : graph) {
		if (!v.visited) {
			std::cout << "Fail ID: " << v.id << std::endl;
		}
	}

	std::cout << sum << std::endl;

 	return 0;

}
