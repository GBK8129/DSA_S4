#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node
{
    int key;
    struct Node *l;
    struct Node *r;
    struct Node *p;
};
void CreateNode(struct Node **Tree, int val)
{
   *Tree=(struct Node*)malloc(sizeof(struct Node));
   (*Tree)->key = val; 
   (*Tree)->l = NULL;
   (*Tree)->r = NULL;
   (*Tree)->p = NULL;
   //(*Tree)->sib=NULL;
}
void BinaryTree(struct Node **Tree, int A[], int n)
{int i=2;
    while(i<n-1)
    {struct Node *T=NULL; 
        if(A[i]==999990 && A[i+1]==999991)
        {i+=2;
        if(A[i]==999990 && A[i+1]<999990)
        {if((*Tree)->r==NULL)
            {CreateNode(&T,A[i+1]); T->p=(*Tree); (*Tree)->r=T;(*Tree)=(*Tree)->r;}i+=2;}

        continue;}
        else if(A[i]==999990 && A[i+1]<999990)
        { 
            
            if((*Tree)->l==NULL )
            {CreateNode(&T,A[i+1]); T->p=(*Tree); (*Tree)->l=T;(*Tree)=(*Tree)->l;}
            else if((*Tree)->r==NULL)
            {CreateNode(&T,A[i+1]); T->p=(*Tree); (*Tree)->r=T;(*Tree)=(*Tree)->r;}
            if(T!=NULL) 
            i+=2; continue;
        }
        else if(A[i]==999991)
        {  if((*Tree)->p!=NULL)
            {(*Tree)=(*Tree)->p;i++;}
            else
            {i++;}
        }
    }
}
/*
void Less(struct Node *Tree, int c, int *val)
{ 
 if(Tree==NULL)
  { return;}
      if((Tree->key)>c)
      {val++;return;}
      if(Tree->l!=NULL)
      {Less(Tree->l,c,val);}
      if(Tree->r!=NULL)
      {Less(Tree->r,c,val);}      

}
void More(struct Node *Tree, int c, int *val)
{ 
   if(Tree==NULL)
  {return;}
      if((Tree->key)<c)
      {val++;return;}
      if(Tree->l!=NULL)
      {Less(Tree->l,c,val);}
      if(Tree->r!=NULL)
      {Less(Tree->r,c,val);} 
} */
void CheckL(struct Node *T, int c)
{
    int val;
    if(T==NULL)
    {c=0;return;}
    if(T->r!=NULL)
    {val=T->r->key;}
    
    if(T->l!=NULL && T->l->key>T->key)
    {c++;}
    else if(T->r!=NULL && T->r->key<T->key)
    {c++;}
    else if(T->r!=NULL && T->r->key>T->key)
    {
      while(T->p!=NULL)
      {if(val>T->p->key)
       {c++;break;}
       else
       {T=T->p;}
      }
    }
}
void CheckR(struct Node *T, int c)
{
    int val;
    if(T==NULL)
    {c=0;return;}
    if(T->l!=NULL)
    {val=T->l->key;}
  
    //
    if(T->r!=NULL && T->r->key<T->key)
    {c++;}
    else if(T->l!=NULL && T->l->key>T->key)
    {c++;}
    else if(T->l!=NULL && T->l->key<T->key)
    {
      while(T->p!=NULL)
      {if(val<T->p->key)
       {c++;break;}
       else
       {T=T->p;}
      }
    }   
}
void BST(struct Node *Tree, int *val)
{
    if(Tree==NULL)
    {return;}
    int x=0,y=0,z=0;
   if(Tree->r!=NULL && Tree->l!=NULL)
  { if((Tree->r->key)<(Tree->key) || (Tree->l->key)>(Tree->key))
   {z+=2;} }
   
   if(z!=0)
   {(*val)+=z;printf("%d\n",*val); }
   else
   { 
     if(Tree->l!=NULL)
       {CheckR(Tree->l,x);} 
     if(Tree->r!=NULL)
       {CheckR(Tree->r,y);}
   }
   if(x!=0 && y!=0)
   {(*val)+=2;return;}
   else if(x==0 && y!=0)
   {
       (*val)++; 
       if(Tree->l!=NULL)
       {CheckR(Tree->l,x);}
   }
   else if(y==0 && x!=0)
   {
       (*val)++; 
       if(Tree->r!=NULL)
       {CheckR(Tree->r,y);}
   }
   else
   {
       if(Tree->l!=NULL)
       {BST(Tree->l,&x);}
       if(Tree->r!=NULL)
       {BST(Tree->r,&y);}
   }

}
/*{ int comp=0;int c;
  if(Tree==NULL)
  {printf("%d\n",val);return;}
   c=Tree->key;
   Less(Tree->l,c,&val);
   More(Tree->r,c,&val);
   if(val!=0)
   {printf("%d\n",val);return;}
   //BST(Tree,val);
   if(Tree->l!=NULL)
     {c=(Tree)->l->key;BST(Tree->l,val);}
   if(Tree->r!=NULL)
     {c=(Tree)->r->key;BST(Tree->r,val);} */
  /*
    while(1)
    {
     (Tree)->key;
     Less(Tree->l,c,&val);
     More(Tree->r,c,&val);
     if(val!=0)
     {break;}
     if(Tree->l!=NULL)
     {c=(Tree)->l->key;BST(Tree->l);}
     if(Tree->r!=NULL)
     {c=(Tree)->r->key;BST(Tree->r);}
     if(val!=0)
     {break;}
    }
 printf("%d\n",val); 
}  */
void Inorder(struct Node* T)
{
    if(T==NULL)
     { return; }
     Inorder(T->l); 
     printf("%d ",T->key);
     Inorder(T->r);
}
int main()
{
    char s[100000];
    scanf("%[^\n]s",s);
    int length=0;
    int i=0;
    int j=0;
    int A[100000];
    while(s[i]!='\0')
     {
        if(s[i]=='(')
        {
            A[j]=999990; j++;
        }
        else if(s[i]==')')
        {
            A[j]=999991; j++;
        }
        else if(isdigit(s[i]))
        {
            A[j]= s[i]-'0';
            //j++;
            while(isdigit(s[++i]))
            {A[j]=A[j]*10; 
             A[j]+=s[i]-'0'; 
            }
            j++; continue;
        }
        else if(s[i]==' ')
        {i++; continue;}
        i++;
     }
    /*for(i=0;i<j;i++)
    {printf("%d ",A[i]);} printf("\n"); */
    struct Node *Tree=NULL;
    struct Node *T=NULL;
    CreateNode(&T,A[1]);
    Tree=T;
    //printf("Segfault\n");
    BinaryTree(&Tree,A,j);
    //Tree=PartoBtree(s,1,j);
    //printf("Seg\n");
    //printf("%d\n",Tree->key);
    //Inorder(Tree); 
    int v=0;
    BST(Tree,&v); 
    //printf("%d\n",v);
    return 0;
}