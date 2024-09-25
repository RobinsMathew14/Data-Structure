#include<stdio.h>
int main(){
int row,col,i,j,k,count=0;
printf("Enter the rowa and columns of the sparse matrix:");
    scanf("%d %d",&row,&col);
    int a[row][col];
    printf("Enter the sparse matrix:\n");
    for(i=0;i<row;i++){  
    for(j=0;j<col;j++){
      scanf(" %d",&a[i][j]);
      if(a[i][j]!=0) {
          count++;
       }
    }}
     printf("Entered sparse matrix:\n");
      for(i=0;i<row;i++){  
    for(j=0;j<col;j++){
         printf("%d     ",a[i][j]);
        }printf("\n");
    }
     int b[count+1][3];
    k=1;
    b[0][0]=row;
    b[0][1]=col;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
        if(a[i][j]!=0)
         {
          b[k][0]=i;
          b[k][1]=j;
          b[k][2]=a[i][j];
          k++;
            }
    }}
    b[0][2]=k-1;
    printf("Row\tcolumn\tvalue\n");
    for(i=0;i<count+1;i++){
        for(j=0;j<3;j++){
         printf("[%d]\t",b[i][j]);
        }printf("\n");
    }
    return 0;
}
