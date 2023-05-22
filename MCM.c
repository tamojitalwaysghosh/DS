#include <stdio.h>
#define max 7

int main() {
    int n=5;
    int p[]={5,4,6,2,7};
    int m[5][5]={0};
    int s[5][5]={0};
    int j,min,q;
    for(int d=1;d<n-1;d++){//moving diagonally
        for(int i=1;i<n-d;i++){//reducing rows
            j=i+d;//moving into the column
            min=32767;
            for(int k=i;k<j;k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<min){
                    min=q;
                    s[i][j]=k;
                }
            }
            m[i][j]=min;
        }
    }
    printf("Matrix chain multiplication:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\n-------------------------------------------------");
    printf("\nThe K matix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//Matrix chain multiplication:
0 0 0 0 0 
0 0 120 88 158 
0 0 0 48 104 
0 0 0 0 84 
0 0 0 0 0 

-------------------------------------------------
The K matix:
0 0 0 0 0 
0 0 1 1 3 
0 0 0 2 3 
0 0 0 0 3 
0 0 0 0 0 
