#pragma once

#include <vector>

using namespace std;

// Клас описващ начален, краен връх и тегло на ребро в претеглен граф
class WeightedEdge {
    int v, u, w;
public:
    WeightedEdge(int from, int to, int weight) : v(from), u(to), w(weight) {}
    int from() { return v;}
    int to() {return u;}
    int weight() {return w;}
};


// Реализация на насочен претеглен граф със списък на съседите (adjacency list)
class WeightedDirectedGraph {
    int numVertices;
    vector<WeightedEdge> *adjList;
public:
    WeightedDirectedGraph(int V): numVertices(V), adjList(new vector<WeightedEdge>[V]) {}
    // добавя ребро със съответното му тегло м/у два върха
    void addEdge(WeightedEdge edge) { adjList[edge.from()].push_back(edge);}
    // Връща списък с всички върхове съседни на v
    vector<WeightedEdge> adj(int v) { return adjList[v];}
    // Връща броят върхове в графа
    int vertices() { return numVertices;}
};