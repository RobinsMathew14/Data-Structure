#include<stdio.h>
#include<stdlib.h>

    struct node
    {
        /* data */
        int data;
        struct node *link;
    }*temp,*head,*temp1,*ptr,*ptr1;
        void main()
        {
            int item,choice,k,n;
            do{
            printf("Linked list operations \n");
            printf("1 Insertrion at the begninng\n");
            printf("2 Insertion at the end \n");
            printf("3 Instertion at any postion\n");
            printf("4 delection at the begining\n");
            printf("5 delction at the end \n");
            printf("6 delction at any postion\n");
            printf("7 display\n");
            printf("8 exit\n");
            printf("enter the option \n");
  
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
    
                printf("Enter thw item");
                scanf(" %d", &item);
                temp= (struct node*)malloc(sizeof(struct node));
                if (temp == NULL){
                    printf("Underflow");
                } else if (head == NULL) {
                	temp->data = item;
                	temp->link= NULL;
                	head = temp;
                } else {
                	temp->data = item;
                	temp->link = head;
                	head = temp;
                }
                break;
                case 2:
                temp=(struct node*)malloc(sizeof(struct node));
                printf("Enter the item");
                scanf(" %d",&item);
                if (temp == NULL){
                    printf("UNDER FLOW");
                }else if(head == NULL){
                      temp->data= item;
                      temp->link=NULL;
                      head=temp;
                }else{
                    ptr = head;
                    while(ptr-> link!=NULL){
                        ptr = ptr->link;
                         }
                         ptr->link=temp;
                         temp->link=NULL;
                         temp->data=item;
                    }
                    break;

                case 3:
                  printf("Enter the item");
                  scanf(" %d", &item);
                  
                  printf("aEnter the  item aftr which vale to be placed");
                   scanf(" %d",&k);
                   temp=(struct node*)malloc(sizeof(struct node));
                   ptr = head;
                   while((ptr->data!=k)&&(ptr->link !=NULL)){
                    ptr = ptr->link;
                   }
                   if (ptr == NULL)
                   {
                    /* code */
                    printf("search failed");
                   }else
                   {
                    temp->link=ptr->link;
                    ptr->link=temp;
                    temp->data=item;
                   }
                   break;
             /*case 4:
                    ptr = head;
                    head =ptr->link;
                    free(ptr);
                    printf("Node dlect from the begning\n");
                    break;
                    case 5:
                    if(head ==NULL){
                        printf("List is empty");
                    }else if (head->link == NULL)
                        {
                           
                            head= NULL;
                            printf("Node delected");
                        } else
                        {
                            ptr = head;
                            while (ptr->link!=NULL)
                            {
                                
                                ptr1=ptr;
                                ptr=ptr->link;
                            }
                            ptr1=ptr;
                            ptr= ptr->link;
                        }
                        ptr1->link=NULL;
                        free(ptr);
                        printf("Node delected from the lat\n");
                        break;
                        

                        case 6:

                        struct node *temp;
                        temp= head;
                        int i,pos;
                        printf("Enter the postion the node:");
                        scanf("%d",&pos);

                        if (pos==1)
                        {
                         
                            printf("Element delelct id %d \n",temp->data);
                            head= head->link;
                            temp->link=NULL;
                            free(temp);

                        }else
                        {
                            for ( i = 0; i < pos; i++)
                            {
                               
                                struct node*temp1=temp->link;
                                temp->link=temp->link->link;
                                printf("Element deleted is:%d\n",temp->data);
                                temp->link=NULL;
                                free(temp1);
                            }
                            
                        }
                        
                        break;*/
                    case 7:
                    ptr =head ;
                    if (ptr==NULL)
                    {
                        /* code */
                        printf("list empty\n");
                    }else
                    {
                        printf("The elemnts are\n");
                        while (ptr!=NULL)
                        {
                            /* code */
                            printf("%d ",ptr->data);
                            ptr= ptr->link;
                        }
                        printf("\n");
                        }

                        break;

                        case 8:

                        printf("Exit");
                        break;

             		default:
          		  printf("Invaliddddddddddddd.......!!!!!!!!!!!!!!11");
                	  break;
            }
        }while(choice != 8);
}
    
