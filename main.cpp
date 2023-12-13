#include <iostream>

#include "weighted_graph/graph.h"
#include "dijkstra/dijkstra.h"
#include "bellman_ford/bellman_ford.h"
#include "shortest_path/shortest_path.h"

WeightedDirectedGraph getFirst() {
    WeightedDirectedGraph graph = WeightedDirectedGraph(5);
    graph.addEdge(WeightedEdge(0, 1,  4));
    graph.addEdge(WeightedEdge(0, 3,  6));
    graph.addEdge(WeightedEdge(0, 4,  6));
    graph.addEdge(WeightedEdge(1, 2,  2));
    graph.addEdge(WeightedEdge(2, 0,  4));
    graph.addEdge(WeightedEdge(2, 3,  8));
    graph.addEdge(WeightedEdge(3, 4,  9));

    return graph;
}

WeightedDirectedGraph getGraph() {
    WeightedDirectedGraph graph = WeightedDirectedGraph(6);
    graph.addEdge(WeightedEdge(0, 1,  2));
    graph.addEdge(WeightedEdge(0, 2,  6));
    graph.addEdge(WeightedEdge(0, 3,  7));
    graph.addEdge(WeightedEdge(1, 3,  3));
    graph.addEdge(WeightedEdge(1, 4,  6));
    graph.addEdge(WeightedEdge(2, 4,  1));
    graph.addEdge(WeightedEdge(3, 4,  5));
    graph.addEdge(WeightedEdge(4, 5,  1));

    return graph;
}

WeightedDirectedGraph withNegativeWeight() {
    WeightedDirectedGraph graph = WeightedDirectedGraph(5);
    graph.addEdge(WeightedEdge(0, 1, 1));
    graph.addEdge(WeightedEdge(0, 2, 10));
    graph.addEdge(WeightedEdge(1, 3, 2 ));
    graph.addEdge(WeightedEdge(2, 3, -10));
    graph.addEdge(WeightedEdge(3, 4, 3));

    return graph;
}

WeightedDirectedGraph withNegativeCycle() {
    WeightedDirectedGraph graph = WeightedDirectedGraph(5);
    graph.addEdge(WeightedEdge(0, 1, 99));
    graph.addEdge(WeightedEdge(0, 4, -99));
    graph.addEdge(WeightedEdge(1, 2, 15));
    graph.addEdge(WeightedEdge(2, 1, -42));
    graph.addEdge(WeightedEdge(2, 3, 10));

    return graph;
}

int main() {

    ShortestPath dijkstraSP = DijkstraShortestPath(getGraph(), 0);
    cout << "Dijkstra paths"  << "\n";
    cout << dijkstraSP.distance(1) << "\n";
    cout << dijkstraSP.distance(2) << "\n";
    cout << dijkstraSP.distance(3) << "\n";
    cout << dijkstraSP.distance(4) << "\n";

    dijkstraSP.printPathTo(3);
    dijkstraSP.printPathTo(4);

    cout << "Bellman Ford paths"  << "\n";
    ShortestPath bellmanFordSP = BellmanFordShortestPath(getGraph(), 0);
    cout << bellmanFordSP.distance(1) << "\n";
    cout << bellmanFordSP.distance(2) << "\n";
    cout << bellmanFordSP.distance(3) << "\n";
    cout << bellmanFordSP.distance(4) << "\n";

    bellmanFordSP.printPathTo(3);
    bellmanFordSP.printPathTo(4);

    cout << "Bellman Ford cycle detection"  << "\n";
    BellmanFordShortestPath bellmanFordSPNoCycle = BellmanFordShortestPath(withNegativeWeight(), 0);
    cout << bellmanFordSPNoCycle.hasNegativeCycle() << "\n";
    BellmanFordShortestPath bellmanFordSPCycle = BellmanFordShortestPath(withNegativeCycle(), 0);
    cout << bellmanFordSPCycle.hasNegativeCycle() << "\n";

    return 0;
}
