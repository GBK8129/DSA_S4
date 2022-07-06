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
void Inorder(struct Node *T)
{
    if(T==NULL)
     { return; }
     Inorder(T->l); 
     printf("%d ",T->key);
     Inorder(T->r);
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
int BST_Size(struct Node *T) 
{ 
    if (T == NULL) 
        return 0; 
    else
        return(BST_Size(T->l)+BST_Size(T->r)+1); 
} 
int check(struct Node *Tree, struct Node *T)
{
    if (Tree!=NULL)
    {
        if (check(Tree->l,T)!=1)
          return 0;
        if (T!=NULL && Tree->key<=T->key)
          return 0;
        T=Tree;
        return check(Tree->r, T);
    }
    return 1;
}
struct Node *BST(struct Node *Tree, int val)
{ 
   struct Node *T = NULL;
   //bool b;
   //int a=0,b=0,c=0;
   if(check(Tree, T)==1)
   {return Tree;}
   else if(check(Tree->l, T)==1)
   {return Tree->l;}
   else if(check(Tree->r, T)==1)
   {return Tree->r;}


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
    //Tree=PartoBtree(s,1,j);
    Inorder(Tree); printf("\n");
    T=BST(Tree,0);   
    printf("%d\n",BST_Size(T));
    return 0;
}