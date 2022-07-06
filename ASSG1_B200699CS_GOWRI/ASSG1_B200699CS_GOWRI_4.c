#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node
{
    int k;
    struct Node *l;
    struct Node *r;
    struct Node *p;
};
void CreateNode(struct Node **Tree, int val)
{
   *Tree=(struct Node*)malloc(sizeof(struct Node));
   (*Tree)->k = val; 
   (*Tree)->l = NULL;
   (*Tree)->r = NULL;
   (*Tree)->p = NULL;
}

void Search(struct Node *T, struct Node **temp,int s)
{
    if (T==NULL)
    {(*temp)=NULL; return;}
    if(T->k==s)
    {(*temp)=T; return;}
   /* else if(T->l!=NULL && T->l->k==s)
    {(*temp)=T->l; return;}
    else if(T->r!=NULL && T->r->k==s)
    {(*temp)=T->r;return;} */
    if(T->l!=NULL)
    {Search(T->l,temp,s);}
    if(T->r!=NULL)
    Search(T->r,temp,s);

    /*else if(T->l!=NULL && T->l->k==s)
    {return T->l;}
    else if(T->r!=NULL && T->r->k==s)
    {return T->r;} */
   /* else if(T->l->l!=NULL && T->l->l->k==s)
    {return T->l->l;}
    else if(T->l->r!=NULL && T->l->r->k==s)
    {return T->l->r;}
    else if(T->r->l!=NULL && T->r->l->k==s)
    {return T->r->l;}
    else if(T->r->r!=NULL && T->r->r->k==s)
    {return T->r->r;} */
 /*
 struct Node *flag=NULL;
    if(T->l!=NULL)
    {T=T->l;
    flag= Search((T),s);
    if(flag!=NULL)
    {return flag;}
    }
    if(T->r!=NULL)
    {T=T->r;
    flag= Search((T),s);
    if(flag!=NULL)
    {return flag;}
    }
  */ 
}
void Inorder(struct Node *T)
{
    if(T==NULL)
     { return; }
     Inorder(T->l); 
     printf("%d ",T->k);
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
int Ancestor(int A[], struct Node *T)
{
   // A[0]=T->k;
    int i=0;
    while(T!=NULL)
    {
        A[i]=(T->k); i++;
        
        if(T->p!=NULL)
        {T=T->p;continue;}
        else
        {break;}
    }
    return i;
}
int main()
{
    char s[100000];
    scanf("%[^\n]s",s);
    int length=0;
    int i=0;
    int j=0;
    int n,m;
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
    scanf("%d %d",&n,&m);
    struct Node *x=NULL;
    struct Node *y=NULL;
    int P[10000],Q[10000];
    Search(Tree,&x,n);
    Search(Tree,&y,m);
    int a=0;int b=0;

    if(x!=NULL || y!=NULL)
    {
       a= Ancestor(P,x);
       b= Ancestor(Q,y);
    }
    int c=-1,d=-1,e=-1,f=-1;
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {if(P[i]==Q[j])
         {c=i;d=j;}
        }
        if(c!=-1 && d!=-1)
        {break;}
    }
    for(i=0;i<b;i++)
    {
        for(j=0;j<a;j++)
        {if(Q[i]==P[j])
         {f=i;e=j;}
        }
        if(e!=-1 && f!=-1)
        {break;}
    }
    if((c+d)>=(e+f))
    {printf("%d\n",P[e]);}
    else
    {printf("%d\n",Q[c]);}
    //Tree=PartoBtree(s,1,j);
    //Inorder(Tree);    
    return 0;
}