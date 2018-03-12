#include "vertex.h"
#include <cmath>

int getDistance(struct vertex *v1, struct vertex *v2) {
	return round(
		(long double) sqrt((pow(v1->xCoord - v2->xCoord, 2)) + (pow(v1->yCoord - v2->yCoord, 2)))
	);
}