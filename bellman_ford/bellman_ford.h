#include <stack>
#include <queue>
#include <limits.h>
#include "../weighted_graph/graph.h"
#include "../shortest_path/shortest_path.h"

using namespace std;

class BellmanFordShortestPath : public ShortestPath {
    void shortestPath() {
        // Bellman Ford's routine, basically = relax all E edges V-1 times
        for (int i = 0; i < graph.vertices() - 1; ++i) {
            for (int v = 0; v < graph.vertices(); ++v) {
                if (distTo[v] != INT_MAX) {
                    for (WeightedEdge e: graph.adj(v)) {
                        relax(e);
                    }
                }
            }
        }
    }
public:
    // Конструктор които приема претеглен граф и начален (source) връх
    BellmanFordShortestPath(WeightedDirectedGraph graph, int from) : ShortestPath(graph, from) {
        shortestPath();
    }

    bool hasNegativeCycle() {
        // Максималният възможен път при отсъствие на негативен цикъл е V-1.
        // За да проверим за негативен цикъл просто изпълняваме релаксацията за всички върхове още веднъж.
        // Ако засечем промяна - означава че имаме път V, което не е възможно => имаме негативен цикъл
        for (int v = 0; v < graph.vertices(); ++v)
            for (WeightedEdge e: graph.adj(v))
                if (relax(e))
                    return true;

        return false;
    }
};
