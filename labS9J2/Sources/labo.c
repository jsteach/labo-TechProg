#include "labo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>



AdjMatrix* create_graph(size_t max_nodes) {
	AdjMatrix* Matrice = (AdjMatrix*)allocate(sizeof(AdjMatrix));
	Matrice->len = 0;
	Matrice->max_size = max_nodes;
	Matrice->nodes = (Node*)allocate(sizeof(Node) * max_nodes);

	for (size_t i = 0; i < max_nodes; i++) {
		Matrice->nodes[i].cost = UINT8_MAX;
		Matrice->nodes[i].visited = 0;
		Matrice->nodes[i].path_from = UINT8_MAX;
	}

	Matrice->adjGraph = (int**)allocate(sizeof(int*) * max_nodes);
	for (size_t i = 0; i < max_nodes; i++) {
		Matrice->adjGraph[i] = (int*)allocate(sizeof(int) * max_nodes);
		for (size_t j = 0; j < max_nodes; j++) {
			Matrice->adjGraph[i][j] = 0;
		}
	}

	return Matrice;

}


void add_node(AdjMatrix* graph, void* data) {
	if (graph->len >= graph->max_size) {
		return;
	}
	graph->nodes[graph->len].data = data;
	graph->nodes[graph->len].cost = UINT8_MAX;
	graph->nodes[graph->len].visited = 0;
	graph->nodes[graph->len].path_from = UINT8_MAX;
	graph->len++;
}


void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost) {
	if (fromNode >= graph->len || toNode >= graph->len) {
		return;
	}
	graph->adjGraph[fromNode][toNode] = cost;
}

//1. On met le noeud de début dans le noeud courant et on garde en mémoire le noeud viser
//2. On met le noeud de début comme visiter et son coût à la valeur 0
//3. On fait une boucle qui continue temps que le noeud courant n’est pas le noeud viser
//a.On parcours les noeuds adjacences
//i.À chaque noeud, si le noeud n’est pas visiter, on évalue son coût
//ii.Si le coût dans le noeud est plus grand que le coût évaluer
//1. On assigne le coût plus petit au noeud
//2. On assigne aussi de quel noeud nous provenons(i.e.path_from)
//iii.On évalue ensuite si le noeud sera notre prochaine destination, si son coût est plus bas que l’ancien
//noeud destination, nous le remplaçons par ce dernier
//
//b.On marque le noeud courant comme visiter
//c.Si on a un noeud destination, on l’assigne au noeud courant, sinon, on retourne au dernier noeud visiter avant
//4. On doit reconstruire le chemin parcouru

void dijkstra(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath) {
	Node* currNode = &graph->nodes[startNodeIndex];
	currNode->visited = 1;
	currNode->cost = 0;

	int currentIndex = startNodeIndex;

	while (currentIndex != endNodeIndex) {
		int nextNode = -1;
		uint8_t bestCost = UINT8_MAX;

		// Parcours des noeuds adjacents
		for (size_t i = 0; i < graph->len; i++) {
			int edgeCost = graph->adjGraph[currentIndex][i];

			if (edgeCost > 0 && !graph->nodes[i].visited) {
				uint8_t newCost = graph->nodes[currentIndex].cost + edgeCost;

				if (newCost < graph->nodes[i].cost){
					graph->nodes[i].cost = newCost;
					graph->nodes[i].path_from = (uint8_t)currentIndex;
				}

				// choisir le prochain meilleur noeud
				if (graph->nodes[i].cost < bestCost) {
					bestCost = graph->nodes[i].cost;
					nextNode = (int)i;
				}
			}
		}
		graph->nodes[currentIndex].visited = 1;

		if (nextNode != -1) {
			currentIndex = nextNode;
		}
		else {
			return;
		}
	}

	//Reconstruire le chemin
	int node = endNodeIndex;
	while (node != startNodeIndex && graph->nodes[node].path_from != UINT8_MAX) {
		stack_push(solvedPath, graph->nodes[node].data);
		node = graph->nodes[node].path_from;
	}
	//Ajouter le noeud de départ
	stack_push(solvedPath, graph->nodes[startNodeIndex].data);
}

