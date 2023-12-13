#include <stack>
#include <queue>
#include <limits.h>
#include "../weighted_graph/graph.h"
#include "../shortest_path/shortest_path.h"

using namespace std;

class DAGShortestPath : public ShortestPath {
    void dfs(WeightedDirectedGraph graph, int v, bool* visited, stack<int> topoOrder) {
        visited[v] = true;
        for (WeightedEdge e : graph.adj(v)) {
            if (!visited[e.to()]) {
                dfs(graph, e.to(), visited, topoOrder);
            }
        }
        topoOrder.push(v); // пазим върховете в обратния ред на посещение
    }

    stack<int> topoSort(WeightedDirectedGraph graph) {
        stack<int> topoOrder = stack<int>();
        bool* visited = new bool[graph.vertices()];
        for (int i = 0; i < graph.vertices(); i++) {
            if (!visited[i]) {
                dfs(graph, i, visited, topoOrder);
            }
        }
    }

    void shortestPath(WeightedDirectedGraph graph) {
        stack<int> topoOrder = topoSort(graph);
        while(!topoOrder.empty()) {
            int v = topoOrder.top();
            topoOrder.pop();

            for (WeightedEdge e : graph.adj(v)) {
                relax(e);
            }
        }
    }

public:
    // Конструктор които приема претеглен граф и начален (source) връх
    DAGShortestPath(WeightedDirectedGraph graph, int from) : ShortestPath(graph, from) {
        shortestPath(graph);
    }

};
