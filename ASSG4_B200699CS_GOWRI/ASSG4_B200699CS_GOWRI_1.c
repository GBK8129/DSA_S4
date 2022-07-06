#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
struct Node
{
    int key;
    int Degree;
    struct Node *p;
    struct Node *c;
    struct Node *s;
};
void Inorder(struct Node *T)
{
    if(T==NULL)
     { return; }
     Inorder(T->c); 
     printf("%d ",T->key);
     Inorder(T->c->s);
}
void Preorder(struct Node *T)
{
    if(T==NULL)
     { return; }
     printf("%d ",T->key);
     Preorder(T->c); 
     Preorder(T->c->s);
}
void Postorder(struct Node *T)
{
    if(T==NULL)
     { return; }
     
     Postorder(T->c); 
     Postorder(T->c->s);
     printf("%d ",T->key);
}
int Ancestor(int A[], struct Node *T)
{
   // A[0]=T->k;
    int i=0;
    while(T!=NULL)
    {
        A[i]=(T->key); i++;
        
        if(T->p!=NULL)
        {T=T->p;continue;}
        else
        {break;}
    }
    return i;
}
void Successor(struct Node* T, int a)
{
    if(T==NULL)
     { return; }
    struct Node* temp;
   // temp=Search(T,a);
   
    if (temp->c != NULL)
     {  
         temp = temp->c;
         while (temp->c!=NULL)
          {temp = temp->c;}
         if(temp!=NULL)
         {
             printf("%d\n",temp->key);
             return;
         }
     }
    else
    { 
    struct Node *exc;
    exc=temp->p;
   
    while(exc!=NULL &&  temp==exc->c)
    {
        temp=exc;
        //exc=exc->p;
        if(exc->p!=NULL)
         exc=exc->p;
        else
        {printf("-1\n"); return;}
    }
    printf("%d\n",exc->key);
    return;
    }
    printf("-1\n");
    return;
}
void Predecessor(struct Node* T, int a)
{
    if(T==NULL)
     { return; }
    struct Node* temp;
   // temp=Search(T,a);
    
    if (temp->c != NULL)
     {
         temp = temp->c;
         while (temp->c!=NULL)
          {temp = temp->c;}
          if(temp!=NULL)
           {
               printf("%d\n",temp->key);
               return;
           }
     }
    else 
    {
     struct Node *exc=NULL;
     
    exc=temp->p;
   
    while(exc!=NULL && temp==(exc)->c)
    {
        temp=exc;
        if(exc->p!=NULL)
         exc=exc->p;
        else
        {printf("-1\n"); return;}
        
    }
    printf("%d\n",exc->key);
    return;
    }
    printf("-1\n");
    
}
void MakeHeap(struct Node **H, int k)
{
    (*H)=(struct Node*)malloc(sizeof(struct Node));
    (*H)->key=k;
    (*H)->Degree=0;
    (*H)->p=NULL;
    (*H)->c=NULL;
    (*H)->s=NULL;
}
void Make_Linkage(struct Node* H, struct Node* U)
{
    
    H->p = U;
    H->s = U->c;
    U->c = H;
    U->Degree++;
}
struct Node* Merge_Union(struct Node* A, struct Node* B)
{
    
    if (B == NULL)
    {return A;}
    if (A == NULL)
    {return B;}

    struct Node* cur = NULL;
    if (B->Degree >= A->Degree)
    {cur = A;}
    else if (B->Degree < A->Degree)
    {cur = B;}

    while (A != NULL && B != NULL)
    {
        if (A->Degree == B->Degree)
        {
            struct Node* sibling = A->s;
            A->s = B;
            A = sibling;
        }
        else if (A->Degree < B->Degree)
        {A = A->s;}
        else
        {
            struct Node* sibling = B->s;
            B->s = A;
            B = sibling;
        }
    }
    return cur;
}
void Union(struct Node **H, struct Node *U)
{
   if (*H == NULL && U == NULL)
    {return;}

    struct Node *cur = Merge_Union(*H, U);
    struct Node* pre = NULL;
    struct Node* now = cur;
    struct Node* nex = now->s;
    while (nex != NULL)
    {
        if ((now->Degree != nex->Degree) || ((nex->s != NULL) && (nex->s)->Degree == now->Degree))
        {
            pre = now;
            now = nex;
        }
        else
        {
            if (nex->key>=now->key)
            {
                now->s = nex->s;
                Make_Linkage(nex, now);
            }
            else
            {
                if (pre == NULL)
                {cur = nex;}
                else
                {pre->s = nex;}
                Make_Linkage(now, nex);
                now = nex;
            }
        }
        nex = now->s;
    }
    *H=cur;
    //return cur;
}
void Insert(struct Node **H, int k)
{
    struct Node *temp;
    MakeHeap(&temp,k);
    Union(&(*H),temp);
}
struct Node *Search(struct Node *H, int k)
{
    if (H == NULL)
    {return NULL;}
    if (H->key == k)
    {return H;}
    struct Node* find = Search(H->c, k);
    if (find != NULL)
    {return find;}
    return Search(H->s, k);
}
void PrintChild(struct Node *H)
{
    if(H==NULL)
    {return;}
   
        printf("%d ",H->key);
        if(H->s!=NULL)
        {printf("%d ",H->s->key);}
        PrintChild(H->c);
        //PrintChild(H->s);
        return;
}
void PrintHeap(struct Node *H)
{
    if(H==NULL)
    {return;}
    //while(H!=NULL)
    //{
        printf("%d ",H->key);
        PrintChild(H->c);
        PrintHeap(H->s);
        
       // H=H->s;
   // }
   // printf("\n");
}
struct Node *Minimum(struct Node *H)
{ 
     if (H == NULL)
        {return NULL;}

