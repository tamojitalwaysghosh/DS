#include <stdio.h>
#define max 7

void bfs(int adj[][max], int visited[], int start){
    int queue[max],rear=-1,front=-1;
    for(int i=0;i<max;i++){
        visited[i]=0;
    }
    rear+=1;
    queue[rear]=start;
    visited[start]=1;
    front++;
    
    while(front<=rear){
        start=queue[front];
        front++;
        printf("%d ",start);
        for(int i=0;i<max;i++){
            if(adj[start][i] && visited[i]==0){
                rear+=1;
                queue[rear]=i;
                visited[i]=1;
            }
        }
    }
}

void dfs(int adj[][max],int visited[],int k){
    printf("%d ",k);
    visited[k]=1;
    for(int i=0;i<max;i++){
        if(adj[k][i] && visited[i]==0){
            dfs(adj,visited,i);
        }
    }
}

int main() {
    int visited[max]={0,0,0,0,0,0,0};
    int adj[max][max]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    printf("BFS: ");
    dfs(adj,visited,0);
    return 0;
}

//BFS: 0 1 2 3 4 5 6 
