#include "vertex.h"
#include "mstPrim.h"
#include "graphFileIO.h"
#include "greedyOddMatching.h"
#include "eulerTour.h"
#include "twoOpt.h"
#include <iostream>

//#include "vertex.cpp"
//#include "mstPrim.cpp"
//#include "graphFileIO.cpp"
//#include "greedyOddMatching.cpp"
//#include "eulerTour.cpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {

	std::string inputFileName = argv[1];
	//std::string inputFileName = "tsp_example_2.txt";

	//To be altered for competition
	bool prevRun = false;

	std::vector<vertex> graph = buildGraphFromFile(inputFileName);
	mstPrim(graph);
	greedyOddMatching(graph);
	vertLink *tour = createEulerTour(graph);
	vertLink *itr = tour;
	std::vector<vertex*> tspTour;
	
	int presum = 0;
	for (vertex &v : graph)
		v.visited = false;
	while (itr != nullptr) {
		if (!itr->vert->visited) {
			itr->vert->visited = true;
			tspTour.push_back(itr->vert);
			if (tspTour.size() > 1 && itr->next != nullptr)
				presum += getDistance(tspTour[tspTour.size()-2], tspTour[tspTour.size()-1]);
		}
		itr = itr->next;
	}


	presum += getDistance(tspTour[tspTour.size()-1], tspTour[0]);
	

	//std::cout << "Before Opt: " << presum <<std::endl;

	//Perform 2OPT
	twoOpt(tspTour);
	//Sum after optimizaition
	presum = 0;
	for (int i = 0; i < tspTour.size(); i++) {
		if (i < tspTour.size() - 1) {
			presum += getDistance(tspTour[i], tspTour[i + 1]);
		}
	}
	presum += getDistance(tspTour[tspTour.size() - 1], tspTour[0]);


	outputToFile(tspTour, presum, inputFileName);

	//std::cout << "After Opt: " << presum << std::endl;
 	return 0;

}
