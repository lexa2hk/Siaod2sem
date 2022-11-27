
//cmake_minimum_required(VERSION 3.23)
//project(Siaod2sem)
//
//set(CMAKE_CXX_STANDARD 23)
//add_executable(Siaod2sem Task6/main.cpp Task6/Graph.h Task6/Graph.cpp Task7/main.cpp)



#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

int main()
{
    system("chcp 65001");
    int n,a,b,w;

    cout<<"Лабораторная работа №6.'Графы'. Смольников Алексей. Вариант 22"<<endl;
    cout<<"Количество узлов: ";
    cin>>n;

    cout<<"Количество граней: ";
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
    cout<<"Нахождение мостов в графе: "<<endl;
    graph.findBridges();

    cout<<"Вывод списка смежных вершин"<<endl;
    graph.printGraphList();
    graph.toGraphviz("graph.gv");


    Graph graph2 = graph.Kruksal();
    graph2.toGraphviz("graphKruksal.gv");

    cout<<"Алгоритм Крускала: "<<endl;
    graph2.printTree();
    return 0;
}