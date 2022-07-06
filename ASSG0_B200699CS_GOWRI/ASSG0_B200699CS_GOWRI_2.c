#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int front,rear,n;
    int Q_Array[100002];
};
int isEmpty(struct Queue *Q)
{
   if(Q->front==-1 || Q->front>=(Q->rear))
   { return -1;}
   else
   {return 0;}
}
int isFull(struct Queue *Q)
{
   if(Q->rear==((Q->n)))
   {return -1;}
   else
   {return 0;}
}
void enQueue(int val,struct Queue **Q)
{  
   //x=(struct Node*)malloc(sizeof(struct Node));
   if(isFull(*Q)==-1)
   {
       printf("1\n");
       return;
   }
   if(isEmpty(*Q)==-1)
   {
       (*Q)->front=0;
       if((*Q)->rear==-1)
       { (*Q)->rear=0; }
   }
   
   int pos=(*Q)->rear;
   (*Q)-> Q_Array[pos]= val; 
   ((*Q)->rear)=((*Q)->rear)+1;
}
void deQueue(struct Queue **Q)
{
  if(isEmpty(*Q)==-1)
   {
       printf("1\n");
       return;
   } 
   printf("%d\n",(*Q)->Q_Array[(*Q)->front]);
   ((*Q)->front)=((*Q)->front)+1;   
}
int main()
{
    int n;
    scanf("%d",&n);
    char c,space;
    int val;
    struct Queue *Q;
    Q=(struct Queue*)malloc(sizeof(struct Queue));
    //Q=(struct Queue*)malloc(sizeof(struct Queue));
    Q->front=-1;
    Q->rear=-1;
    Q->n=n;
    int check;
    while(1)
    {
       scanf("%c",&c);
       switch(c)
       {
           case 'i': scanf("%c",&space);
                     scanf("%d",&val);
                     enQueue(val,&Q);
                     break;
           case 'd': deQueue(&Q);
                     break;
           case 'e': check=isEmpty(Q);
                     if(check==-1)
                     {printf("1\n");}
                     else if(check==0)
                     {printf("-1\n");}
                     break;
           case 'f': check=isFull(Q);
                     if(check==-1)
                     {printf("1\n");}
                     else if(check==0)
                     {printf("-1\n");}
                     break;
           case 't': return 0;
       }
    }    
}