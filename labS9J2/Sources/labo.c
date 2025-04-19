#include "labo.h"


AdjMatrix* create_graph(size_t max_nodes)
{
	AdjMatrix* graph = (AdjMatrix*)allocate(sizeof(AdjMatrix));
	graph->len = 0;
	graph->max_size = max_nodes;

	graph->nodes = (Node*)allocate(max_nodes * sizeof(Node));

	for (size_t i = 0; i < max_nodes; i++) {
		graph->nodes[i].cost = UINT8_MAX;
		graph->nodes[i].path_from = UINT8_MAX;
		graph->nodes[i].visited = 0;
		graph->nodes[i].data = NULL;

	}
	graph->adjGraph = (int**)allocate(max_nodes * sizeof(int*));
	for (size_t i = 0; i < max_nodes; i++) {
		graph->adjGraph[i] = (int*)allocate(max_nodes * sizeof(int));
		for (size_t j = 0; j < max_nodes; j++) {
			graph->adjGraph[i][j] = 0;
		}
	}
	return graph;
}

void add_node(AdjMatrix* graph, void* data)
{
	if (graph->len >= graph->max_size) {
		return;
	}
	graph->nodes[graph->len].data = data;
	graph->nodes[graph->len].cost = UINT8_MAX;
	graph->nodes[graph->len].path_from = UINT8_MAX;
	graph->nodes[graph->len].visited = 0;

	graph->len++;

}

void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost)
{
	if (fromNode >= (int)graph->len || toNode >= (int)graph->len) {
		return;
	}
	graph->adjGraph[fromNode][toNode] = cost;
}

void dijkstra(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath)
{
	if (startNodeIndex < 0 || startNodeIndex >= (int)graph->len ||
		endNodeIndex < 0 || endNodeIndex >= (int)graph->len) {
		return;
	}
	for (size_t i= 0; i < graph->len; i++) {
		graph->nodes[i].cost = UINT8_MAX;
		graph->nodes[i].visited= 0;
		graph->nodes[i].path_from = UINT8_MAX;
	}
	graph->nodes[startNodeIndex].cost = 0;
}