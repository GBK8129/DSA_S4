#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int key;
    struct Node *l;
    struct Node *r;
};
void CreateNode(struct Node **A, int k)
{
   *A=(struct Node*)malloc(sizeof(struct Node));
   //printf("KEY: %d\n",)
   (*A)->key = k; 
   (*A)->l = NULL;
   (*A)->r = NULL;
}
void Insert(struct Node** A, struct Node* T)
{
  if(*(A)==NULL)
  { 
     *(A)=T;
     return;
  }
     //T->p=(*A);
     if (T->key < (*A)->key)
       { Insert(&(*A)->l, T); }
     else if (T->key > (*A)->key)
       { Insert(&(*A)->r, T); }
}
int Height(struct Node *A)
{
    if (A == NULL)
     {return 0;}
    int l,r;
        l = Height(A->l);
        r = Height(A->r);
    if (l > r)
     {return (l + 1);}
    else
     {return (r + 1);}
    
}
int GetBalance(struct Node *A)
{
    int lh=Height(A->l);
    int rh=Height(A->r);
    return (lh-rh);
}
void isAVL(struct Node *A, int k[])
{
    if (A==NULL)
    {return;}
    isAVL(A->l,k);
    int balance=GetBalance(A);
    if(balance != 0 && balance != 1 && balance !=-1)
    {k[0]++;}
    isAVL(A->r,k);
    return;
}
int main()
{
    char c;
    char space;
    int val;
    int k[1];
    k[0]=0;
    struct Node *temp;
    struct Node *A=NULL;
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
        case 'i': scanf("%c",&space);
                  scanf("%d",&val);
                  CreateNode(&temp,val);
                  Insert(&A,temp);
                  break;
        case 'c': isAVL(A,k);
                  if(k[0]==0)
                  {printf("1\n");}
                  else
                  {printf("0\n");}
                  k[0]=0;
                  break;
        case 't': return 0;

        }
    }
}