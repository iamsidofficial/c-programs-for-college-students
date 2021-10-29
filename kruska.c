#include <stdio.h>
#include<stdlib.h>
#define MAX 30
FILE *f,*o;
typedef struct edge {
  int u, v, w;
} edge;

typedef struct edge_list {
  edge data[MAX];
  int n;
} edge_list;

edge_list elist;

int Graph[MAX][MAX], n;
edge_list spanlist;

void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);  // initialising parent.
void sort();
void print();

// Applying Krushkal Algo
void kruskalAlgo() {
  int belongs[MAX], i, j, cno1, cno2;
  elist.n = 0;

  for (i = 1; i < n; i++)
    for (j = 0; j < i; j++) {
      if (Graph[i][j] != 0) {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = Graph[i][j];
        elist.n++;
      }
    }

  sort();

  for (i = 0; i < n; i++)
    belongs[i] = i;

  spanlist.n = 0;

  for (i = 0; i < elist.n; i++) {
    cno1 = find(belongs, elist.data[i].u);    //cno1, cno2 parents
    cno2 = find(belongs, elist.data[i].v);

    if (cno1 != cno2) {                   // ie not cycle
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n = spanlist.n + 1;
      applyUnion(belongs, cno1, cno2);    //apply union
    }
  }
}

int find(int belongs[], int vertexno) {       // find orignal parent
  return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2) {        //called only when its not a cycle
  int i;

  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

// Sorting algo
void sort() {
  int i, j;
  edge temp;

  for (i = 1; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}

// Printing the result
void print() {
  int i, cost = 0;

  char vert[7]={'A','B','C','D','E','F','G'};  // setting names of the vertices

o=fopen("output.txt","w");
  for (i = 0; i < spanlist.n; i++) {
    fprintf(o,"\n%c - %c : %d", vert[spanlist.data[i].u], vert[spanlist.data[i].v], spanlist.data[i].w);

    cost = cost + spanlist.data[i].w;
  }


  fprintf(o,"\nSpanning tree cost: %d", cost);
  fclose(o);
}

int main() {
  int i, j, total_cost,p[30][30];

  printf("Kruskal's algorithm in C\n");

  printf("Enter the no. of vertices:\n");
  scanf("%d", &n);
  f=fopen("input.txt","w");

  printf("\nEnter the cost adjacency matrix:\n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &p[i][j]);

        fprintf(f,"\n%d",p[i][j]);
    }
  }
  fclose(f);
  f=fopen("input.txt","r");
  for(i=0;i<n;i++)
  {
      for(j=0;j<n;j++)
      {
        fscanf(f,"%d,",&Graph[i][j]);
      }
  }
  fclose(f);


  kruskalAlgo();
  print();
}
