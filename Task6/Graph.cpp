//
// Created by lexa2k on 15.11.2022.
//

#include "Graph.h"

Graph::Graph(int size) {
    this->size = size;
    for (int i = 0; i < size; ++i) {
        adjacent adjacent1;
        adjacent1.vertex = i;
        graph.push_back(adjacent1);
    }
}

void Graph::addEdge(int vertex1, int vertex2, int weight) {

    if(vertex1>=size || vertex2>=size){
        cerr<<"Error: vertex out of range"<<endl;
        return;
    }

    edge newEdge;
    newEdge.vertexEdge = vertex2;
    newEdge.weight = weight;

    if(vertex1!=vertex2){
        edge newEdge2;
        newEdge2.vertexEdge = vertex1;
        newEdge2.weight = weight;
        graph[vertex2].edges.push_back(newEdge2);
    }

    graph[vertex1].edges.push_back(newEdge);

}

void Graph::printGraphList() {
    for (int i = 0; i < graph.size(); ++i) {
        cout << graph[i].vertex << ": ";
        for (int j = 0; j < graph[i].edges.size(); ++j) {
            cout << graph[i].edges[j].vertexEdge << "(" << graph[i].edges[j].weight << ") ";
        }
        cout << endl;
    }
}


//https://e-maxx.ru/algo/bridge_searching
//https://e-maxx.ru/algo/dfs
void Graph::findBridges() {
    vector<int> timeIn(size, -1);
    vector<int> fup(size, -1);
    vector<bool> visited(size, false);
    vector<int> parent(size, -1);
    int timer = 0;

    for (int i = 0; i < size; ++i) {
        if (!visited[i]) {
            dfs(i, visited, timeIn, fup, parent, timer);
        }
    }
}

void Graph::dfs(int v, vector<bool> &visited, vector<int> &timeIn, vector<int> &fup, vector<int> &parent, int &timer){
    visited[v] = true;
    timeIn[v] = fup[v] = timer++;
    for (int i = 0; i < graph[v].edges.size(); ++i) {
        int to = graph[v].edges[i].vertexEdge;
        if (to == parent[v]) {
            continue;
        }
        if (visited[to]) {
            fup[v] = min(fup[v], timeIn[to]);
        } else {
            parent[to] = v;
            dfs(to, visited, timeIn, fup, parent, timer);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > timeIn[v]) {
                cout<<"BRIDGE "<< v << " " << to << endl;
            }
        }
    }
}

Graph Graph::Kruksal() {

}

void Graph::toGraphviz(std::string filename) {
    ofstream file;
    file.open(filename);
    file << "digraph G {" << endl;
    file << "layout=circo;"<<endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < graph[i].edges.size(); ++j) {
            file << graph[i].vertex << " -> " << graph[i].edges[j].vertexEdge << " [label=" << graph[i].edges[j].weight << "]" << endl;
        }
    }
    file << "}";
    file.close();
}
