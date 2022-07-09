#include <stdio.h> // mandatory include

float time_angle(int XX, int YY){   // function you have to implement
    float result = 30*(XX%12) - 5.5*YY;
    if(result<0)
    {
        result*=-1;
    }
    if(360-result<result)
    {
        result=360-result;
    }    
    // sample variable - you can change this according to your need
    return result;                 // return statment
}

int main()                       // mandatory main function
{
    int XX, YY;                 // variable denoting hours and minutes
    scanf("%d", &XX);           // hour input
    scanf("%d", &YY);           // minute input
    // printf("%d:%d",XX,YY);
    int result = time_angle(XX, YY);  // calling function
    printf("%d",result);               // printing result
    return 0;                   // return statment
}
