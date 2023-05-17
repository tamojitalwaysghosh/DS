#include <stdio.h>

int main() {
    int start[3]={1,5,7};
    int finish[3]={4,8,9};
    int activities=sizeof(start)/sizeof(start[0]);
    int i=0;
    printf("%d",i);
    for(int j=1;j<activities;j++){
        if(start[j]>=finish[i]){
            printf("\t%d",j);
            i=j;
        }
    }
    return 0;
}

//------------------------------
0	1
