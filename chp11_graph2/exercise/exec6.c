/*
    5번 그래프에 대하여 Floyd 알고리즘을 적용하고
    배열 A의 내용을 매 단계마다 출력하라.
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES	100	
#define INF	1000000	/* 무한대 (연결이 없는 경우) */

typedef struct GraphType {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void printA(GraphType *g)
{
	int i, j;
	printf("===============================\n");
	for (i = 0; i<g->n; i++) {
		for (j = 0; j<g->n; j++) {
			if (A[i][j] == INF)
				printf("  * ");
			else printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("===============================\n");
}

void floyd(GraphType* g)
{

	int i, j, k;
	for (i = 0; i<g->n; i++)
		for (j = 0; j<g->n; j++)
			A[i][j] = g->weight[i][j];
	printA(g);

	for (k = 0; k<g->n; k++) {
		for (i = 0; i<g->n; i++)
			for (j = 0; j<g->n; j++)
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
		printA(g);
	}
}

int main(void)
{
	GraphType g = { 6,
    {{  0,  40,   45,   15,  INF,  INF },
    { 40,   0,   20,   15,  20,    INF },
    { 45,  20,   0,  INF,   33,  40 },
    { 15,   15,  INF,   0,   40,  INF },
    { INF,   20,   33, 40,    0,  3 },
    { INF,  INF,  40,  INF,  3,    0 }}
	};
	floyd(&g);
	return 0;
}