#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int x[4];
int a[4][4];

bool place(int k,int i){
    for(int j=1;j<k;j++){
        if(x[j]==i || abs(x[j]-i)==abs(j-k)){
            return false;
        }
    }
    return true;
}

void nqueen(int k,int n){
    for(int i=1;i<=n;i++){
        if(place(k,i)){
            x[k]=i;
            if(k==n){
                for(int j=1;j<=n;j++){
                    for(int p=1;p<=n;p++){
                        if(x[j]==p){
                            printf(" Q ");
                        }
                        else{
                            printf(" x ");
                        }
                    }
                    printf("\n");
                }
                printf("\n\n");
            }
            else{
                nqueen(k+1,n);
            }
        }
    }
}

int main() {
    // Write C code here
    printf("Nqueen\n");
    nqueen(1,4);
    return 0;
}

//-----------------------------
Nqueen
 x  Q  x  x 
 x  x  x  Q 
 Q  x  x  x 
 x  x  Q  x 


 x  x  Q  x 
 Q  x  x  x 
x  x  x  Q 
 x  Q  x  x 


