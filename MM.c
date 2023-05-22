// Online C compiler to run C program online
#include <stdio.h>

void maxmin(int a[40],int i,int j,int *max,int *min){
    if(i==j){
        *max=*min=a[i];
    }
    else if(i==j-1){
        if(a[i]<a[j]){
            *max=a[j];
            *min=a[i];
        }
        else{
            *max=a[i];
            *min=a[j];
        }
    }
    else{
        int max1,max2,min1,min2;
        int mid=(i+j)/2;
        maxmin(a,i,mid,&max1,&min1);
        maxmin(a,mid+1,j,&max2,&min2);
        
        if(max1>max2){
            *max=max1;
        }
        else{
            *max=max2;
        }
        if(min1<min2){
            *min=min1;
        }
        else{
            *min=min2;
        }
    }
}

int main() {
    int a[40],n,max,min;
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter a number:");
        scanf("%d",&a[i]);
    }
    maxmin(a,0,n-1,&max,&min);
    printf("max:%d\n",max);
    printf("min:%d",min);

    return 0;
}
