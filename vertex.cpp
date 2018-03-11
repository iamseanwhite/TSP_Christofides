#include "vertex.h"

int getDistance(struct vertex v1, struct vertex v2){

    return round(sqrt((pow(v1.xCoord - v2.xCoord, 2)) + (pow(v1.yCoord - v2.yCoord, 2))));

}

int mstPrim(vector<vertex> vertexList, vertex root) {

    //set keys to infinity and parents to null
    for (vertex v : vertexList) {
        int inf = numeric_limits<int>::max();
        v.key = inf;
        v.parent = NULL;
        //cout << v.key << "\n";
    }

    root.key = 0;
    vector<vertex> Q = vertexList;

    //vector<vertex> vertex_MST;
    vector<edge> edge_MST;

    while (Q.size() != 0) {

        //extract min
        int min = inf;
        vertex u;
        for (vertex v : Q) {
            if (v.key < min) {
                min = v.key;
                u = v;
            }
        }
        Q.erase(v);

        //build and place edge into MST
        if (u.key != 0) {   //if not the root
            edge e = {
                &u.parent,  //from
                &u,         //to
                u.key,      //weight
            };

            edge_MST.push_back(e);
        }

        //adjacency list of u is all vertices because complete graph
        for (vertex v : vertexList) {

            //if in Q
            if (find(Q.begin(), Q.end(), v) != Q.end()) {

                //and distance is better than before
                if (getDistance(u,v) < v.key) {
                    v->parent = &u;
                    v.key = getDistance(u,v);
                }
            }
        }


    }

}



