//
// Created by lexa2k on 15.11.2022.
//

#ifndef SIAOD2SEM_GRAPH_H
#define SIAOD2SEM_GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// По заданию гарантируется, что вершины нащзываются от 0 до n-1,
// а при создании графа мы создаем n вершин, так что оператор индексирования работает корректно

class Graph {
    struct edge{
        int vertexEdge;
        int weight;
    };

    struct adjacent{
        int vertex;
        vector<edge> edges;
    };

    int size=0;
    vector<adjacent> graph = vector<adjacent>(0);

public:
    Graph(int size);
    void addEdge(int vertex1, int vertex2, int weight);
    void printGraphList();
    void findBridges();
    void dfs(int v, vector<bool> &visited, vector<int> &timeIn, vector<int> &fup, vector<int> &parent, int &timer);

    Graph Kruksal();

    void toGraphviz(std::string filename);
};


#endif //SIAOD2SEM_GRAPH_H
