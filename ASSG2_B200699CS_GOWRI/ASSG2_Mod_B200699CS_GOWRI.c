#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct DataNode
{
    char key[1000];
    struct DataNode *Next;
};
void CreateNode(struct DataNode **H, char s[])
{
   (*H)=(struct DataNode*)malloc(sizeof(struct DataNode));
   strcpy((*H)->key,s);
   (*H)->Next = NULL;
}
void Insert(struct DataNode **H, struct DataNode *temp)
{
    if(((*H)==NULL))
     {(*H)=temp; return;}
     
    while((*H)->Next!=NULL)
     {(*H)=(*H)->Next;}
    (*H)->Next=temp;
}
void Delete(struct DataNode **H, char s[])
{//printf("%s",(*H)->key);
    if((*H)==NULL)
    {return;}
    while((*H)!=NULL)
    {  
        if(!strcmp((*H)->key,s))
        {
            if((*H)->Next!=NULL)
            {
               // printf("Del:%s",(*H)->key);
                (*H)=(*H)->Next;return;
            }
            else
            {
                (*H)=NULL;return;
            }
        }
        if((*H)->Next!=NULL)
        {(*H)=(*H)->Next;}
        else
        {return;}
        
    }
}
int Check(struct DataNode *H[],int n)
{
    int i;
    for(i=0;i<n;i++)
    { 
        if(H[i]!=NULL)              // added 
        {  if(H[i]->Next!=NULL)
        {return -1;}}
    }
    return 1;
}
int Hash(char s[],int n)
{
    int i;
    int k=0;
    for(i=0;s[i]!='\0';i++)
    {k++;}
    int pos[k];
    int val;
    k=k-1;
    for(i=0;i<=k;i++)
    {
        if(s[i]>=97 && s[i]<=122)
        {val=s[i]-96;}
        else if(s[i]>=65 && s[i]<=90)
        {val=s[i]-64;}
        pos[i]=val;
    }
    int pro;
    int j;
    
    int sum=0;
    for(i=0;i<=k;i++)
    {   pro=1;
        for(j=0;j<i;j++)
        {pro*=3;}
        sum+=pos[i]*pro;
    }
    sum=sum%n;
    return sum;
    
}
int main()
{
    char coll;
    int n;
    scanf("%d",&n);
    struct DataNode *H[n]; 
   //Hash = (struct DataNode*) malloc(m * sizeof(struct DataNode));
    struct DataNode *temp=NULL;
    for(int i=0;i<n;i++)
    {H[i]=NULL;}
    char s[1000];
    char c;
    char space;
    int pos;

    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'i': scanf("%c",&space);
                      scanf("%s",s);
                      CreateNode(&temp,s);
                      
                      pos= Hash(s,n);
                      //printf("%d\n", pos);
                      Insert(&H[pos],temp);
                      break;
            case 'd': scanf("%c",&space);
                      scanf("%s",s);
                      pos= Hash(s,n);
                      Delete(&H[pos],s);
                      break;
            case 'p': printf("%d\n",Check(H,n));
                      break;
            case 't': return 0;
        }
    }
}