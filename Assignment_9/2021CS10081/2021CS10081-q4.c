#include <stdio.h> // mandatory include
int exc(int XX, int YY, int ZZZZ, int AA, int BB, int CCCC)
{
    int result=0;
    int ctrm=0;
    for(int i=ZZZZ;i<CCCC;i++)
        {
            if(i%4==0&&ctrm%7==2)
            {
                result+=1;
            }
            else if(i%4!=0&&ctrm%7==1)
            {
                result+=1;
            }
            if(i%4==3)
            {
                ctrm+=2;
            }
            else
            {
                ctrm+=1;
            }
        }
        if(BB>YY&&!(BB==3&&AA==1))
        {
            if(CCCC%4==0&&ctrm%7==2)
            {
                result+=1;
            }
            else if(CCCC%4!=0&&ctrm%7==1)
            {
                result+=1;
            }
        }
        return result;
}
int birt(int XX, int YY, int ZZZZ, int AA, int BB, int CCCC){   // function you have to implement
    int result = 0;          // sample variable - you can change this according to your need
    //printf("%d-%d-%d and %d-%d-%d \n",XX, YY, ZZZZ, AA, BB, CCCC);
    int ctr=6;
    if(XX==29 && YY==2)
    {
        return exc(XX,YY,ZZZZ,AA,BB,CCCC);
    }
    else if(YY>2)
    {
        for(int i=ZZZZ;i<CCCC;i++)
        {
            if(ctr%7==1)
            {
                result+=1;
            }
            if(i%4==3)
            {
                ctr+=2;
            }
            else
            {
                ctr+=1;
            }
        }
        if(BB>YY)
        {
            if(ctr%7==1)
            {
                result+=1;
            }
        }
        else if(BB==YY && AA>XX)
        {
            if(ctr%7==1)
            {
                result+=1;
            }
        }
    }
    else
    {
        for(int i=ZZZZ;i<CCCC;i++)
        {
            if(ctr%7==1)
            {
                result+=1;
            }
            if(i%4==0)
            {
                ctr+=2;
            }
            else
            {
                ctr+=1;
            }
        }
        if(BB>YY)
        {
            if(ctr%7==1)
            {
                result+=1;
            }
        }
        else if(BB==YY && AA>XX)
        {
            if(ctr%7==1)
            {
                result+=1;
            }
        }
    }
    return result;                 // return statment
}

int main()                       // mandatory main function
{
    int XX, YY, ZZZZ, AA, BB, CCCC;             // variable 
    scanf("%d", &XX);           // input of Date of birth
    scanf("%d", &YY);            // input of Month of birth
    scanf("%d", &ZZZZ);           // input of Year of birth
    scanf("%d", &AA);           // input of Date of death
    scanf("%d", &BB);            // input of Month of death
    scanf("%d", &CCCC);            // input of Year of death
    //printf("%d-%d-%d and %d-%d-%d \n",XX, YY, ZZZZ, AA, BB, CCCC);
    int result = birt(XX, YY, ZZZZ, AA, BB, CCCC);  // calling function
    printf("%d",result);               // printing result
    return 0;                   // return statment
}
