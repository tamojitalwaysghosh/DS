// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#define INF 99999

int min(int visited[40],int distance[40],int vertices){
    int min=INF;
    int minIndex=0;
    
    for(int i=0;i<vertices;i++){
        if(!visited[i] && distance[i]<=min){
            min=distance[i];
            minIndex=i;
        }
    }
    
    return minIndex;
}

void dijkstra(int graph[40][40],int vertices,int source){
    int visited[40],distance[40];
    
    for(int i=0;i<vertices;i++){
        distance[i]=INF;
    }
    
    distance[source]=0;
    
    for(int i=0;i<vertices-1;i++){
        int u= min(visited,distance,vertices);
        visited[u]=true;
        
        for(int v=0;v<vertices;v++){
            if(!visited[v] && graph[u][v] && distance[u]!=INF && distance[v]>distance[u]+graph[u][v]){
                distance[v]=distance[u]+graph[u][v];
            }
        }
    }
    
    printf("Vertices\tDistance from Edge\n");
    for(int i=0;i<vertices;i++){
        printf("%d\t%d\n",i,distance[i]);
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
    
    dijkstra(graph,n,source);
    return 0;
}
