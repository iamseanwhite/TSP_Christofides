#include "vertex.h"

int getDistance(struct vertex v1, struct vertex v2){

    return round(sqrt((pow(v1.xCoord - v2.xCoord, 2)) + (pow(v1.yCoord - v2.yCoord, 2))));

}

vector<edge> mstPrim(vector<vertex> vertexList, vertex root) {

    vector<vertex> Q = vertexList;

    //set keys to infinity and parents to null
    int inf = numeric_limits<int>::max();
    for (int i = 1; i < Q.size(); i++) {
    //for (vertex v : Q) {
        Q[i].key = inf;
        Q[i].parent = NULL;
        //cout << v.key << "\n";
    }

    //root.key = 0;


    //vector<vertex> vertex_MST;
    vector<edge> edge_MST;
    vertex u;
    while (Q.size() != 0) {

        //extract min
        int min = inf;
        int counter = 0;
        int placeHolder;
        for (vertex v : Q) {
            if (v.key < min) {
                min = v.key;
                u = v;
                placeHolder = counter;
            }
            counter++;
        }
        Q.erase(Q.begin() + placeHolder);

        if (u.key != 0) {   //if not the root
            edge e = {
                u.parent,  //from
                &u,         //to
                u.key,      //weight
            };

            edge_MST.push_back(e);
        }

        //adjacency list of u is all vertices because complete graph
        for (int i = 0; i < Q.size(); i++) {
        //for (vertex v : Q) {

            //if distance is better than before
            if (getDistance(u,Q[i]) < Q[i].key) {
                Q[i].parent = &u;
                //vertexList[i].parent = &u;
                Q[i].key = getDistance(u,Q[i]);
                //vertexList[i].key = getDistance(u,Q[i]);
            }

        }

    }
   /*
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
    */
    return edge_MST;

}



