#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node 
{
   int key;
   struct Node *l;
   struct Node *r;
   struct Node *p;
   int Color;
};
void CreateNode(struct Node **A, int val, int c)
{
   *A=(struct Node*)malloc(sizeof(struct Node));
   
   (*A)->key = val; 
   (*A)->Color = c; 
   (*A)->l = NULL;
   (*A)->r = NULL;
   (*A)->p = NULL;
}
void LeftRotate(struct Node *RB,struct Node *A)
{
    /*struct Node *B = (*A)->r;
    struct Node *P = (*A)->p;
    struct Node *temp = B->l;
    B->l = (*A); (*A)->r = temp;  
    B->p = P;
    B->p->r=B;  */
    struct Node*  B= (A)->r;
    (A)->r = B->l;
    if ((A)->r!=NULL)
    {(A)->r->p = (A);}
    B->p = (A)->p;
    if ((A)->p==NULL)
    {RB = B;}
    else if ((A) == (A)->p->l)
    {(A)->p->l = B;}
    else
    {(A)->p->r = B;}
    B->l = (A);
    (A)->p = B;
    //return B;
}
void RightRotate(struct Node *RB, struct Node *A)
{
    /*struct Node *B = (*A)->l;
    struct Node *P = (*A)->p;
    struct Node *temp = B->r;
    B->r = (*A); (*A)->l = temp;
    B->p = P;
    B->p->l=B;*/ 
    //return B; 
    struct Node* B = (A)->l;
    (A)->l = B->r;
    if ((A)->l!=NULL)
    {(A)->l->p = (A);}
    B->p = (A)->p;
    if ((A)->p==NULL)
    {RB = B;}
    else if ((A) == (A)->p->l)
    {(A)->p->l = B;}
    else
    {(A)->p->r = B;}
    B->r = (A);
    (A)->p = B;
    //return B;
}
void Insert(struct Node **RB, struct Node *T)
{
  if(*(RB)==NULL)
    { *(RB)=T; return; }
     T->p=(*RB);
     if (T->key < (*RB)->key)
       { Insert(&((*RB)->l), T); }
     else if (T->key > (*RB)->key)
       { Insert(&((*RB)->r), T); }
       return;
}
struct Node *InsertRedBlack(struct Node *RB, int val)
{
    struct Node *z=NULL;
    struct Node *temp=NULL;
    
    if((RB) == NULL)
    {CreateNode(&z,val,0); (RB)=z; return (RB);}
    
   CreateNode(&z,val,1);
    Insert(&(RB),z);
    while ( z!= (RB) && z->Color!=0 && z->p->Color == 1 )
    {//printf("VAL: %d\n",z->key);
        struct Node *y=NULL;
        if (z->p == z->p->p->l)
            y = z->p->p->r;
        else
            y = z->p->p->l;
 
        if (y!= NULL && y->Color == 1)
        {
            y->Color = 0;
            z->p->Color = 0;
            z->p->p->Color = 1;
            z = z->p->p;
        }
 
        
        else
        {
            
            if (z->p == z->p->p->l &&
                z == z->p->l)
            {
                int ch = z->p->Color ;
                z->p->Color = z->p->p->Color;
                z->p->p->Color = ch;
                RightRotate(RB,(z->p->p));
            }
 
            else if (z->p == z->p->p->l &&
                z == z->p->r)
            {
                int ch = z->Color ;
                z->Color = z->p->p->Color;
                z->p->p->Color = ch;
                LeftRotate(RB,(z->p));
                RightRotate(RB,(z->p));
                
            }
 
            else if (z->p == z->p->p->r &&
                z == z->p->r)
            {
                int ch = z->p->Color ;
                z->p->Color = z->p->p->Color;
                z->p->p->Color = ch;
                LeftRotate(RB,(z->p->p));

            }

            else if (z->p == z->p->p->r &&
                z == z->p->l)
            {
                int ch = z->Color ;
                z->Color = z->p->p->Color;
                z->p->p->Color = ch;
                RightRotate(RB,(z->p));
                //printf("!\n");
                LeftRotate(RB,(z->p));
                //printf("")
            }
            
        }
    }
    while(RB->p!=NULL)
    {RB=RB->p;}
    (RB)->Color = 0;  
    return RB;     
}
void CheckBeautiful(struct Node *RB,int c,int rev,int bc[])
{
    if(RB==NULL)
    {return;}
    if(bc[0]==-1)
    {return;}
   // printf("FAult\n");
    if(RB->l!=NULL)
   { if((c==0 && RB->l->Color==1) || (c==1 && RB->l->Color==0)) 
    {
      if(RB->l !=NULL && rev !=RB->l->key)  
      {
          int k=RB->l->Color;
          CheckBeautiful(RB->l,k,RB->l->key,bc);
      } 
    }
    else
    {bc[0]=-1;return;} }
    if(RB->r!=NULL)
   { if((c==0 && RB->r->Color==1) || (c==1 && RB->r->Color==0)) 
    {
      if(RB->r !=NULL && rev !=RB->r->key)  
      {
          int k=RB->r->Color;
          CheckBeautiful(RB->r,k,RB->r->key,bc);
      } 
    }
    else
    {bc[0]=-1;return;} }
    if(RB->p!=NULL)
   { if((c==0 && RB->p->Color==1) || (c==1 && RB->p->Color==0)) 
    {
      if(RB->p !=NULL && rev !=RB->p->key)  
      {
          int k=RB->p->Color;
          CheckBeautiful(RB->l,k,RB->key,bc);
      } 
    }
    else
    {bc[0]=-1;return;} }
  
    
}
int main()
{
    struct Node *RB=NULL;
 
    int n;
   
    scanf("%d",&n);
    
    int i;
    int val;
    for(i=0;i<n;i++)
    {
        
        scanf("%d",&val);
        if(RB==NULL)
        {
            CreateNode(&RB,val,0);
        }
        else
        {RB=InsertRedBlack(RB,val);}
        //printf("RB: %d\n",RB->key);
    }
    int bc[1];
    bc[0]=(-2);
    CheckBeautiful(RB,(RB->Color),(RB->key),bc);
    
    if(bc[0]!=(-2))
    printf("%d\n",bc[0]);
    else
    {printf("1\n");}
}