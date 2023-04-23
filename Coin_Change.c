#include<stdio.h>

int ans[40];

int coinf(int *coins,int n,int value){
    int count=0;
    
    for(int i=0;i<n;i++){

            while(value>=coins[i]){
                ans[count]=coins[i];
                count++;
                value -= coins[i];
            }
            if(value==0){
                break;
            }
    }
    return count;
}

void main(){
    //numbers are arranged in descending order as we are following the greedy approach
    int coins[] = {25,20,10,5};
    
    int value = 95;

    //find the size of the coins array
    int size = sizeof(coins)/sizeof(coins[0]);
  
    //taking the number of coins to be taken
    int num_of_coin=coinf(coins,size,value);
    
    //final coins array 
    for(int i=0;i<num_of_coin;i++){
        printf("%d ",ans[i]);
    }
}
