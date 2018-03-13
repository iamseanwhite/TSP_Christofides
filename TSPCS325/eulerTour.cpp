#include "eulerTour.h"
#include <vector>
#include <iostream>

void removeEdge(vertex *v1, vertex* v2) {
	for (auto itr = v2->edges.begin(); itr != v2->edges.end(); ++itr) {
		if (*itr == v1) {
			v2->edges.erase(itr);
			//Break to prevent the itr from exceeding the end of the vector
			break;
		}
	}
	for (auto itr = v1->edges.begin(); itr != v1->edges.end(); ++itr) {
		if (*itr == v2) {
			v1->edges.erase(itr);
			//Break to prevent the itr from exceeding the end of the vector
			break;
		}
	}
}

//This could be cleaned up but it works
vertLink* createEulerTour(std::vector<vertex> &graph) {

	//Reset all parent pointers
	for (vertex v : graph)
		v.parent = nullptr;

	//Initialize the tour
	vertLink *tourStart = new vertLink;
	vertLink *itr;
	vertLink *end = new vertLink;
	vertLink *next = nullptr;
	tourStart->vert = &graph[0];
	tourStart->next = end;
	tourStart->prev = nullptr;
	end->vert = tourStart->vert;
	end->next = nullptr;
	end->prev = tourStart;

	itr = tourStart;
	bool missedEdges = true;
	while (missedEdges) {

		//Complete a subtour
		int id = itr->vert->id;
		do {
				vertLink *nextLink = new vertLink;
				nextLink->vert = itr->vert->edges[0];
				nextLink->vert->parent = itr->vert;
				nextLink->prev = itr;
				nextLink->next = end;
				if (end != nullptr)
					end->prev = nextLink;
				itr->next = nextLink;
				removeEdge(itr->vert, nextLink->vert);
				itr = nextLink;
		} while (itr->vert->id != id);

		//Remove double Link
		vertLink *garbage = end->prev;
		garbage->prev->next = end;
		end->prev = garbage->prev;
		delete garbage;
		itr = end;

		//Walk back though the tour looking for missed edges
		missedEdges = false;
		while (itr != nullptr && !missedEdges) {
			if (itr->vert->edges.size() > 0) {
				end = new vertLink;
				end->next = itr->next;
				if (end->next != nullptr)
					end->next->prev = end;
				itr->next = end;
				end->prev = itr;
				end->vert = itr->vert;
				missedEdges = true;
			}
			else {
				next = itr;
				itr = itr->prev;
			}
		}


	}

	
	//Print for debugging and fun
	/*
	vertLink *printItr = tourStart;
	while (printItr != nullptr) {
		std::cout << printItr->vert->id << " ";
		printItr = printItr->next;
	}
	std::cout << std::endl;
	*/
	return next;

}


