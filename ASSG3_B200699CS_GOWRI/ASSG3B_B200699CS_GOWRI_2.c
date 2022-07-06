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
int BeautCalc(struct Node *RB, int c[], int b);
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
    struct Node*  B= A->r;
    A->r = B->l;
    if (A->r!=NULL)
    {A->r->p = A;}
    B->p = A->p;
    if (A->p==NULL)
    {RB = B;}
    else if (A ==A->p->l)
    {A->p->l = B;}
    else
    {A->p->r = B;}
    B->l = A;
    A->p = B;
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
    struct Node* B = A->l;
    A->l = B->r;
    if (A->l!=NULL)
    {A->l->p = A;}
    B->p = A->p;
    if (A->p==NULL)
    {RB = B;}
    else if (A == A->p->l)
    {A->p->l = B;}
    else
    {A->p->r = B;}
    B->r = A;
    A->p = B;
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
/*
struct Node *InsertRedBlack(struct Node *RB, int val)
{
    struct Node *z=NULL;
    
    if(RB==NULL)
    {CreateNode(&z,val,0); (RB)=z; return (RB);}
    CreateNode(&z,val,1);
    Insert(&(RB),z);
    
    while ( z!= (RB) && z->p->Color == 1)
    {
        struct Node *y;
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
                RightRotate(RB,z->p->p);
            }
 
            else if (z->p == z->p->p->l &&
                z == z->p->r)
            {
                int ch = z->Color ;
                z->Color = z->p->p->Color;
                z->p->p->Color = ch;
                LeftRotate(RB,z->p);
                RightRotate(RB,z->p->p);
            }
 
            else if (z->p == z->p->p->r &&
                z == z->p->r)
            {
                int ch = z->p->Color ;
                z->p->Color = z->p->p->Color;
                z->p->p->Color = ch;
                LeftRotate(RB,z->p->p);
            }

            else if (z->p == z->p->p->r &&
                z == z->p->l)
            {
                int ch = z->Color ;
                z->Color = z->p->p->Color;
                z->p->p->Color = ch;
                RightRotate(RB,z->p);
                LeftRotate(RB,z->p->p);
            }
        }
    }
    while(RB->p!=NULL)
    {RB=RB->p;}
    (RB)->Color = 0;  
    return RB;
    
   // struct Node *G;
    
    /*while ((temp != RB) && (temp->Color != 0)
           && (temp->p->Color == 1))
    {
        G=temp->p->p;
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
    
//} 
struct Node *BeautCalcParent(struct Node *RB, int c[],int b, int val)
{
    if(RB==NULL)
    {return NULL;}
    /* int i=0,j=0;
    if(b<0)
    {return 0;}
    if(b==0 && RB!=NULL && RB->Color==0)
    {c[0]++;i=1;j=1;return 1;}
    if(RB->r!=NULL && val==RB->r->key)
    {i=BeautCalc(RB->l,c,b-1);}
    else if(RB->l!=NULL && val==RB->l->key && i==0)
    {j=BeautCalc(RB->r,c,b-1);} */
    if(b==0)
    {return RB;}
    else
    {
    if(RB->r!=NULL && val==RB->r->key)
    {return RB->l;}
    else if(RB->l!=NULL && val==RB->l->key)
    {return RB->r;} 
    }
}
int BeautCalc(struct Node *RB, int c[], int b)
{
    int i=0,j=0,k=0;
    if(RB==NULL || b<0)
    {return 0;}
    int temp=RB->key;
    //int i,j,k,l;
    if(b==0 && RB->Color==0)
    {//c[0]++;
    return 1;}
    if(RB->l!=NULL )
    {BeautCalc(RB->l,c,b-1);}
    if(RB->r!=NULL )
    {BeautCalc(RB->r,c,b-1);}
    if(RB->p!=NULL )
    {//RB=BeautCalcParent(RB->p,c,b-1,RB->key);
    if((b-1)==0 && RB->p->Color==0)
    {return 1;}
    else
    {
        if(RB->key==RB->p->r->key)
        {BeautCalc(RB->l,c,b-2);}
        else if(RB->key==RB->p->l->key)
        {BeautCalc(RB->r,c,b-2);}
    }
    //BeautCalc(RB,c,b-1);}
   
    }      
}
void BeautCheck(struct Node *RB, int c[], int b)
{
  //printf("VAL:%d\n",RB->key);
  if(RB==NULL)
  {return;}
  struct Node *k=NULL;
  int i;
      //printf("VAL %d\n", RB->key);
     i=BeautCalc(RB,c,b);
     /*if(k!=NULL && k->Color==0)
     {c[0]++;printf("K:%d\n",k->key);} */
     if(i==1)
     {printf("Tru: %d\n", RB->key);c[0]++;}
     if(RB->l!=NULL)
     {BeautCheck(RB->l,c,b);}
     if(RB->r!=NULL)
     {BeautCheck(RB->r,c,b);}
    
}
void printkdistanceNodeDown(struct Node *RB, int val,int map[])
{

    if (RB == NULL || val < 0)
        return;

    if (val == 0 && RB->Color == 0)
    {
        map[0]++;
        return;
    }

    printkdistanceNodeDown(RB->l, val - 1,map);
    printkdistanceNodeDown(RB->r, val - 1,map);
}

