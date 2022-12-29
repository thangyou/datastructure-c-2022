/*
    하드 디스크에 파일로 그래프의 인접 행렬이 저장되어 있다고 가정하고 다음 함수를 작성하라.
    그래프 파일의 형식은 다음과 같다.
    4       // 정점의 개수
    0 1 1 1 // 인접 행렬
    1 0 1 1
    1 1 0 1
    1 1 1 0
    read_graph_mat(GraphType *g, char *name) : 이름이 name인 그래프 파일 읽어서 그래프 g의 인접 행렬에 저장
    write_graph_mat(GraphType *g, char *name) : 그래프 g의 인접 행렬을 이름이 name인 그래프 파일에 저장
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

void read_graph_mat(GraphType *g, char *name){

    FILE *fp = fopen(name, "r");

    if(fp == NULL){
        printf("파일열기 실패\n");
        return;
    } else {
        printf("파일열기 성공\n");
    }

    fscanf(fp, "%d", &g->n);

    for(int i=0; i<g->n; i++)
        for(int j=0; j<g->n; j++)
            fscanf(fp, "%d",&(g->adj_mat[i][j]));

    fclose(fp);

}


void write_graph_mat(GraphType *g, char *name){
    FILE *fp = fopen(name, "w");

    if(fp == NULL){
        printf("파일열기 실패\n");
        return;
    } else {
        printf("파일열기 성공\n");
    }

    for(int i=0; i<g->n; i++){
        for(int j=0; j<g->n; j++){
            fprintf(fp, "%d ", g->adj_mat[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

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

	free(g);
}