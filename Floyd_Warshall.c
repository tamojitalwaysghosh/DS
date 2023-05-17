#include <stdio.h>
#include <stdlib.h>
#define INF 99999

void printArray(int matrix[][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matrix[i][j]==INF){
                printf("%4s","INF");
            }
            else{
                printf("%4d",matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void floydwarshall(int graph[][4]){
    int matrix[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            matrix[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<4;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(matrix[i][k]+matrix[k][j]<matrix[i][j]){
                    matrix[i][j]=matrix[i][k]+matrix[k][j];
                }
            }
        }
    }
    printArray(matrix);
}

int main() {
    
    int graph[4][4]={
        {0,3,INF,7},
        {8,0,2,INF},
        {5,INF,0,1},
        {2,INF,INF,0}
    };
    floydwarshall(graph);
    
    return 0;
}

//---------------------------
   0   3   5   6
   5   0   2   3
   3   6   0   1
   2   5   7   0
