#include "mstPrim.h"
#include <queue>
#include <limits>
#include <climits>
#include <cstdlib>
#include <ctime>

void mstPrim(std::vector<vertex> &graph) {
	//Create priority queue for the vertices based on http://en.cppreference.com/w/cpp/container/priority_queue
	auto cmp = [](vertex* LHS, vertex* RHS) {return LHS->key > RHS->key; };
	std::priority_queue<vertex*, std::vector<vertex*>, decltype(cmp) > vertexQueue(cmp);
	
	int startIndex = 0;
	graph[startIndex].key = 0;
	graph[startIndex].visited = true;
	for (int i = 1; i < graph.size(); i++) {
		int dist = getDistance(&graph[startIndex], &graph[i]);
		if (dist < graph[i].key && &graph[startIndex] != &graph[i]) {
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
/*
vector<edge> mstPrim(vector<vertex> &vertexList) {

	vector<vertex> Q = vertexList;

	//set keys to infinity and parents to null
	int inf = std::numeric_limits<int>::max();
	for (int i = 1; i < Q.size(); i++) {
		//for (vertex v : Q) {
		Q[i].key = inf;
		vertexList[i].key = inf;
		Q[i].parent = nullptr;
		vertexList[i].parent = nullptr;
		//cout << v.key << "\n";
	}

	//root.key = 0;


	//vector<vertex> vertex_MST;
	vector<edge> edge_MST;
	vertex u;
	vertex* addressOfu;
	while (Q.size() != 0) {

		//extract min
		int min = inf;
		int counter = 0;
		int placeHolder;
		for (vertex v : Q) {
			if (v.key < min) {
				min = v.key;
				u = v;
				for (int i = 0; i < vertexList.size(); i++) {
					//for (vertex ver : vertexList) {
					if (vertexList[i].id == v.id)
						addressOfu = &vertexList[i];
				}
				placeHolder = counter;
			}
			counter++;
		}
		Q.erase(Q.begin() + placeHolder);
		/*
		if (u.key != 0) {   //if not the root
		edge e = {
		u.parent,  //from
		&u,         //to
		u.key,      //weight
		};

		edge_MST.push_back(e);
		}
		*/
/*
		//adjacency list of u is all vertices because complete graph
		for (int i = 0; i < vertexList.size(); i++) {
			//for (vertex v : Q) {

			//if also in Q
			for (int j = 0; j < Q.size(); j++) {

				if (Q[j].id == vertexList[i].id) {

					//if distance is better than before
					if (getDistance(u, vertexList[i]) < vertexList[i].key) {
						vertexList[i].parent = addressOfu;
						Q[j].parent = addressOfu;
						vertexList[i].key = getDistance(u, vertexList[i]);
						Q[j].key = getDistance(u, vertexList[i]);

						break;
					}

				}

			}

		}

	}

	//build and place edge into MST
	for (int i = 0; i < vertexList.size(); i++) {
		//for (vertex v : vertexList) {
		if (vertexList[i].key != 0) {   //if not the root
			edge e = {
				vertexList[i].parent,  //from
				&vertexList[i],         //to
				vertexList[i].key,      //weight
			};

			edge_MST.push_back(e);
		}
	}

	return edge_MST;

}
*/