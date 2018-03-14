#include "twoOpt.h"
#include <iostream>

void reverse(int start, int end, std::vector<vertex*> &graph) {
	while (start < end) {
		vertex* temp = graph[start];
		graph[start] = graph[end];
		graph[end] = temp;
		start++;
		end--;
	}

}

void twoOpt(std::vector<vertex*> &tour) {

	int edgeAVert1 = 0, 
		edgeAVert2 = 1,
		edgeBVert1,
		edgeBVert2;

	//Loop through the array and if a distanace can be shortened do so
	while (edgeAVert2 < tour.size()) {

		edgeBVert1 = 0;
		edgeBVert2 = 1;

		while (edgeBVert2 < tour.size()) {
			//Make sure the edges are mutually disjoint
			if (edgeAVert1 != edgeBVert1 &&
				edgeAVert1 != edgeBVert2 &&
				edgeAVert2 != edgeBVert1 &&
				edgeAVert2 != edgeBVert2) {

				//Check to see if swapping edges will improve the distance
				if ((getDistance(tour[edgeAVert1], tour[edgeAVert2]) + getDistance(tour[edgeBVert1], tour[edgeBVert2])) >
					(getDistance(tour[edgeAVert1], tour[edgeBVert1]) + getDistance(tour[edgeAVert2], tour[edgeBVert2]))) {

					//If edgeA is before edgeB
					if (edgeAVert1 < edgeBVert2) {
						//Reverse the elements from edgeAVert2 to edgeBVert1
						reverse(edgeAVert2, edgeBVert1, tour);
					}
					else {
						//Reverse the elements from edgeBVert2 to edgeAVert1
						reverse(edgeBVert2, edgeAVert1, tour);
					}
				}
			}
			edgeBVert1++;
			edgeBVert2++;
		}

		edgeAVert1++;
		edgeAVert2++;
	}
	

}