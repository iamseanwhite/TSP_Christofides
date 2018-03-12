#include "vertex.h"
//#include "vertex.cpp"

int main() {

    vector<vertex> vertexList;

    vertex v1, v2, v3;

    v1.id = 0;
    v1.xCoord = 1;
    v1.yCoord = 1;
    v1.parent = NULL;
    v1.key = 0;

    v2.id = 1;
    v2.xCoord = 2;
    v2.yCoord = 1;
    v2.parent = NULL;

    v3.id = 2;
    v3.xCoord = 4;
    v3.yCoord = 1;
    v3.parent = NULL;

    vertexList.push_back(v1);
    vertexList.push_back(v2);
    vertexList.push_back(v3);

    //cout << vertexList[0].id << vertexList[0].xCoord;
    cout << getDistance(v1,v2) << "\n";

    vector<edge> MST = mstPrim(vertexList);

    for (int i = 0; i < MST.size(); i++){
    //for (edge e : MST) {
        cout << "From id: " << (*MST[i].from).id;
        cout << "\nTo id: " << (*MST[i].to).id;
        cout << "\nWeight: " << MST[i].weight << "\n\n";
    }

    char x;
    cin >> x;

}
