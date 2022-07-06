#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char key[50];
    struct Node *Next;
};
int CreateNode(struct Node **H, char val[])
{
   (*H)=(struct Node*)malloc(sizeof(struct Node));
   strcpy((*H)->key,val);
   (*H)->Next=NULL;
   int c=0;
   while(val[c]!='\0')
   {c++;}
   return c;
}
struct Node *Insert(struct Node **H,struct Node *T)
{
    
    int i;
    if(*H==NULL )
    {*H=T; return *H;}
    int c;
    int x=0;
    struct Node *temp;
    temp=(*H);
    struct Node *t;
    t=(*H);
    while(t!=NULL)
    {
       if(!strcmp(T->key,(t)->key))
       {x++;return (*H);}
       t=t->Next;
    }
        while((temp)->Next!=NULL)
        {(temp)=(temp)->Next;}
        (temp)->Next=T;
        return (*H);  

}
void Print(struct Node *H[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d:",i);
        if(H[i]==NULL)
        {printf("null");}
        else
        {
            printf("%s",H[i]->key);
            while(H[i]->Next!=NULL)
            { H[i]=H[i]->Next; printf("-%s",H[i]->key);}
        }
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d\n",&n);
    char s[100000];
    scanf("%[^\n]s",s);
    //printf("\n%s",s);
    int i,j;
    int c=0;
    int size;
    struct Node *H[n];
    for(i=0;i<n;i++)
    {H[i]=NULL;}
    char val[50];
    struct Node *t;
    for(i=0;s[i]!='\0';i++)
    {
    
      val[j]=s[i];
      j++;
      if(s[i+1]==' ' || s[i+1]=='\0')
      {
          j=0;
          size=CreateNode(&t,val);
          int pos=(size*size)%n;
         // printf("\nSize: %d %d\n",pos,size);
          H[pos]=Insert(&H[pos],t);
          
          while(val[c]!='\0')
          {val[c]='\0'; c++;}
          c=0;
          i++;
          continue;
      }
    }
  
    Print(H,n);
    return 0;
}