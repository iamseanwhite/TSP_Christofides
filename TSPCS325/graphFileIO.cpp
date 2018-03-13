#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include "graphFileIO.h"

std::vector<vertex> buildGraphFromFile(std::string filename) {
	std::vector<vertex> graph;
	std::ifstream inFile;
	std::string curLine;
	inFile.open(filename);
	if (inFile) {
		while (std::getline(inFile, curLine)) {
			vertex newVert;
			std::istringstream vertData(curLine);
			vertData >> newVert.id;
			vertData >> newVert.xCoord;
			vertData >> newVert.yCoord;
			newVert.parent = nullptr;
			newVert.key = std::numeric_limits<int>::max();
			newVert.visited = false;
			graph.push_back(newVert);
		}
	}
	return graph;
}

void outputToFile(std::vector<vertex*> tspTour, int presum, std::string inputFileName) {

	std::ofstream outputFile;
	outputFile.open(inputFileName + ".tour");

	outputFile << presum << "\n";
	//std::cout << presum << "\n";

	for (vertex *v : tspTour) {
		outputFile << v->id << "\n";
		//std::cout << v->id << "\n";
	}

	outputFile.close();


}