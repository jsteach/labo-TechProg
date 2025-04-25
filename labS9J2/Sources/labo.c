#include "labo.h"

/*
* Creer une matrice d'adjacence. Mettre len a 0. Mettre max_size a max_nodes.
* Allouer de la memoire pour le max de noeud specifier i.e. pour graph->nodes.
* Pour chaque noeud de graph->nodes mettre le cost et path_from a UINT8_MAX et visited a 0.
* Pour adjGraph, allouer une quantiter de int* relatif a la valeur de max_nodes.
* Dans chaque int* allouer un tableau de int relatif a la valeur max_nodes.
* A chaque index de adjGraph mettez son cout a 0.
* Retourner le graph creer.
*/
AdjMatrix* create_graph(size_t max_nodes) {
	AdjMatrix* matAdj = allocate(sizeof(AdjMatrix));
	matAdj->len = 0;
	matAdj->max_size = max_nodes;

	matAdj->nodes = allocate(sizeof(Node) * max_nodes);

	for (size_t i = 0; i < max_nodes; i++)
	{
		matAdj->nodes[i].cost = UINT8_MAX;
		matAdj->nodes[i].path_from = UINT8_MAX;
		matAdj->nodes[i].visited = 0;
	}

	matAdj->adjGraph = allocate(sizeof(int*) * max_nodes);

	for (size_t i = 0; i < max_nodes; i++)
	{
		matAdj->adjGraph[i] = allocate(sizeof(int) * max_nodes);

		for (size_t j = 0; j < max_nodes; j++)
		{
			matAdj->adjGraph[i][j] = 0;
		}
	}

	return matAdj;
}

/*
* Creer un node, lui attribuer le data et l'ajouter dans la matrice d'adjacence.
*/
void add_node(AdjMatrix* graph, void* data) {
    Node* n = &graph->nodes[graph->len++];
    n->data = data;
}

/*
* Ajouter un lien dans la matrice d'adjacence, d'un noeud a l'autre noeud, en specifiant le cout y etant relier.
*/
void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost) {
	graph->adjGraph[fromNode][toNode] = cost;
}

/*
* Implementer l'algorithme de dijkstra.
*/
void dijkstra(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath) {
	
	int currNode = startNodeIndex;
	int targetNode = endNodeIndex;

	graph->nodes[currNode].cost = 0;

    // Étape 3 : Boucle principale
    while (currNode != targetNode) {
        Node* currentNode = &graph->nodes[currNode];
        currentNode->visited = 1;

        int nextNodeIndex = -1;
        uint8_t lowestCost = UINT8_MAX;

        // a. Parcourir les noeuds adjacents
        for (size_t i = 0; i < graph->len; i++) {
            int edgeCost = graph->adjGraph[currNode][i];

            if (edgeCost > 0 && graph->nodes[i].visited == 0) {
                uint8_t newCost = currentNode->cost + edgeCost;

                // ii. Mise à jour du coût si on trouve mieux
                if (graph->nodes[i].cost > newCost) {
                    graph->nodes[i].cost = newCost;
                    graph->nodes[i].path_from = currNode;
                }

                // iii. Sélection du prochain noeud à visiter
                if (graph->nodes[i].cost < lowestCost) {
                    lowestCost = graph->nodes[i].cost;
                    nextNodeIndex = i;
                }
            }
        }

        // b. Si on a trouvé un noeud suivant
        if (nextNodeIndex != -1) {
            currNode = nextNodeIndex;
        }
        else {
            // c. Aucun chemin possible
            return;
        }
    }

    // Étape 3 : Reconstruction du chemin
    // Vérifier si un chemin existe
    if (graph->nodes[endNodeIndex].cost == UINT8_MAX ||
        graph->nodes[endNodeIndex].path_from == UINT8_MAX) {
        return; // Pas de chemin
    }

    // Étape 4 : Reconstruction du chemin (de fin à début)
    int traceIndex = endNodeIndex;
    while (traceIndex != startNodeIndex && traceIndex != UINT8_MAX) {
        stack_push(solvedPath, &graph->nodes[traceIndex]);
        traceIndex = graph->nodes[traceIndex].path_from;
    }

    stack_push(solvedPath, &graph->nodes[startNodeIndex]);
}