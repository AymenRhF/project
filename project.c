#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


float rega(float x[],float y[],float a,float b,int n){
    float d=0;
    for (int i=0 ; i<n ; i++)
    {
        d+=x[i]*(y[i]-(a*x[i]+b));
    }
    return(-2.0f/n)*d;
}
float regb(float x[],float y[],float a,float b,int n){
    float d=0;
    for (int i=0 ; i<n ;i++)
    {
        d+=(y[i]-(a*x[i]+b));
    }
    return(-2.0f/n)*d;
}

void main(){
    srand(time(0));
    srand(time(0));
    int n;
    printf("\ndonner la taille du tableau:");
    scanf("%d",&n);
    float tabx[n];
    float taby[n];
    for(int i=0;i<n;i++){
        printf("\n donner x:");
        scanf("%f",&tabx[i]);
        printf("\n donner y:");
        scanf("%f",&taby[i]);

    }
    int i=0;
    srand(time(0));
    float a=(rand()%100)+1;
    printf("a est %d\n",a);
    float b=(rand()%100)+1;
    printf("b est %d\n",b);
    float alpha=0.1;
    while (i<10000)
    {
        float der_a=rega(tabx,taby,a,b,n);
        float der_b=regb(tabx,taby,a,b,n);
        if (fabs(der_a)<=0.001 && fabs(der_b)<=0.001)
            break;
        a=a-alpha*der_a;
        b=b-alpha*der_b;
        i++;
    }
    printf("\na=%f\nb=%f",a,b);
    
}