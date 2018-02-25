/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int lenthHelper(int x)
{
    if(x>=1000000000) return 10;
    if(x>=100000000) return 9;
    if(x>=10000000) return 8;
    if(x>=1000000) return 7;
    if(x>=100000) return 6;
    if(x>=10000) return 5;
    if(x>=1000) return 4;
    if(x>=100) return 3;
    if(x>=10) return 2;
    return 1;
}

int swap_n(char num[],int i,int j)
{
    char swap;
    printf("-->%s",num);
    printf("x is : <%ld> y is : <%ld>\n",i,j);
    swap = num[j];
    num[j] = num[i];
    printf("-->%s",num);
    num[i] = swap;
    printf("-->%s",num);
    return atoi(num);
}

int main()
{
    int number = 312213;
    char num[lenthHelper(number)+1];
    char number1;
    int len,x,i,j;
    char swap;
    
    //If number is odd, remove the middle number
    sprintf(num,"%ld",number);

    len = lenthHelper(number);
    x = floor(len/2);
    if((len%2)!=0)
    {
        num[x]='0';   
    }
    
    printf("--%s--\n",num);
    for (i=len-x-1;i>=0;i--)
    {
        for(j=i-1;j>=0;j--)
        {
            if(num[i]>num[j])
            {
                number = swap_n(num,i,j);
                number = swap_n(num,i+x-1,j+x-1);
                printf ("\n--%ld--",number);
                return number;
            }
        }
    }
    
    printf ("\n--%ld--",number);
    return number;
}



