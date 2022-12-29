/*
    연결된 그래프 G의 간선들 중에서 그 간선을 제거하면 연결이 끊어지는 간선 (u,v)를 bridge라고 한다. 
    주어진 그래프에서 브리지를 찾아내는 함수를 작성하라.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType {
	int n;	// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r<MAX_VERTICES; r++)
		for (c = 0; c<MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
// 인접 행렬 출력 함수
void print_adj_mat(GraphType* g)
{
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}
void cnt_bridge(GraphType *g) {
	int r, c, edges;
	for (r = 0; r < g->n; r++)
		edges = 0;
	for (c = 0; c < g->n; c++){
		if (g->adj_mat[r][c] != 0)
			edges++;
		if (c == g->n - 1)
			if (edges == 1){
				c = 0;
				while (g->adj_mat[r][c] != 0) {
					c++;
				}
				printf("bridge:(%d,%d)", r, c);
			}
	}
}

void main()
{
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	init(g);
	for(int i=0;i<4;i++)

	insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);
    cnt_bridge(g);

	free(g);
}