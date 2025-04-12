#include "labo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



/*
* Creer une matrice d'adjacence.
* Mettre len a 0. Mettre max_size a max_nodes.
* Allouer de la memoire pour le max de noeud specifier i.e. pour graph->nodes.
* Pour chaque noeud de graph->nodes mettre le cost et path_from a UINT8_MAX et visited a 0.
* Pour adjGraph, allouer une quantiter de int* relatif a la valeur de max_nodes.
* Dans chaque int* allouer un tableau de int relatif a la valeur max_nodes.
* A chaque index de adjGraph mettez son cout a 0.
* Retourner le graph creer.
*/
AdjMatrix* create_graph(size_t max_nodes) {
	AdjMatrix* MatriceProche = allocate(sizeof(AdjMatrix));
	MatriceProche->len = 0;
	MatriceProche->max_size = max_nodes;

	MatriceProche->nodes = allocate(sizeof(Node) * MatriceProche->max_size);
	for (int i = 0; i < MatriceProche->max_size; i++) {
		MatriceProche->nodes[i].cost = 0;
		MatriceProche->nodes[i].path_from = 0;
		MatriceProche->nodes[i].visited = 0;
		MatriceProche->nodes[i].data = NULL;
	}

	MatriceProche->adjGraph = allocate(sizeof(int*) * MatriceProche->max_size);
	for (int i = 0; i < MatriceProche->max_size; i++) {
		MatriceProche->adjGraph[i] = allocate(sizeof(int) * MatriceProche->max_size);
	}
	for (int i = 0; i < MatriceProche->max_size; i++) {
		for (int j = 0; j < MatriceProche->max_size; j++) {
			MatriceProche->adjGraph[i][j] = 0;
		}
	}

	return MatriceProche;
}


void add_node(AdjMatrix* graph, void* data) {
	graph->nodes[graph->len].data = data;
	graph->len++;
}


void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost) {
	graph->adjGraph[fromNode][toNode] = cost;
}


void dijkstra(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath) {
	for (int i = 0; i < graph->len; i++) {
		graph->nodes[i].visited = 0;
		graph->nodes[i].path_from = NULL;
		graph->nodes[i].cost = UINT8_MAX;
	}
	while (solvedPath->top > -1) {
		stack_pop(solvedPath);
	}

	Queue* pathQ = allocate(sizeof(Queue));
	Queue* pathQNum = allocate(sizeof(Queue));
	queue_init(pathQ);
	queue_init(pathQNum);
	Node* NewNode = &graph->nodes[startNodeIndex];
	queue_push(pathQ, NewNode);
	queue_push(pathQNum, startNodeIndex);
	NewNode->cost = 0;
	int currentIndex = -1;
	int cost = -1;
	while (NewNode != NULL) {
		NewNode = queue_pop(pathQ);
		currentIndex = queue_pop(pathQNum);
		NewNode->visited = 1;
		if (NewNode == &graph->nodes[endNodeIndex]) {
			break;
		}
		for (int i = 0; i < graph->len; i++) {
			if (!graph->nodes[i].visited) {
				cost = graph->nodes[currentIndex].cost + graph->adjGraph[currentIndex][i];
				if (graph->nodes[i].cost > cost && graph->nodes[currentIndex].cost != cost) {
					queue_push(pathQ, &graph->nodes[i]);
					queue_push(pathQNum, i);
					graph->nodes[i].cost = cost;
					graph->nodes[i].path_from = currentIndex;
				}
			}
		}
	}
	while (NewNode->path_from != NULL) {
		stack_push(solvedPath, NewNode);
		int indexPosition = NewNode->path_from;
		NewNode = &graph->nodes[indexPosition];
	}
	stack_push(solvedPath, NewNode);
}