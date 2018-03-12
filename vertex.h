#ifndef VERTEX_H_
#define VERTEX_H_

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <limits>

using namespace std;

struct vertex {
    int id, xCoord, yCoord, key;
    struct vertex* parent;
};

struct edge {
    struct vertex* from;
    struct vertex* to;
    int weight;
};

int getDistance(struct vertex v1, struct vertex v2);
vector<edge> mstPrim(vector<vertex> &vertexList);

#endif
