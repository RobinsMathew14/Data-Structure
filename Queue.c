#include <stdio.h>

int enqueue(int Queue[], int rear, int n) {
    if (rear == n - 1) {
        printf("\nQueue Overflow");
        return rear;
    } else {
        int item;
        rear++;
        printf("\nEnter the element to be added: ");
        scanf("%d", &item);
        Queue[rear] = item;
        return rear; 
    }
}

int dequeue(int Queue[], int front, int rear) {
    if (front > rear) {
        printf("\nQueue Underflow");
        return front; 
    } else {
        printf("\nThe deleted element is: %d", Queue[front]);
        front++;
        return front; 
}
}
void display(int Queue[], int front, int rear) {
    if (rear < front) {
        printf("\nThe queue is empty");
    } else {
        printf("\nThe elements in the queue are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
        printf("\n"); 
    }
}

int main() {
    int n, front = 0, rear = -1, choice;
    char c;
    
    printf("\nEnter the queue size: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("\nInvalid queue size.");
        return 1; 
    }

    int Queue[n];

    do {
        printf("\nQueue operations");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rear = enqueue(Queue, rear, n);
                break;
            case 2:
                front = dequeue(Queue, front, rear);
                break;
            case 3:
                display(Queue, front, rear);
                break;
            default:
                printf("\nInvalid choice");
                break;
        }

        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');
    
    printf("\nExiting...\n");
    return 0;
}





..


#include <stdio.h>
int push(int top, int n, int stack[])
	{
	int item;
		if(top >=n-1)
		{
		printf("the stack overflow");
		}
		else 
		{
		    top++;
		    printf("Ente the elements to insert");
		    scanf("%d",& item);
		    stack[top]=item;
		}
		return top;
	}
	int pop (int top, int stack[])
		{
			int item;
			if (top==-1)
				{
				printf("The stack underflow");
				}
			else
			{
				item=stack[top];
				top--;
				printf("The delect item %d",item);
			}
			return top;
		}
	void display(int stack[],int top)
		{
			if (top==-1)
				{
					printf("The stack Empty");
				}
			else
				{
					printf("The Elements in the stack");
					for(int i=0;i<=top; i++)
					{
						printf("%d", stack[i]);
					}
					printf("\n");
				}
		}
int main()
{
	int item,n,option,top=1;
	char ch;
	printf("Enter the stack  size");
	scanf("%d",&n);
	int stack[n];
		do
		   {
			printf("Stack opreation \n");
			printf("1.push \n");
			printf("2.pop\n");
			printf("3.display\n");
			printf("Enter the option ");
			scanf("%d" ,&option);
			
			switch(option)
			{
				case 1:
				top = push(top,n, stack);
				break;
				
				case 2:
				top = pop(top, stack);
				break;
				
				case 3: 
				display(stack, top);
				
				default:
				printf("Invalid");
				break;
			} 
				printf("Do you want to continue(y/n): ");
				scanf(" %c", &ch);
			}
			while (ch == 'Y' || ch == 'y');
			printf("\n Exit");
			return 0;
		   
}  


