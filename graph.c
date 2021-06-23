#include<stdlib.h>

struct adjListNode{
    int dest;
    struct adjListNode *next;
};

struct adjList{
    struct adjListNode *head;
};

struct Graph{
    int vertex;
    struct adjList *arr;   
};

struct Graph* createGraph(int vertex){


    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertex = vertex;

    graph->arr = (struct adjList*)malloc(vertex * sizeof(struct adjList));

    for(int i = 0; i < vertex; ++i){
        graph->arr[i].head = NULL;
    }
    
    return graph;
};

struct adjListNode* newNode(int dest)
{
    struct adjListNode* newNode =
     (struct adjListNode*) malloc(sizeof(struct adjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}


void addEdge(struct Graph *graph, int src, int dest){
    printf("Edge added");
    struct adjListNode *newnode = newNode(dest);

    newnode->next = graph->arr[src].head;
    graph->arr[src].head = newnode;

    newnode = newNode(src);

    newnode->next = graph->arr[dest].head;
    graph->arr[dest].head = newnode;



}


void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->vertex; ++v)
    {
        struct adjListNode* pCrawl = graph->arr[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl != NULL)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main(){

struct Graph *graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}