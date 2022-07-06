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
struct Node *LeftRotate(struct Node *A)
{
    struct Node *B = A->r;
    struct Node *temp = B->l;
    B->l = A;
    A->r = temp;
    return B;
}
struct Node *RightRotate(struct Node *A)
{
    struct Node *B = A->l;
    struct Node *temp = B->r;
    B->r = A; A->l = temp;
    return B;
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
struct Node *Search(struct Node *A,int k)
{ 
  if (A == NULL)
       {return NULL;}
   if  (A->key == k)
       {return A;}
    if (A->key < k)
       {return Search(A->r, k);}
    if (A->key > k)    
       {return Search(A->l, k);}
}
int GetBalance(struct Node *A,int k)
{
    struct Node *T=Search(A,k);
    //printf("Search: %d\n", T->key)
    if(T==NULL)
    {printf("FALSE\n"); return 999000;}
    if(T->l == NULL && T->r== NULL)
    { return 0; }
    
    int lh=Height(T->l);
    int rh=Height(T->r);
    //printf("L:%d R:%d\n",lh,rh);
    return (lh-rh);

}
int Balance(struct Node *A)
{   
    if((A)==NULL)
    {return 0;}
    int lh=Height(A->l);
    int rh=Height(A->r);
    //printf("L:%d R:%d\n",lh,rh);
    return (lh-rh);
}
void MakeAVL(struct Node **A)
{
    if((*A)==NULL)
    {return;}
    MakeAVL(&(*A)->l);
    int balance= Balance(*A);
    if (balance > 1 && Balance((*A)->l) >= 0)
    {RightRotate(*A);return;}
    if (balance > 1 && Balance((*A)->l) < 0)
    {(*A)->l =  LeftRotate((*A)->l); (*A)=RightRotate(*A); return;}
    if (balance < -1 && Balance((*A)->r) <= 0)
    {LeftRotate(*A);return;}
    if (balance < -1 && Balance((*A)->r) > 0)
    {(*A)->r = RightRotate((*A)->r); (*A)=LeftRotate(*A); return;}
    MakeAVL(&(*A)->r);
}
void Insert(struct Node **A, struct Node *temp)
{
  if ((*A) == NULL)
        (*A)=temp;
 
    if (temp->key < (*A)->key)
        Insert(&(*A)->l, temp);
    else if (temp->key > (*A)->key)
        Insert(&(*A)->r, temp);

    int balance;
    balance= Balance(*A);

    if (balance > 1 && temp->key < (*A)->l->key)
        {(*A)=RightRotate(*A); return ;}
    if (balance < -1 && temp->key > (*A)->r->key)
        {(*A)=LeftRotate(*A);  return;}
    if (balance > 1 && temp->key > (*A)->l->key)
        {(*A)->l =  LeftRotate((*A)->l); (*A)=RightRotate(*A); return;}
    if (balance < -1 && temp->key < (*A)->r->key)
        {(*A)->r = RightRotate((*A)->r); (*A)=LeftRotate(*A); return;}  
    
   //Balance(*A);
}
struct Node *Minimum(struct Node* T)
{
   while(T->r!=NULL)
   {T=T->r;}
   return T;
}
void DeleteNode(struct Node **A,int k)
{
    
    if ((*A) == NULL)
        {return;}
    if ( k < (*A)->key )
        DeleteNode(&(*A)->l, k);
    else if( k > (*A)->key )
        DeleteNode(&(*A)->r, k);
    else
    {
        if( ((*A)->l == NULL) || ((*A)->r == NULL) )
        {
            struct Node *temp=NULL;
            if ((*A)->l==NULL && (*A)->r!=NULL)
            {temp=(*A)->r;} 
            else if ((*A)->l!=NULL && (*A)->r==NULL)
            {temp=(*A)->l;} 
 
            if (temp == NULL)
            { temp = (*A); (*A) = NULL; }
            else
            *A = temp;
        }
        else
        {
            struct Node* temp;
            temp = Minimum((*A)->r);
            (*A)->key = temp->key;
            DeleteNode(&(*A)->r, temp->key);
        }
    }
 
    if ((*A) == NULL)
      {return;}
 
    int balance = Balance(*A);
 
    if (balance > 1 && Balance((*A)->l) >= 0)
    {RightRotate(*A);return;}
    if (balance > 1 && Balance((*A)->l) < 0)
    {(*A)->l =  LeftRotate((*A)->l); (*A)=RightRotate(*A); return;}
    if (balance < -1 && Balance((*A)->r) <= 0)
    {LeftRotate(*A);return;}
    if (balance < -1 && Balance((*A)->r) > 0)
    {(*A)->r = RightRotate((*A)->r); (*A)=LeftRotate(*A); return;}
}

void PrintTree(struct Node *A)
{
     if (A == NULL)
    {return;}
    printf("%d",(A->key));

    if (A->l==NULL && A->r==NULL)
    {printf(" ");printf("( ) ( )");return;}
    printf(" "); printf("("); printf(" "); 
    if(A->l!=NULL)
    {PrintTree(A->l); printf(" ");}
    printf(")"); 
   
    printf(" "); printf("("); printf(" "); 
    if(A->r!=NULL)
    {PrintTree(A->r); printf(" ");}
    printf(")"); 
    
}
int main()
{
    char c;
    char space;
    int val;
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
                  //MakeAVL(&A);
                  break;
        case 'd': scanf("%c",&space);
                  scanf("%d",&val);
                  temp=Search(A,val);
                  if(temp!=NULL)
                  {printf("%d\n",temp->key);}
                  else
                  {printf("FALSE\n");}
                  DeleteNode(&A,val);
                  //MakeAVL(&A);
                  break;
        case 's': scanf("%c",&space);
                  scanf("%d",&val);
                  temp=Search(A,val);
                  if(temp!=NULL)
                  {printf("TRUE\n");}
                  else
                  {printf("FALSE\n");}
                  break;
        case 'b': scanf("%c",&space);
                  scanf("%d",&val);
                  int i=GetBalance(A,val);
                  if(i!=999000)
                  {printf("%d\n",i);}
                  break;
        case 'p': if(A==NULL)
                  {printf("( )\n"); break;}
                  printf("( ");
                  PrintTree(A);
                  printf(" )\n");
                  break;
        case 'e': return 0;

        }
    }
}