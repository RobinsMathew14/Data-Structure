#include<stdio.h>
void enqueue(int queue[],int *front, int *rear,int n){
    if (*front==(*rear+1)%n)
    {
        printf(" queue overflow\n");
    }else{
        int item;
        printf("Enetr the item");
        scanf("%d",&item);
        *rear=(*rear+1)%n;
        queue[*rear]=item;
        if (*front==-1)
        {
            *front=0;
        }
        }
}
void dequeue(int queue[],int *front, int *rear,int n){
    if (*front==-1 && *rear==-1)
    {
        printf(" queue underflow\n");
    }else{
        printf("dequeue element,%d\n",queue[*front]);
        if(*front==*rear){
            *front=-1;
            *rear=-1;
        }
        else{
            *front=(*front+1)%n;
        }
    }
}
void display(int queue[],int front, int rear,int n){

    if (front==-1 && rear==-1){
    printf("Queue is empty\n");
    }
    else{
        printf("Queue elements\n");
        int i=front;
        while (i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%n;
        }
        printf("%d\n",queue[i]);
        
    }
}
int main(){
    int front=-1,rear=-1,x,n;
    char ch;
    printf("Enetr the size of the queue");
    scanf("%d",&n);
    int queue[n];
    do
    {
        printf(" operation \n  1.enqueue\n  2. dequeue\n  3.display\n");
        printf("Enter the option ");
        scanf("%d",&x);
        switch (x)
        {
        case 1:enqueue(queue,&front,&rear,n );
            break;
         case 2:dequeue(queue,&front,&rear,n );
            break;
            case 3:display(queue,front,rear,n );
            break;
        default:
        printf("Invalid");
            break;
        }
    	printf("Do you want to continue(y/n): ");
				scanf(" %c", &ch);
			
    }while (ch == 'Y' || ch == 'y');
			printf("\n Exit");
			return 0;
    }
