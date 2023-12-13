#include <stack>
#include <queue>
#include <limits.h>
#include "../weighted_graph/graph.h"
#include "../shortest_path/shortest_path.h"

using namespace std;

typedef pair<int, int> iPair;

class DijkstraShortestPath : public ShortestPath {
    void shortestPath(int from) {
        bool* visited = new bool[graph.vertices()];
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        pq.push({0, from});

        while (!pq.empty()) {
            int v = pq.top().second;
            pq.pop();
            if (visited[v]) {
                continue;
            }
            visited[v] = true;
            for (WeightedEdge e : graph.adj(v)) {
                if (relax(e)) {
                    pq.push({distTo[e.to()], e.to()});
                }
            }
        }
    }

public:
    // Конструктор които приема претеглен граф и начален (source) връх
    DijkstraShortestPath(WeightedDirectedGraph graph, int from) : ShortestPath(graph, from) {
        shortestPath(from);
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
