/*
    최단 경로 함수에서 distance[] 배열의 내용을 각 단계마다 출력하고, 그 역할을 설명하라.
    - distance[] : 지정한 정점으로부터 모든 인접한 정점까지의 거리를 계산
    * exec5 정답!
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES	100	
#define INF	1000000	/* 무한대 (연결이 없는 경우) */

typedef struct GraphType {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];     /* 시작정점으로부터의 최단경로 거리 */
int found[MAX_VERTICES];		/* 방문한 정점 표시 */
								
int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i<n; i++)
		if (distance[i]< min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}
void print_status(GraphType* g)
{
	static int step=1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("        found:    ");
	for (int i = 0; i<g->n; i++)
		printf("%2d ", found[i]);
	printf("\n\n");
}

void shortest_path(GraphType* g, int start)
{
	int i, u = start, w;
	for (i = 0; i<g->n; i++) /* 초기화 */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;    /* 시작 정점 방문 표시 */
	distance[start] = 0;
	for (i = 0; i<g->n-1; i++) {
		print_status(g);
		printf("path : \t%d -> ", u);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		printf("%d \n\n", u);
		for (w = 0; w<g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w]<distance[w])
					distance[w] = distance[u] + g->weight[u][w];
	}
}
int main(void)
{
	GraphType g = { 6,
    {{  0,  50,   45,   10,  INF,  INF },
    { INF,   0,   10,   15,  INF,    6 },
    { INF,  INF,   0,  INF,   30,  INF },
    { 20,   INF,  INF,   0,   15,  INF },
    { INF,   20,   35, INF,    0,  INF },
    { INF,  INF,  INF,  INF,  3,    0 }}
	};
	shortest_path(&g, 0);
	return 0;
}
