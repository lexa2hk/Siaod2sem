#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

int main()
{
    system("chcp 65001");
    int n,a,b,w;
    cout<<"Vertex count: ";
    cin>>n;

    cout<<"Edge count: ";
    int e;
    cin>>e;

    Graph graph(n);

    for (int i=0;i<e;i++)
    {
        cin>>a;
        cin>>b;
        cin>>w;
        graph.addEdge(a,b,w);

    }
    graph.findBridges();
    graph.printGraphList();
    graph.toGraphviz("graph.gv");

    Graph graph2 = graph.Kruksal();
    graph2.toGraphviz("graphKruksal.gv");


    graph2.printTree();
    return 0;
}