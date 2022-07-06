#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char firstName[50];
    char lastName[50];
    int age;
    struct Node *p;
    struct Node *l;
    struct Node *r;
};
void CreateNode(struct Node **H, char fn[], char ln[], int age)
{
   (*H)=(struct Node*)malloc(sizeof(struct Node));
   strcpy((*H)->firstName,fn);
   strcpy((*H)->lastName,ln);
   (*H)->age = age;
   (*H)->p=NULL;
   (*H)->l=NULL;
   (*H)->r=NULL;
}
void BinarySearchTree(struct Node **Tree, struct Node *T)
{
  if(*(Tree)==NULL)
  { 
     *(Tree)=T;
     return;
  }
     T->p=(*Tree);
     if (T->age < (*Tree)->age)
       { BinarySearchTree(&(*Tree)->l, T); }
     else if (T->age > (*Tree)->age)
       { BinarySearchTree(&(*Tree)->r, T); }
}
void InsertData(struct Node **H, char fn[],char ln[], int age)
{
  struct Node *temp;
  CreateNode(&temp,fn,ln,age);
  if((*H==NULL))
  {(*H)=temp; }
  else
  {
      BinarySearchTree(H,temp);
  }
}
int ASCII(char ln[])
{
    int sum=0;
    for(int i=0;ln[i]!='\0';i++)
    {
       sum+=ln[i];
    }
    return sum;
}
struct Node *SearchAge(struct Node* T, char fn[], char ln[])
{
    if(T == NULL)
    {return NULL;}
    if(strcmp(T->firstName,fn)==0)
    {return T;}
    if(T->r!=NULL)
    {return SearchAge(T->r,fn,ln);}
    if(T->l!=NULL)
    {return SearchAge(T->l,fn,ln);}
}
struct Node *PrintRelative(struct Node* T, int k)
{
   if(T==NULL)
   {return NULL;}
   printf("%s %s %d\n",T->firstName,T->lastName,T->age);
   if (T->age == k)
       {return T;}
   if (T->age < k)
       {return PrintRelative(T->r,k);}
   if (T->age > k)    
       {return PrintRelative(T->l,k);}
}
void Inorder(struct Node* T)
{
    if(T==NULL)
     { return; }
     if(T->l!=NULL)
     {Inorder(T->l);}
     printf("Inorder: %d %s %s\n",T->age,T->firstName,T->lastName);
     if(T->r!=NULL)
     {Inorder(T->r);}
}
int main()
{
    int age;
    char fn[50];
    char ln[50];
    char c;
    char space;
    int i,j,k;
    int ascii;
    int pos;
    struct Node *temp;
    struct Node *H[128];
    for(i=0;i<128;i++)
    {H[i]=NULL;}
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'i': scanf("%c",&space);
                      scanf("%s",fn);
                      scanf("%s",ln);
                      scanf("%d",&age);
                      ascii= ASCII(ln);
                      pos=ascii%128;
                      InsertData(&H[pos],fn,ln,age);
                      break;
            case 'p': scanf("%c",&space);
                      scanf("%s",fn);
                      scanf("%s",ln);
                      ascii= ASCII(ln);
                      pos=ascii%128;
                      struct Node *T;
                      T=SearchAge(H[pos],fn,ln);
                      if(T==NULL)
                      {printf("-1\n"); break;}
                      /*else
                      {printf("Search Age: %d %s %s\n",T->age,T->firstName,T->lastName);} */
                      struct Node *X;
                      //Inorder(H[pos]);
                      X=PrintRelative(H[pos],T->age);
                      break;
            case 't': return 0;
                      
        }
    }
}
