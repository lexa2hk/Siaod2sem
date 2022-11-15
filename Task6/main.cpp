#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

int main()
{
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
    graph.toGraphviz("graphKruksal.gv");
    return 0;
}