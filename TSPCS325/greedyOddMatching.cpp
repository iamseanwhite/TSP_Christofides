#include "vertex.h"

struct vertLink {
	struct vertex* vert;
	struct vertLink* next;
};

void greedyOddMatching(vector<vertex> &graph) {
	//Build the list of vertices with odd degree
	struct vertLink* head = nullptr;
	for (int i = 0; i < graph.size(); i++) {
		if (graph[i].edges.size() % 2 != 0) {
			struct vertLink *newLink = new vertLink;
			newLink->next = head;
			newLink->vert = &graph[i];
			head = newLink;
		}
	}

	//Match up links and remove them
	while (head != nullptr) {
		int minDist = std::numeric_limits<int>::max(),
			dist;
		struct vertLink* itr = head->next,
			*minVert = nullptr,
			*minVertPrev = nullptr,
			*prev = head,
			*garbage;
		//Examin the rest of the links to find the one with the min distance
		while (itr != nullptr) {
			dist = getDistance(head->vert, itr->vert);
			if (dist < minDist) {
				minDist = dist;
				minVert = itr;
				minVertPrev = prev;
			}
			prev = itr;
			itr = itr->next;
		}
		//Add the vertices to each others edge lists
		head->vert->edges.push_back(minVert->vert);
		minVert->vert->edges.push_back(head->vert);
		//Remove the vertices from the list
		minVertPrev->next = minVert->next;
		garbage = head;
		head = head->next;
		delete garbage;
		delete minVert;
		garbage = nullptr;
		minVert = nullptr;

	}
	
}