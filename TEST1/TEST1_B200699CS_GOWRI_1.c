#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char key[50];
    struct Node *Next;
};
int find_hash1(char w[], int n)
{
    int j; int i=0;
    for(j=0;w[j]!='\0';i++)
    {i++;}
    if(i==1)
    {return (2*(w[0]-(4*'0')))%n;}
    else
    {return ((w[0]+w[1]+w[i-1]+w[i-2]-(4*'0'))/i)%n;}
}
int find_hash2(char w[],int n)
{
    int j; int i=0;
    for(j=0;w[j]!='\0';i++)
    {i++;}
    int sum=0;
    for(i=0;w[i]!='\0';i++)
    {sum+=w[i];}
    return sum/i%n;
}
void CreateNode(struct Node **H, char w[])
{
   *H=(struct Node*)malloc(sizeof(struct Node));
   (*H)->Next = NULL; 
   strcpy((*H)->key,w);
}
void store_word(struct Node **Hg, struct Node **Hh,char w[], int n, int g, int h)
{
    int k=0,l=0;  int j;
    char t[50]; int i=0;
    
    for(j=0;w[j]!='\0';i++)
    {k++;}
    struct Node *temp;
    struct Node *x;
    x=*Hg;
    CreateNode(&temp,w);
    if (x==NULL)
    {*Hg=temp; return;}
    else
    {
       strcpy(t,x->key);
       for(j=0;t[j]!='\0';i++)
       {l++;}
       if(k<l)
       {  
            while(x->Next!=NULL)
             {strcpy(t,x->Next->key); i=0;
               for(j=0;t[j]!='\0';i++)
                 {l++;}
                 if(k>l)
                 {i=1;break;}
                 else if(k<l)
                 {
                     x=x->Next; continue;
                 }
                 else
                 {i=1;break;}
            }  
            if(i==1)
            {temp->Next=x->Next;
             x->Next=temp;   i=0;
             return;}
            
       }     
      else if(k>l)
        {temp->Next=x; *Hg=temp; return;}
            
       
       
    
     if(*Hh==NULL)
      {*Hh=temp; return;}
       x=*Hh;
       
      while(x->Next!=NULL)
      {
          x=x->Next;

      }
      x->Next=temp;
    }
       
}

void print_table(struct Node *H[],  int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(H[i]==NULL)
        {
            printf("NULL"); continue;
        }
        else
        {
            while(H[i]->Next !=NULL)
            {printf("%s ",H[i]->key); H[i]=H[i]->Next;}
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
    char w[50];
    struct Node *t;
    for(i=0;s[i]!='\0';i++)
    {
    
      w[j]=s[i];
      j++;
      if(s[i+1]==' ' || s[i+1]=='\0')
      {
          j=0;
          c=0;
          for(c=0; c<50; c++)
          { w[c]='\0';}
          i++;
          int g,h;
          
          g=find_hash1(w, n);
          h=find_hash2(w, n);
          store_word(&H[g],&H[h],w,n,g,h); 
          continue;
      }
    }
  
    print_table(H,n);
    return 0;
}