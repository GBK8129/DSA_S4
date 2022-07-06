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
    /*struct Node *G=NULL;
    struct Node *P=NULL;
    CreateNode(&temp,val,1);
    Insert(&(RB),temp);
    
    while ((temp != RB) && (temp->Color != 0)
           && (temp->p->Color == 1))
    {
        G=temp->p->p;
        P=temp->p;
        if (temp->p == G->l)
        {
            struct Node* T = temp->p->p->r;
            if (T != NULL && T->Color == 1)
            {
                T->Color = 0;
            temp->p->Color = 0;
            G->Color = 1;
            temp = G;
               
            }
 
            else {
                if (temp == temp->p->r) {
                    LeftRotate(RB,temp->p);
                    //printf("TEMP: %d\n",temp->key);
                   temp = temp->p;   
                                    
                }
                RightRotate(RB,G->p);
                int c;
                c = temp->p->Color;
                temp->p->Color = G->Color;
                G->Color = c;
                temp = temp->p;
                
            }
        }
        else {
            struct Node* T = temp->p->p->l;
            if ((T != NULL) && (T->Color == 1))
            {
                G->Color = 1;
                temp->p->Color = 0;
                T->Color = 0;
                temp = G;
            }
            else {
                if (temp == temp->p->l) {
                    RightRotate(RB, temp->p);
                    temp =  temp->p;
                }
                LeftRotate(RB,G->p);
                int c;
                c = temp->p->Color;
                temp->p->Color = G->Color;
                G->Color = c;
                
                
                temp = temp->p;
                
            }
        }
    }
 
    RB->Color = 0;  */
  /* 
   while (temp != *RB && temp->p->Color == 1)
    {
        struct node *y;
        if (z->p == z->p->p->l)
            y = z->p->p->r;
        else
            y = z->p->p->l;
 
        if (y->color == 1)
        {
            y->color = 0;
            z->p->color = 0;
            z->p->p->color = 1;
            z = z->p->p;
        }
 
        
        else
        {
            
            if (z->parent == z->parent->parent->left &&
                z == z->parent->left)
            {
                char ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent->parent);
            }
 
            if (z->parent == z->parent->parent->left &&
                z == z->parent->right)
            {
                char ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent);
                rightRotate(root,z->parent->parent);
            }
 
            if (z->parent == z->parent->parent->right &&
                z == z->parent->right)
            {
                char ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent->parent);
            }

            if (z->parent == z->parent->parent->right &&
                z == z->parent->left)
            {
                char ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent);
                LeftRotate(root,z->parent->parent);
            }
        }
    }
    (*root)->color = 'B';  */

   /* (RB)->Color = 0;
    return RB; */
    
}
void PrintRBTree(struct Node *A)
{
     if (A == NULL)
    {return;}
    char c;
    if(A->Color==1)
    {c='R';}
    else if(A->Color==0)
    {c='B';}
    printf("%d %c",(A->key),c);

    if (A->l==NULL && A->r==NULL)
    {printf(" ");printf("( ) ( )");return;}
    printf(" "); printf("("); printf(" "); 
    if(A->l!=NULL)
    {PrintRBTree(A->l); printf(" ");}
    printf(")"); 
   
    printf(" "); printf("("); printf(" "); 
    if(A->r!=NULL)
    {PrintRBTree(A->r); printf(" ");}
    printf(")"); 
}
int FormKey(char s[])
{
    int i;
    int val=0;
    for(i=0;s[i]!='\0';i++)
    {
        val=(val*10)+s[i]-'0';
    }
    return val;
}
int main()
{
    struct Node *RB=NULL;
   while(1)
    {
         char s[10];
         int val;
         scanf("%s",s);
         if(isdigit(s[0]))
         {
             val=FormKey(s);
            
             RB=InsertRedBlack(RB,val);
             if(RB==NULL)
             {printf("( )\n");}
             else
             {printf("( "); PrintRBTree(RB); printf(" )\n");}
         }
         else if(s[0]=='t')
         {
             return 0;
         }
    }
}