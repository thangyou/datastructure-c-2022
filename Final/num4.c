#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 10
#define INF 1000000

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
    struct GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void insert_vertex(GraphType* g, int v){
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v,int weight){
    GraphNode* node;
    if (u >= g->n || v >= g->n)
    {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    g->weight[u][v] = weight;
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void init(GraphType* g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
    {
        g->adj_list[v] = NULL;
        for (int a = 0; a < MAX_VERTICES; a++)
            g->weight[v][a] = INF;
    }
}
int choose(int distance[], int n, int found[]){
    int i, min, minpos;

    min = INT_MAX;
    minpos = -1;

    for(i=0; i<n; i++){
        if(distance[i]<min && !found[i]){
            min=distance[i];
            minpos=i;
        }
    }
    return minpos;
}

int distance[MAX_VERTICES]; // 최단 경로 표시
int found[MAX_VERTICES]; // 방문 표시

void print_status(GraphType *g){
    static int step=1;
    printf("STEP %d: ", step++);

    printf("distance: ");
    for(int i=0; i<g->n; i++){
        if(distance[i]==INF)
            printf(" * ");
        else
            printf("%3d ",distance[i]);
    }
    printf("\n");
    printf(" \tfound: \t   ");
    for(int i=0; i<g->n; i++)
        printf("%2d ", found[i]);
    printf("\n\n");
}

void shortest_path(GraphType *g, int start){
    int i, u, w;
    for(i=0; i<g->n; i++){
        distance[i] = g->weight[start][i];
        found[i]=FALSE;
    }
    found[start]=TRUE;
    distance[start]=0;

    for(i=0;i<g->n-1; i++){
        print_status(g);
        printf("path : \t%d -> ", u);
        u=choose(distance, g->n, found);
        found[u]=TRUE;
        printf("%d \n\n", u);
        for(w=0; w<g->n; w++)
            if(!found[w])
                if(distance[u]+g->weight[u][w] < distance[w])
                    distance[w] = distance[u]+g->weight[u][w];
    }
}

int main(void)
{
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 6; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1, 40);
    insert_edge(g, 1, 2, 20);
    insert_edge(g, 0, 2, 45);
    insert_edge(g, 2, 4, 33);
    insert_edge(g, 2, 5, 40);
    insert_edge(g, 0, 3, 15);
    insert_edge(g, 3, 4, 40); 
    insert_edge(g, 4, 5, 3); 
    insert_edge(g, 1, 3, 15);
    insert_edge(g, 1, 4, 20);
    printf("\n");
    shortest_path(g, 0);
    return(0);
}
