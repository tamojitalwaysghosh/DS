#include <stdio.h>
#include <stdbool.h>
#define INF 99999

int min(int a,int b){
    return (a>b)?b:a;
}

void bellmanford(int graph[40][40],int vertices,int source){
    int distance[40];
    for(int i=0;i<vertices;i++){
        distance[i]=INF;
    }
    
    distance[source]=0;
    
    for(int i=0;i<vertices-1;i++){
        for(int u=0;u<vertices;u++){
            for(int v=0;v<vertices;v++){
                if(distance[u]!=INF && graph[u][v]!=0 && distance[v]>distance[u]+graph[u][v]){
                    distance[v]=min(distance[v],distance[u]+graph[u][v]);
                }
            }
        }
    }
    
    for(int u=0;u<vertices;u++){
        for(int v=0;v<vertices;v++){
            if(distance[u]!=INF && graph[u][v] && distance[v]>distance[u]+graph[u][v]){
                printf("Negative edge cycle exists");
                return;
            }
        }
    }
    
    printf("Vertex\tDistance from Source\n");
    for(int i=0;i<vertices;i++){
        printf("\t%d\t%d\n",i,distance[i]);
    }
}

int main() {
    int source;
    int n=7;
    int graph[40][40]={
      {0,6,5,5,INF,INF,INF},
      {INF,0,-1,-2,-2,INF,INF},
      {INF,INF,0,INF,1,INF,INF},
      {INF,INF,-2,0,INF,-1,INF},
      {INF,INF,INF,INF,0,INF,3},
      {INF,INF,INF,INF,INF,0,3},
      {INF,INF,INF,INF,INF,INF,0}
    };
    
    printf("Enter the source vertex:");
    scanf("%d",&source);
    
    bellmanford(graph,n,source);

    return 0;
}
