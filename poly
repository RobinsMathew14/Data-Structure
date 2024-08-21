#include<stdio.h>
struct polynomial
{
    int  coeff;
    int expo;

};

int main (){
struct polynomial x[15];
int count,i;
printf("number of terms in first polynomal");
scanf("%d",&count);
printf("\nEnetr the coefficents and expoments in decensting order");
for ( i = 0; i < count; i++)
{
    printf("\ncoefficent:");
    scanf("%d",&x[i].coeff);
    printf("\nExponents");
    scanf("%d",&x[i].expo);
}
printf("\nFirst Polynomial");
for(i=0;i<count;i++){
printf("%d x^%d", x[i].coeff, x[i].expo);
if(i<count-1)
printf("+");
}
return 0;
}
