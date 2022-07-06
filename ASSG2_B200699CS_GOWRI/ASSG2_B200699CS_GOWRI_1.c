#include<stdio.h>
#include<stdlib.h>
struct DataNode
{
    int key;
    int index;
};
void CreateNode(struct DataNode **H, int val, int m)
{
   (*H)=(struct DataNode*)malloc(sizeof(struct DataNode));
   (*H)->index = val%m;
   (*H)->key = val;
}
void HashTable(struct DataNode **H, int m)
{
    (*H)=(struct DataNode*)malloc(sizeof(struct DataNode));
    (*H)=NULL;  
}
int Insert(struct DataNode **H, struct DataNode *temp)
{
 // int pos=temp->index;
 
  if((*H==NULL))
  {(*H)=temp; return 1;}
  else
  {return 0;}
}

int Search(struct DataNode *H[], int s, int m)
{
  for(int i=0;i<m;i++)
  {
      if(H[i]!=NULL && (H[i]->key)==s)
      {return 1;}
  }  
  return -1;
}
void Delete(struct DataNode *H[], int d, int m)
{
for(int i=0;i<m;i++)
  {
      if(H[i]!=NULL && (H[i]->key)==d)
      {H[i]=NULL; return;}
  }  
}
void Print(struct DataNode *H[], int m)
{
for(int i=0;i<m;i++)
  {
      if(H[i]==NULL)
      {printf("%d ()\n",i);}
      else
      {printf("%d (%d)\n",i,H[i]->key);}
     
  }  
}
int Prime(int m)
{
    int p=3;
    int i;
    int c=0;
    int flag=-999000;
    if(m==3)
    {return 2;}
    while(p<m)
    {c=0;
    for(i=2;i<p;i++)
    {if(p%i==0)
      {c++;}
    }
    if(c==0)
    {flag=p;}
    p++;
    }
    if(flag!=-999000)
    {
        return flag;
    } 
}
void DHashing(struct DataNode *H[], struct DataNode *temp, int m, int R)
{
    int i;
    int pos;
    int h1=temp->index;
    int h2=R-((temp->key)%R);
    for(i=0;i<m;i++)
    {
       pos=(h1+(h2*i))%m;
       if(*(H+(pos))==NULL)
       {(*H)[pos].key=temp->key; (*H)[pos].index=pos; return;}
       h1=pos;
    }
}
int main()
{
    char coll;
    int m;
    scanf("%c",&coll);
    scanf("%d",&m);
    int c1,c2;
    if(coll=='a')
    {
        scanf("%d %d",&c1,&c2);
    }
    struct DataNode *Hash[m]; 
   // Hash = (struct DataNode*) malloc(m * sizeof(struct DataNode));
    struct DataNode *temp=NULL;
    for(int i=0;i<m;i++)
    {HashTable(&(Hash[i]),m);}
    //Hash=NULL;
    char c;
    char space;
    int val;
    int r;
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'i': scanf("%c",&space);
                      scanf("%d",&val);
                      CreateNode(&temp,val,m);
                      int pos=temp->index;
                      r=Insert(&Hash[pos],temp);
                      
                      if(r==0)
                      {
                          if(coll=='a')
                          {
                              int h1=temp->index;
                              for(int i=0;i<m;i++)
                               {
                                 pos=(h1+(c1*i)+(c2*i*i));
                                 //printf("%d\n",pos);
                                 if(pos>=m)
                                 {pos=pos-m;}
                                 int k;
                                 k=Insert(&Hash[pos],temp);
                                 if(k==0)
                                 {continue;}
                                 else if(k==1)
                                 {Hash[pos]->index=pos; break;}
                               }
                              
                          }
                          else if(coll=='b')
                          {
                              int R;
                              R=Prime(m);
                              //DHashing(Hash,temp,m,R);
                              int h1=temp->index;
                              int h2=R-((temp->key)%R);
                              for(int i=0;i<m;i++)
                              {
                               pos=(h1+(h2*i))%m;
                               if(pos>=m)
                                 {pos=pos-m;}
                               int k;
                               k=Insert(&Hash[pos],temp);
                                 if(k==0)
                                 {continue;}
                                 else if(k==1)
                                 {Hash[pos]->index=pos; break;}
                              }
                          }
                      }
                      break;
            case 's': scanf("%c",&space);
                      scanf("%d",&val);
                      r=Search(Hash,val,m);
                      printf("%d\n",r);
                      break;
            case 'd': scanf("%c",&space);
                      scanf("%d",&val);
                      Delete(Hash,val,m);
                      break;
            case 'p': Print(Hash,m);
                      break;
            case 't': return 0;
        }
    }
}