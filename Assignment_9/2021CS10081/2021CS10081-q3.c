#include <stdio.h> // mandatory include

int food(int x, int y, int m, int n){   // function you have to implement
    long long result = 1;          // sample variable - you can change this according to your need
    //printf("(%d,%d) and (%d,%d) \n",x,y,m,n);
    for(int i=1;i<=y;i++)
    {
        result*=(x+i);
        result/=i;
    }
    for(int i=1;i<=n-y;i++)
    {
        result*=(m-x+i);
        result/=i;
    }
    return result;                 // return statment
}

int main()                       // mandatory main function
{
    int x, y, m, n;             // variable denoting coordinate of restaurant and delivery location
    scanf("%d", &x);           // x coordinate of restaurant
    scanf("%d", &y);            // y coordinate of restaurant
    scanf("%d", &m);           // x coordinate of delivery location
    scanf("%d", &n);            // y coordinate of delivery location
    //printf("(%d,%d) and (%d,%d) \n",x,y,m,n);
    int result = food(x, y, m, n);  // calling function
    printf("%d",result);               // printing result
    return 0;                   // return statment
}
