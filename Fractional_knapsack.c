#include<stdio.h>

void swap(int* h,int *k)
{
    int temp=*h;
    *h=*k;
    *k=temp;
}

void swapp(float* h,float* k)
{
    float temp=*h;
    *h=*k;
    *k=temp;
}

void knapsack(int n,int capacity,int weight[],int value[])
{
    //total_profit as tp, capacity as m
    float tp=0;
    int m=capacity,i;
    float x[n];
    
    for(i=0;i<n;i++){
        x[i]=0;
    }
    
    for(i=0;i<n;i++)
    {
        if(weight[i]<=m){
            tp=tp+value[i];
            m=m-weight[i];
            x[i]=1.0;
            //printf("\nweight is %d",m);
        }
        else
        {
            break;
        }
    }
    
    if(i<n)
    {
            x[i]=(float)m/weight[i];
            tp=tp+(x[i]*value[i]);
            //printf("\nm is %d and weight is %d and ratio is %f and%f",m,weight[i],(float)m/weight[i],x[i]);
    }
    
    printf("\nThe x values are: \n");
    for(int i=0;i<n;i++)
    {
        printf("%f\t",x[i]);
    }
    
    printf("\nth total profit is:   %f",tp);
}

void main()
{
    int n,max;
    printf("*Fractional Knapsack*\n");
    printf("Enter the number of objects: ");
    scanf("%d",&n);
    
    printf("\n Enter max weight of the knapsack: ");
    scanf("%d",&max);
    
    int weight[n],value[n];
    
    printf("\nEnter the weight and value associated(separate the values using space): \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&weight[i],&value[i]);
    }
    
    float ratio[n];
    for(int i=0;i<n;i++)
    {
        ratio[i]=(float)value[i]/weight[i];
    }
    
    /////Sorting of the ratio value
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ratio[i]<=ratio[j])
            {
                swapp(&ratio[i],&ratio[j]);
                
                swap(&weight[i],&weight[j]);
                
                swap(&value[i],&value[j]);  
            }
        }
    }
    
    printf("The table:\n");
    printf("weight  ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",weight[i]);
    }
    
    printf("\n");
    
    printf("value   ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",value[i]);
    }
    
    printf("\n");
    
    printf("ratio   ");
    for(int i=0;i<n;i++)
    {
        printf("%f\t",ratio[i]);
    }
    
    knapsack(n,max,weight,value);
}


//*Fractional Knapsack*
//Enter the number of objects: 5
//Enter max weight of the knapsack: 60
//Enter the weight and value associated(separate the values using space): 
//2 56
//3 10
//1 14
//3 56
//2 53
//The table:
//weight  2	2	3	1	3	
//value   56	53	56	14	10	
//ratio   28.000000	26.500000	18.666666	14.000000	3.333333	
//The x values are: 
//1.000000	1.000000	1.000000	1.000000	1.000000	
//The total profit is:   189.000000
