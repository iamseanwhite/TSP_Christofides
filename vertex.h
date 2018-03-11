#ifndef VERTEX_H_
#define VERTEX_H_

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

struct vertex {
    int id, xCoord, yCoord;
    struct vertex* parent;
};

int getDistance(struct vertex v1, struct vertex v2);

#endif
