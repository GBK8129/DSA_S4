#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int k;
    int pos;
    struct Node *l;
    struct Node *r;
    struct Node *p;
   // struct Node *sib;
};
void CreateNode(struct Node **Tree, int val)
{
   *Tree=(struct Node*)malloc(sizeof(struct Node));
   (*Tree)->k = val; 
   (*Tree)->l = NULL;
   (*Tree)->r = NULL;
   (*Tree)->p = NULL;
   //(*Tree)->sib=NULL;
}
struct Node *Last(struct Node *T)
{
   while(T->l!=NULL)
   {T=T->l;}
   return (T);
}
int minDepth(struct Node *T,int i)
{
   while(T->r!=NULL)
   {T=T->r;i++;}
   return i;
}
int maxDepth(struct Node* T,int i) 
{ 
    while(T->l!=NULL)
   {T=T->l;i++;}
   return i;
} 
void Insert(struct Node **Tree, struct Node *temp)
{
    if((*Tree)==NULL)
    {(*Tree)=temp; return;}  
    else if(((*Tree)->l)==NULL)
    {temp->p=(*Tree);(*Tree)->l=temp; return;}
    else if(((*Tree)->r)==NULL)
    {temp->p=(*Tree);(*Tree)->r=temp; return;}
    else if((*Tree)->l->l==NULL)
    {temp->p=((*Tree)->l);(*Tree)->l->l=temp; return;}
    else if((*Tree)->l->r==NULL)
    {temp->p=((*Tree)->l);(*Tree)->l->r=temp; return;}
    else if((*Tree)->r->l==NULL)
    {temp->p=((*Tree)->r);(*Tree)->r->l=temp; return;} 
    else if((*Tree)->r->r==NULL)
    {temp->p=((*Tree)->r);(*Tree)->r->r=temp; return;}
     struct Node *L;
     int i=0;
     struct Node *flag=(*Tree);
     L=Last((*Tree));
     (*Tree)=Last((*Tree));
     int j=0;
     while((*Tree)!=NULL)
     { 
        if((*Tree)->p!=NULL)
        {
            (*Tree)=(*Tree)->p;
            if((*Tree)->r==NULL)
            {temp->p=(*Tree);(*Tree)->r=temp;i++;break;}
            else if((*Tree)->l==NULL)
            {temp->p=(*Tree);(*Tree)->l=temp;i++;break;}
            else if(minDepth(flag,1)==maxDepth(flag,1))
            {i=0;break;}
            else if((*Tree)->r!=NULL && j!=0 )
            {
                if((*Tree)->r->l==NULL)
                {temp->p=(*Tree)->r;(*Tree)->r->l=temp;i++;break;}
                else if((*Tree)->r->r==NULL)
                {temp->p=(*Tree)->r;(*Tree)->r->r=temp;i++;break;}
                if(j>=2 && (minDepth(*Tree,1)!=maxDepth(*Tree,1) || minDepth(*Tree,1)==j+1))
                {((*Tree)=(*Tree)->r); L=Last(*Tree);(*Tree)=L;j=0;continue;}
            }
            
        } 
        if((*Tree)->p==NULL)
        {break;}
        j++;
     }
    
     if(i==0)
     {//(*Tree)=Last((*Tree)); 
     temp->p=L;L->l=temp;}
     while((*Tree)->p!=NULL)
     {(*Tree)=(*Tree)->p;}
    // (*Tree)=L;

}
void Print(struct Node *Tree)
{
    if (Tree == NULL)
    {return;}
    printf("%d",Tree->k);

    if (Tree->l==NULL && Tree->r==NULL)
    {printf(" ");printf("( ) ( )");return;}

    printf(" "); printf("("); printf(" "); Print(Tree->l); printf(" "); printf(")"); 
   
    if (Tree->r!=NULL) 
    { printf(" "); printf("("); printf(" "); Print(Tree->r); printf(" ");printf(")"); }
    else
    {printf(" ( )");}
}

void list(struct Node *T)
{
     if(T==NULL)
     {return; }
     list(T->l); 
     printf("%d ",T->k);
     list(T->r);
}

int main()
{
    char c;
    char space;
    int n;
    struct Node *Tree=NULL;
    struct Node *temp=NULL;
    int A[100000];
    int i=0;
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'i': scanf("%c",&space);
                      scanf("%d",&n);
                      CreateNode(&temp,n);
                      Insert(&Tree,temp);
                      i++;
                      break;
/*
            case 'l': list(Tree);
                      printf("\n");
                      break;
*/
            case 'p': if(i==0)
                      {printf("( )\n");break;}
                      printf("( ");
                      Print(Tree);
                      printf(" )\n");
                      break;
            case 'e': return 0;
            
        }
    }
}
