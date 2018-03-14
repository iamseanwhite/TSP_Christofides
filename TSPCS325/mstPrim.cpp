#include "mstPrim.h"
#include <queue>
#include <limits>
#include <climits>
#include <cstdlib>
#include <ctime>

void mstPrim(std::vector<vertex> &graph, int startVert) {
	//Create priority queue for the vertices based on http://en.cppreference.com/w/cpp/container/priority_queue
	auto cmp = [](vertex* LHS, vertex* RHS) {return LHS->key > RHS->key; };
	std::priority_queue<vertex*, std::vector<vertex*>, decltype(cmp) > vertexQueue(cmp);
	
	srand(time(NULL));

	int startIndex = startVert;
	//int startIndex = rand() % graph.size();
	graph[startIndex].key = 0;
	graph[startIndex].visited = true;
	for (int i = 0; i < graph.size(); i++) {
		int dist = getDistance(&graph[startIndex], &graph[i]);
		if (!graph[i].visited) {
			graph[i].key = dist;
			graph[i].parent = &graph[startIndex];
			vertexQueue.push(&graph[i]);
		}
	}
	
	while (!vertexQueue.empty()) {
		vertex* u = vertexQueue.top();
		vertexQueue.pop();
		//If u has not be visited
		if (!u->visited) {
			//Add u and its parent to each others edge list
			u->parent->edges.push_back(u);
			u->edges.push_back(u->parent);
			//Set it as visited
			u->visited = true;
			//Examine all edges adjacent to u and if traveling from u to them will
			//decrease their key and they are already not part of the tree
			//Update their weight and add to the queue
			for (int i = 0; i < graph.size(); i++) {
				int dist = getDistance(u, &graph[i]);
				if (dist < graph[i].key && u != &graph[i]) {
					graph[i].key = dist;
					graph[i].parent = u;
					vertexQueue.push(&graph[i]);
				}
			}
		}
	}
}
