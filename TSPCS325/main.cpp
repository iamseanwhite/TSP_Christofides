#include "vertex.h"
#include "mstPrim.h"
#include "graphFileIO.h"
#include "greedyOddMatching.h"
#include "eulerTour.h"
#include "twoOpt.h"
#include <iostream>
#include <limits>
#include <ctime>

//#include "vertex.cpp"
//#include "mstPrim.cpp"
//#include "graphFileIO.cpp"
//#include "greedyOddMatching.cpp"
//#include "eulerTour.cpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {

	std::clock_t start = clock();
	double time = 0;

	std::string inputFileName;
	if (argc == 2) {
		inputFileName = argv[1];
	}
	//For testing
	else {
		inputFileName = "tsp_example_2.txt";
	}
	

	//To be altered for competition
	bool prevRun = false;


	std::vector<vertex> graph = buildGraphFromFile(inputFileName);

	for (int i = 0; i < graph.size(); i++) {
		//Reset Graph
		for (vertex &v : graph) {
			v.parent = nullptr;
			v.key = std::numeric_limits<int>::max();
			v.visited = false;
			v.edges.clear();
		}

		mstPrim(graph, i);
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

		//Perform 2OPT
		twoOpt(tspTour);
		//Sum after optimizaition
		int presum = 0;
		for (int i = 0; i < tspTour.size(); i++) {
			if (i < tspTour.size() - 1) {
				presum += getDistance(tspTour[i], tspTour[i + 1]);
			}
		}
		presum += getDistance(tspTour[tspTour.size() - 1], tspTour[0]);

		//If there is no previous run then write current run to file.
		if (!prevRun) {
			prevRun = true;
			outputToFile(tspTour, presum, inputFileName);
		}
		//Otherwise check to see if this run is shorter.
		//If it is write to file
		else {
			if (presum < checkPreviousTour(inputFileName)) {
				outputToFile(tspTour, presum, inputFileName);
			}
		}

		//Comment this out if going for absolute optimum
		//Time to kill program if it is going too long
		clock_t finish = clock();
		time = ((finish - start) / (double)CLOCKS_PER_SEC);
		if (time > 170) {
			break;
		}

	}

	//std::cout << time << std::endl;

 	return 0;

}
