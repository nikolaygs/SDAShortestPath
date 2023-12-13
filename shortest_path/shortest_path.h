#pragma once

#include <stack>
#include "../weighted_graph/graph.h"

class ShortestPath {
protected:
    WeightedDirectedGraph graph;
    int* distTo;
    int* edgeTo;

    bool relax(WeightedEdge e) {
        int v = e.from(); int u = e.to();
        int currentPathDistance = distTo[v] + e.weight();
        if (distTo[u] > currentPathDistance) {
            distTo[u] = currentPathDistance;
            edgeTo[u] = e.from();
            return true;
        }
        return false;
    }

public:
    // Конструктор които приема претеглен граф и начален (source) връх
    ShortestPath(WeightedDirectedGraph graph, int from) : graph(graph) {
        distTo = new int[graph.vertices()];
        edgeTo = new int[graph.vertices()];
        for (int i = 0; i < graph.vertices(); i++) {
            distTo[i] = INT_MAX;
        }
        distTo[from] = 0;
    }

    // връща разстоянието от началния връх до 'to'
    int distance(int to) {
        return distTo[to];
    }

    void printPathTo(int w) {
        // ще получим пътя в обратен ред, затова ще ползваме стек
        stack<int> path;
        while (true) {
            path.push(w);
            w = edgeTo[w];
            if (w == edgeTo[w]) {
                path.push(w);
                break;
            }
        }

        // печатаме пътя до съответния връх
        while(!path.empty()) {
            cout << path.top();
            path.pop();
            if (path.size() > 0) {
                cout << "->";
            }
        }
        cout << "\n";
    }
};