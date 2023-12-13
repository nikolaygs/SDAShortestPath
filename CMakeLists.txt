cmake_minimum_required(VERSION 3.26)
project(SDA_ShotestPath)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDA_ShotestPath main.cpp
        weighted_graph/graph.h
        shortest_path/shortest_path.h
        dijkstra/dijkstra.h
        bellman_ford/bellman_ford.h
        shortest_path_dag/DAGShortestPath.h)
