// Online C compiler to run C program online
#include <stdio.h>

void tower_of_hanoi(int n,char source,char auxiliary,char destination){
    if(n==1){
        printf("move 1 disk from %c to %c\n",source,destination);
        return;
    }
    
    tower_of_hanoi(n-1,source,destination,auxiliary);
    printf("move %d disks from %c to %c\n",n,source,destination);
    tower_of_hanoi(n-1,auxiliary,source,destination);
}

int main() {
    int n=3;
    printf("Enter Number of disks:\n");
    //scanf("%d",&n);
    char source='A',auxiliary='B',destination='C';
    
    tower_of_hanoi(n,source,auxiliary,destination);

    return 0;
}
