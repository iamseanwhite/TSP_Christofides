#include "vertex.h"
//#include "vertex.cpp"

int main() {

    vector<vertex> vertexList;

    vertex v1, v2;

    v1.id = 0;
    v1.xCoord = 1;
    v1.yCoord = 1;
    v1.parent = NULL;
    v1.key = 0;

    v2.id = 1;
    v2.xCoord = 2;
    v2.yCoord = 1;
    v2.parent = NULL;

    vertexList.push_back(v1);
    vertexList.push_back(v2);

    //cout << vertexList[0].id << vertexList[0].xCoord;
    cout << getDistance(v1,v2) << "\n";

    vector<edge> MST = mstPrim(vertexList, vertexList[0]);

    for (edge e : MST) {
        cout << "From: " << e.from->id; //<< "\nTo: " << e.to->id << "\nWeight: " << e.weight;
    }

    char x;
    cin >> x;

}