int Beauty(struct Node *RB, struct Node *T, int map[], int c[], int b)
{

    if (RB == NULL)
        return -1;

    if (RB == T)
    {
        printkdistanceNodeDown(RB, b,map);
        return 0;
    }
    if (b == 1)
    {
        if (T->p->Color == 0)
            map[0]++;
        if (T->r != NULL)
        {
            if (T->r->Color == 0)
                map[0]++;
        }
        if (T->l != NULL)
        {
            if (T->l->Color == 0)
                map[0]++;
        }
        return 0;
    }

    // Recur for left subtree
    int dl = Beauty(RB->l, T, map,c,b);

    if (dl != -1)
    {

        if (dl + 1 == b && T->Color == 0)
            map[0]++;

        else
            printkdistanceNodeDown(RB->r, b - dl - 2,map);

        return 1 + dl;
    }

    int dr = Beauty(RB->r, T, map,c,b);
    if (dr != -1)
    {
        if (dr + 1 == b && T->Color == 0)
            map[0]++;
        else
            printkdistanceNodeDown(RB->l, b - dr - 2,map);
        return 1 + dr;
    }

    return -1;
}
void BeautyCheck(struct Node *RB, struct Node *T, int c[], int b)
{
    int map[1];
    map[0] = 0;
    if (T == NULL)
    {return;}
     //printf("VAL:%d\n",RB->key);
 /* if(RB==NULL)
  {return;}
  struct Node *k=RB; */
    
        int BCheck;
        BCheck = Beauty(RB, T,map,c,b);
        if (map[0] == 0 || BCheck == -1)
        {}
        else
        { c[0]++; }
        map[0] = 0;
           /* if(k!=NULL && k->Color==0)
     {c[0]++;} */
 /*    if(RB->l!=NULL)
     {BCheck(RB->l,c,b);}
     if(RB->r!=NULL)
     {BCheck(RB->r,c,b);}*/

        BeautyCheck(RB,T->l, c,b); 
        BeautyCheck(RB,T->r, c,b);
}

/*void BCheck(struct Node *RB, int c[], int b)
{
  //printf("VAL:%d\n",RB->key);
  if(RB==NULL)
  {return;}
  struct Node *k=RB;
      
    // int f=printkdistanceNode(k,RB,b,c);
    /* if(k!=NULL && k->Color==0)
     {c[0]++;} */
 /*    if(RB->l!=NULL)
     {BCheck(RB->l,c,b);}
     if(RB->r!=NULL)
     {BCheck(RB->r,c,b);}
} */
int main()
{
    struct Node *RB=NULL;
    int b;
    int n;
    scanf("%d",&b);
    scanf("%d",&n);
    int bc[1];
    bc[0]=0;
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
    BeautyCheck(RB,RB,bc,b);
    printf("%d\n",bc[0]);
}