﻿#include "labo.h"

/*
* Creer un Noeud, assigner lui la valeur de data, faite un memset 0 sur adj, 
* visited a faux, len a 0, allouer de la memoire pour le QNode et assurer vous de mettre la propiete prev de QNode a NULL.
* Retourner ensuite le pointeur vers le Node.
*/
Node* create_node(void* data) {
	Node* newNode = allocate(sizeof(Node));

	newNode->data = data;
	memset(newNode->adj,0,sizeof(Node*) * UINT8_MAX);
	newNode->visited = 0;
	newNode->len = 0;
	
	newNode->revPath = allocate(sizeof(QNode));

	newNode->revPath->prev = NULL;

	return newNode;
}

/*
* Ajouter le node dans la liste d'adjacence de root.
*/
void add_adjacent_node(Node* root, Node* node) {
	root->adj[root->len++] = node;
}

/*
* Programmer l'algorithme de depth first search afin de trouver la cle. 
* Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
* La Stack devrait contenir la liste en ordre inverse de celle parcouru. 
* i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner C -> B -> A
*/
int dfs(Node* root[], int len, Node* curr, void* key, Stack* s) {
    if (curr == NULL)
    {
        curr = root[0];
    }

    curr->visited = 1;

    stack_push(s, curr);

    if (curr->data == key) {
        return 1;
    }

    for (int i = 0; i < curr->len; i++) {
        Node* voisin = curr->adj[i];

        if (voisin->visited == 0) {
            if (dfs(root, len, voisin, key, s)) {
                return 1;
            }
        }
    }

    stack_pop(s);
    return 0;
}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. 
* Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
* La Stack devrait contenir la liste en ordre du chemin parcouru. 
* i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner A -> B -> C
*/
int bfs(Node* root[], void* key, Stack* s) {

    Queue q;
    queue_init(&q);
    int count = 0;

    queue_push(&q, root[0]);
    root[0]->visited = 1;
    root[0]->revPath->data = NULL;

    while (q.prev != NULL)
    {
        Node* nodeSearch = queue_pop(&q);
        count++;
        
        if (nodeSearch->data == key)
        {
            Node* revPath = nodeSearch;
            while (revPath != NULL)
            {
                stack_push(s, revPath);
                revPath = (Node*)revPath->revPath->data;
            }
            return count;
        }

        for (int i = 0; i < nodeSearch->len; i++) {
            Node* voisin = nodeSearch->adj[i];

            if (voisin->visited == 0) {
                queue_push(&q, voisin);
                voisin->visited = 1;
                voisin->revPath->data = nodeSearch;
            
            }

        }
    }

    return count;
}