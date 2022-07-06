#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int top,n;
    int *A;
};
int isEmpty(struct Stack *S)
{
   if((S)->top==-1)
   { return -1;}
   else
   {return 0;}
}
int isFull(struct Stack *S)
{
   if(S->top==((S->n)))
   {return -1;}
   else
   {return 0;}
}
void Push(int val,struct Stack **S)
{
    if(isFull((*S))==-1)
    {
        printf("1\n"); 
        int *B;
        B=(int*)malloc(2*(*S)->n*sizeof(int));
        for(int i=0;i<(*S)->n;i++)
        {B[i]=(*S)->A[i];}
        free((*S)->A);
        //A=(int*)malloc(2*(*S)->n*sizeof(int));
        (*S)->A=B;
        (*S)->n=(*S)->n*2;
    }
    if(isEmpty((*S))==-1)
    {
        (*S)->top++;
    }
    int pos;
    pos=(*S)->top;
    //(((*S)->(*A))+pos)=val;
    (*S)->A[pos] = val;
    (*S)->top=(*S)->top+1;

}
void Pop(struct Stack **S)
{
    if(isEmpty((*S))==-1)
    {printf("-1\n"); return;}
    int pos;
    (*S)->top=(*S)->top-1;
    pos=(*S)->top;
    printf("%d\n",(*S)->A[pos]);
    
}
int main()
{
    int n;
    scanf("%d",&n);
    char c,space;
    int val;
    struct Stack *S;
    S=(struct Stack*)malloc(sizeof(struct Stack));
    //Q=(struct Queue*)malloc(sizeof(struct Queue));
    S->top=-1;
    S->n=n;
    S->A=(int*)malloc(S->n*sizeof(int));
    //int check;
    while(1)
    {
       scanf("%c",&c);
       switch(c)
       {
           case 'i': scanf("%c",&space);
                     scanf("%d",&val);
                     Push(val,&S);
                     break;
           case 'd': Pop(&S);
                     break;
           case 't': return 0;
       }
    }    
}