    struct Node *pre = NULL;
    struct Node *Min = H;

    int less = H->key;
    struct Node *now = H;
    while (now->s != NULL)
    {
        if ((now->s)->key < less)
        {
            less = (now->s)->key;
            pre = now;
            Min = now->s;
        }
        now = now->s;
    }
    struct Node *t;
    MakeHeap(&t,less);
    return t;
}
void ExtractMin(struct Node **H)
{
    if (H == NULL)
    {return;}

    struct Node* prev = NULL;
    struct Node* cur = (*H);
    struct Node* nex = cur->s;
    struct Node *min = NULL;
    
    MakeHeap(&min, Minimum(*H)->key);
    while (nex != NULL)
    {
        if (cur->key == min->key)
        { break;}
        prev = cur;
        cur = nex;
        nex = nex->s;
    }
    if (prev == NULL)
    { (*H) = nex; }
    else
    { prev->s = nex;}

    cur->s = NULL;
    struct Node* B = cur;
    cur = cur->c;
    free(B);
    struct Node* A = NULL;
    A=(struct Node*)malloc(sizeof(struct Node));
    A->p = NULL;
    A = cur;
    prev = NULL;
    nex = NULL;
    
    while (cur != NULL)
    {
        nex = cur->s;
        cur->s = prev;
        prev = cur;
        cur = nex;
    }
    A = prev;
    Union(&*H, A);
     
}
void Swap(int a[], int b[])
{
    int temp;
    temp=a[0];
    a[0]=b[0];
    b[0]=temp;
}
void DecreaseKey(struct Node **H, int x, int y)
{
    struct Node* f = Search(*H, x);
    if (f == NULL)
    {return;}
    f->key = (x-y);
    struct Node* p = f->p;

    while (p != NULL && f->key < p->key)
    {
        int a[1],b[1];
        a[0]=f->key;
        b[0]=p->key;
        //Swap(a,b);
        f->key=b[0];
        p->key=a[0];
        f = p;
        p = p->p;
    }
} 
void Delete(struct Node **H, int k)
{
    if (*H == NULL)
    {
        printf("-1\n");
        return;
    }
    struct Node *temp = Search(*H, k);

    if (temp == NULL)
    {
        printf("-1\n");
        return;
    }
    else
    {printf("%d\n", k);}

    DecreaseKey(&(*H), k, 10000);


    return ExtractMin(&*H);
}
/*
void LeftRotate(struct Node *RB,struct Node *A)
{
    /*struct Node *B = (*A)->r;
    struct Node *P = (*A)->p;
    struct Node *temp = B->l;
    B->l = (*A); (*A)->r = temp;  
    B->p = P;
    B->p->r=B; 
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
    B->p->l=B; 
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
*/
int main()
{
    int val;
    int dec;
    int ret;
    struct Node *H=NULL;
    struct Node *temp=NULL;
    struct Node *r=NULL;
    char c;
    char space;
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'i': scanf("%c",&space); 
                      scanf("%d",&val);
                      Insert(&H,val);
                      break;
            case 'd': scanf("%c",&space); 
                      scanf("%d",&val);
                      Delete(&H,val);
                      break;
            case 'p': PrintHeap(H);
                      printf("\n");
                      break;
            case 'm': r=Minimum(H);
                      if(r!=NULL)
                      {printf("%d\n",(r)->key);}
                      else
                      {printf("-1\n");}
                      break;
            case 'x': r=Minimum(H);
                      if(r!=NULL)
                      {printf("%d\n",(r)->key);ExtractMin(&H);}
                      else
                      {printf("-1\n");}                      
                      break;
            case 'r': scanf("%c",&space); 
                      scanf("%d",&val);
                      scanf("%c",&space); 
                      scanf("%d",&dec);
                      r=Search(H,val);
                      if(r!=NULL)
                      {printf("%d\n",val-dec);
                      DecreaseKey(&H,val,dec);}
                      else
                      {printf("-1\n");}
                      break;
            case 'e': return 0;
        }
    }

}