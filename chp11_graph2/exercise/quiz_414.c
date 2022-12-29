#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i <n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v])) v = i;
	return (v);
}
//
void prim(GraphType* g, int s)
{
	int i, u, v;

	for (u = 0; u<g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for (i = 0; i<g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) return;
		printf("정점 %d 추가\n", u);
		for (v = 0; v<g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v]< distance[v])
					distance[v] = g->weight[u][v];
	}
}

int main(void)
{
	GraphType g = { 8, 
	{{ 0, 10, INF, 6, INF, INF, INF, 1 },
	{ 10,  0, 4, INF, INF, 2, INF, INF },
	{ INF, 4, 0, 11, INF, 7, INF, INF },
	{ 6, INF, 11, 0, INF, INF, INF, 3 },
	{ INF, INF, INF, INF, 0, 5, INF, 7 },
	{ INF, 2, 7, INF, INF, 0, INF, INF },
	{ INF, INF, INF, INF, INF, 9, 0, 12 },
	{ 1, INF, INF, 3, 8, INF, 12, 0 }}
	};
	prim(&g, 0);
	return 0;
}
