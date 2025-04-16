#include "labo.h"


AdjMatrix* create_graph(size_t max_nodes) {
    AdjMatrix* newMatrix = allocate(sizeof(AdjMatrix));

    newMatrix->len = 0;
    newMatrix->max_size = max_nodes;
    newMatrix->nodes = allocate(max_nodes * sizeof(Node));

    for (int i = 0; i < max_nodes; i++) {
        newMatrix->nodes[i].cost = UINT8_MAX;
        newMatrix->nodes[i].path_from = UINT8_MAX;
        newMatrix->nodes[i].visited = 0;
    }

    newMatrix->adjGraph = allocate(max_nodes * sizeof(int*));
    for (int i = 0; i < max_nodes; i++) {
        newMatrix->adjGraph[i] = allocate(max_nodes * sizeof(int));
        for (int j = 0; j < max_nodes; j++) {
            newMatrix->adjGraph[i][j] = 0;
        }
    }

    return newMatrix;
}

void add_node(AdjMatrix* graph, void* data) {
    graph->nodes[graph->len].data = data;
    graph->nodes[graph->len].cost = UINT8_MAX;
    graph->nodes[graph->len].visited = 0;
    graph->nodes[graph->len].path_from = UINT8_MAX;
    graph->len++;
}

void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost) {
	graph->adjGraph[fromNode][toNode] = cost;
}

void dijkstra(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath) {
    int currentNodeIndex = startNodeIndex;
    int targetNodeIndex = endNodeIndex;

    graph->nodes[startNodeIndex].visited = 1;
    graph->nodes[startNodeIndex].cost = 0;

    while (currentNodeIndex != targetNodeIndex) {
        Node* currentNode = &graph->nodes[currentNodeIndex];
        int nextNodeIndex = -1;
        uint8_t minCost = UINT8_MAX;

        for (int i = 0; i < graph->len; i++) {
            if (graph->adjGraph[currentNodeIndex][i] == 0 || graph->nodes[i].visited == 1) {
                continue;
            }

            uint8_t newCost = currentNode->cost + graph->adjGraph[currentNodeIndex][i];

            if (newCost < graph->nodes[i].cost) {
                graph->nodes[i].cost = newCost;
                graph->nodes[i].path_from = currentNodeIndex;
            }

            if (graph->nodes[i].cost < minCost) {
                minCost = graph->nodes[i].cost;
                nextNodeIndex = i;
            }
        }

        graph->nodes[currentNodeIndex].visited = 1;

        if (nextNodeIndex != -1) {
            currentNodeIndex = nextNodeIndex;
        }
        else {
            minCost = UINT8_MAX;
            for (int i = 0; i < graph->len; i++) {
                if (!graph->nodes[i].visited && graph->nodes[i].cost < minCost) {
                    minCost = graph->nodes[i].cost;
                    nextNodeIndex = i;
                }
            }
            if (nextNodeIndex == -1) {
                break; 
            }

            currentNodeIndex = nextNodeIndex;
        }
    }

    if (graph->nodes[endNodeIndex].cost != UINT8_MAX) {
        int current = endNodeIndex;
        while (current != startNodeIndex) {
            stack_push(solvedPath, &(graph->nodes[current]));
            current = graph->nodes[current].path_from;
        }

        stack_push(solvedPath, &(graph->nodes[startNodeIndex]));
    }
}