#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct Node
{
    char E_id[5];
    int r;
    struct Node *left;
    struct Node *right;
    struct Node *p;
};
void CreateNode(struct Node **Tree, char s[], int val)
{
   *Tree=(struct Node*)malloc(sizeof(struct Node));
   strcpy((*Tree)->E_id,s);
   (*Tree)->r = val; 
   (*Tree)->left = NULL;
   (*Tree)->right = NULL;
   (*Tree)->p = NULL;
}
struct In
{
    int e; char w[5]; int A,B;
};
void read_and_store(struct Node **Tree, struct In *A[], int n)
{int i=2;
    while(i<n-1)
    {struct Node *T=NULL; 
        if(A[i]->A==999990 && A[i+1]->A==999991)
        {i+=2;
        if(A[i]->A==999990 && A[i+1]->A<999990)
        {if((*Tree)->right==NULL)
            {CreateNode(&T,A[i+1]->w,A[i+1]->e); T->p=(*Tree); (*Tree)->right=T;(*Tree)=(*Tree)->right;}i+=2;}

        continue;}
        else if(A[i]->A==999990 && A[i+1]->A<999990)
        { 
            
            if((*Tree)->left==NULL )
            {CreateNode(&T,A[i+1]->w,A[i+1]->e); T->p=(*Tree); (*Tree)->left=T;(*Tree)=(*Tree)->left;}
            else if((*Tree)->right==NULL)
            {CreateNode(&T,A[i+1]->w,A[i+1]->e); T->p=(*Tree); (*Tree)->right=T;(*Tree)=(*Tree)->right;}
            if(T!=NULL) 
            i+=2; continue;
        }
        else if(A[i]->A==999991)
        {  if((*Tree)->p!=NULL)
            {(*Tree)=(*Tree)->p;i++;}
            else
            {i++;}
        }
    }
}
void print_employee(struct Node *T)
{
    if(T==NULL)
     { return; }
     print_employee(T->left); 
     printf("%s ",T->E_id);
     print_employee(T->right);
}
int find_employee(struct Node *T,int sum[])
{
    if( T->left==NULL && T->right==NULL )
     {return T->r;}
 
    sum[0]+=find_employee(T->left,sum);

    sum[1]+=find_employee(T->right,sum);
 
    
    if (T->r >= (sum[0]+sum[1]) )
    {printf("%s ",T->E_id);}
  

}
void CreateIn(struct In **Tree, char s[], int e, int val)
{
   *Tree=(struct In*)malloc(sizeof(struct In));
   strcpy((*Tree)->w,s);
   (*Tree)->e = e; 
   (*Tree)->A= val;
   (*Tree)->B = val;
   
}
int main()
{
    char s[100000];
    scanf("%[^\n]s",s);
    int length=0;
    int i=0;
    int j=0;
    char z[1];
    z[0]='\0';
    int n,m;
    struct In *x;
    struct In *A[100000];
    while(s[i]!='\0')
     { char w[5];
        if(s[i]=='(')
        {
            CreateIn(&x,z,999990,999990);A[j]=x;j++;
        }
        else if(s[i]==')')
        {
            CreateIn(&x,z,999991,999991);A[j]=x; j++;
        }
        else if(isalpha(s[i]))
        {
            w[0]=s[i];
            w[1]=s[++i];
            w[2]=s[++i];
            w[3]=s[++i];
            i++;
            //strcpy(A[j]->w,w);
            int sum=0;
            while(isdigit(s[++i]))
            {sum=sum*10; 
             sum+=(s[i]-'0'); 
            }
            
            CreateIn(&x,w,sum,0);
            A[j]=x;
            j++; continue;
        }
        else if(s[i]==' ')
        {i++; continue;}
        i++;
     }
    int sum[2];
    sum[0]=0; sum[1]=0;
    struct Node *Tree=NULL;
    struct Node *T=NULL;
    CreateNode(&T,A[1]->w,A[1]->e);
    Tree=T;
    
    read_and_store(&Tree,A,j);
    print_employee(Tree);    
    printf("\n");
    find_employee(Tree,sum);
    return 0;
}
