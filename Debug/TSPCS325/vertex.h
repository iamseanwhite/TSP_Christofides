#pragma once
#ifndef VERT_H
#define VERT_H

#include <vector>
using std::vector;

struct vertex {
	int id,
		xCoord,
		yCoord,
		key;
	struct vertex *parent;
	bool visited = false;
	std::vector<vertex*> edges;
};

struct edge {
	struct vertex* from;
	struct vertex* to;
	int weight;
};

int getDistance(struct vertex *v1, struct vertex *v2);
#endif