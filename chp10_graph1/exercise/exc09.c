/*
    adj_mat.c
    크기가 n x n인 방향 그래프 a가 n x n 인접 배열 사용하여 표현되어 있다.
    1) 진출차수(out-degree) 계산 함수 = out_degree()
    2) 진입차수(in-degree) 계산 함수 = in_degree()
    3) 그래프 안에 있는 간선 개수 계산 함수 = cnt_edge()
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
// 1) 시간복잡도 O(n)
void out_degree(GraphType *g) 
{
    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->n; j++)
        {
            printf("%2d", g->adj_mat[i][j]);
        }
        printf("\n");
    }
    
}
// 2) 시간복잡도 O(n)
void in_degree(GraphType *g, int n)
{
    int sum = 0;
    for (int i = 0; i < g->n; i++)
    {
        sum += g->adj_mat[i][n];
    }
    printf("진입 차수 = %d\n", sum);
}
// 3) 시간복잡도 O(n^2)
void cnt_edge(GraphType *g)
{
    int sum = 0;
    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->n; j++)
        {
            sum += g->adj_mat[i][j];
        }
    }
    printf("진입 차수 = %d\n", sum);
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

    out_degree(g);
    in_degree(g, 1);
    cnt_edge(g);

	free(g);
}