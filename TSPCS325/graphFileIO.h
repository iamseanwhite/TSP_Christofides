#pragma once

#ifndef BUILD_GRAPH_H
#define BUILD_GRAPH_H

#include <vector>
#include <string>
#include "vertex.h"

std::vector<vertex> buildGraphFromFile(std::string filename);
void outputToFile(std::vector<vertex*> tspTour, int sum, std::string inputFileName);
int checkPreviousTour(std::string tourFileName);

#endif // !BUILD_GRAPH_H
