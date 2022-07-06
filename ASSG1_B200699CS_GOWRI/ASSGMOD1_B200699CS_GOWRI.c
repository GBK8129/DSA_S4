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
void Search(struct Node *T, struct Node **temp,int s)
{
    if (T==NULL)
    {(*temp)=NULL; return;}
    if(T->key==s)
    {(*temp)=T; return;}
   
    if(T->l!=NULL)
    {Search(T->l,temp,s);}
    if(T->r!=NULL)
    Search(T->r,temp,s);

  
}
int Iteration(struct Node *T, int i, int n,int Sum[], int last)
{
   
  if(i>n)
      {return 0;}
    if(T->l!=NULL && last != T->l->key)
     {
        printf("T->l->key %d \n", T->l->key); 
         Sum[0]+=T->l->key+Iteration(T->l,i+1,n,Sum,T->key); 
     }
    if(T->r!=NULL && last != T->r->key)
     {
         printf("T->r->key %d \n", T->r->key); 
         Sum[0]+=T->r->key+Iteration(T->r,i+1,n,Sum,T->key); 
     }
     if(T->p!=NULL && last != T->p->key)
     {
         printf("T->p->key %d \n", T->p->key); 
         Sum[0]+=T->p->key+Iteration(T->p,i+1,n,Sum,T->key); 
     } 
    return 0;
    
}
void Planner(struct Node *Tree,int S,int n)
{
    if(Tree==NULL)
    {printf("0");return;}
    struct Node *T=NULL;
    Search(Tree,&T,S);
    if(T->l!=NULL && T->l->key==S)
    {T=T->l;}
    else if(T->r!=NULL && T->r->key==S)
    {T=T->r;}
    
    int Sum[1];
    Sum[0]=T->key;
    
    //printf("Here %d %d\n",Sum,Tree->key);
    if(T!=NULL)
    {Iteration(T,1,n,Sum,T->key);}
    
    printf("%d",Sum[0]);
}
void Inorder(struct Node *T)
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
  
    BinaryTree(&Tree,A,j);
    //Inorder(Tree);
    int S,n;
    scanf("%d %d",&S,&n);
    Planner(Tree,S,n);
    return 0;
}