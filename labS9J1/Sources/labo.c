#include "labo.h"

Node* create_node(void* data) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        perror("Échec allocation Node");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    memset(new_node->adj, 0, sizeof(new_node->adj));
    new_node->visited = 0;
    new_node->len = 0;

    new_node->revPath = malloc(sizeof(QNode)); //Je n'ai pas compris l'erreur dans cette ligne
    if (!new_node->revPath) {
        perror("Échec allocation QNode");
        free(new_node);
        exit(EXIT_FAILURE);
    }

    new_node->revPath->node = new_node;
    new_node->revPath->prev = NULL;

    return new_node;
}
void add_adjacent_node(Node* root, Node* node) {
    if (root->len < UINT8_MAX) {
        root->adj[root->len++] = node;
    }
    else {
        fprintf(stderr, "Erreur : trop de voisins pour le noeud %d\n", root->data);
    }
}
int dfs(Node* root[], int len, Node* curr, void* key, Stack* s) {
    if (curr == NULL) {
        return 0; 
    }
    stack_push(s, curr);
    while (s->top != -1) {
        Node* node = (Node*)stack_pop(s);

        if (node->visited) {
            continue;
        }
        node->visited = 1;
        if (node->data == key) {
            printf("Clé trouvée : %d\n", (int)(uintptr_t)node->data);
            return 1;
        }
        for (int i = 0; i < node->len; i++) {
            if (!node->adj[i]->visited) {
                stack_push(s, node->adj[i]);
            }
        }
    }
    return 0;
}
int bfs(Node* root[], void* key, Stack* s) {
    if (root == NULL || s == NULL) {
        return 0;
    }
    for (int i = 0; i < sizeof(root) / sizeof(root[0]); i++) {
        stack_push(s, root[i]);
    }
    while (s->top != -1) {
        Node* node = (Node*)stack_pop(s);
        if (node->visited) {
            continue;
        }
        node->visited = 1;
        if (node->data == key) {
            printf("Clé trouvée : %d\n", (int)(uintptr_t)node->data);
            return 1; // Clé trouvée
        }
        for (int i = 0; i < node->len; i++) {
            if (!node->adj[i]->visited) {
                stack_push(s, node->adj[i]);
            }
        }
    }
    return 0;
}