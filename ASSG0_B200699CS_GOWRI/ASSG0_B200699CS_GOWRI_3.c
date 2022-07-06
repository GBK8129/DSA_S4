#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node
{
    struct Node *Next;
    int A;
};
struct Node* Create_Node(int in)
{  
   //x=(struct Node*)malloc(sizeof(struct Node));
   struct Node *temp;
   temp=(struct Node*)malloc(sizeof(struct Node));
   temp->A = in; temp->Next = NULL;
   return temp;
   //printf("%d\n",in);
}
void OutputLL(struct Node *L, int pos)
{
    for(int i=0;i<pos;i++)
    {L=L->Next;}
    printf("%d",L->A);
}
int InputLL(struct Node **L)
{
   //int val[100000];
   int i=0;
   /*while(scanf("%d",&val[i])!=-1)
   {
     i++;
   }
   */
   char c;
   char check;
  /* do
   {
      scanf("%d",&val[i]);
      // printf(" input: %d ",val[i]);
      i++;
      check=val[i];
      if(check=='\n')
      {break;}
      else if(check==' ')
      {continue;}
      
      scanf("%c",&c); // for space
      if(c=='\n')
      {break;}
   } while (c!='\n'||check=='\n'); */
   int ins;
   /*do
   {
       struct Node *temp;
       scanf("%d",&ins);
       check=ins;
       if(isdigit(check)!=0)
       {if(i==0)
       {
           Create_Node(ins);
           i++;
           (*L)=temp;
       }
       else
       {
           i++;
           (*L)->Next=temp; (*L)=(*L)->Next;
       }
       }
     
   } while(check!='\n'); */
   int *val ;
   val = (int *)malloc(100002 * sizeof (int));

    int *temp;

    while(scanf("%d", val+i) == 1) { 
        i++;
        if(i == 100002) {             
            temp = val;
           // len *= 2;
            val = (int *)realloc(val,100002 * 2 * sizeof (int));  
            if(val == NULL) {
              
                val = temp;
                break;
            }
        }
    }

   
  
   int j=0;
  /* for(j=0;j<=i;j++)
   {printf(" %d ",val[j]);}printf("\n"); */
   
   for(j=0;j<i;j++)
   {
       struct Node *temp;
       temp=Create_Node(val[j]);
       if(j==0)
       {(*L)=temp;}
       else
       {(*L)->Next=temp; (*L)=(*L)->Next;}
   } 
   return j+1; 
}
int main()
{
    int n;
    int k;
    struct Node *L;
    L=(struct Node*)malloc(sizeof(struct Node));
    n=InputLL(&L);
    scanf("%d",&k);
    int pos;
    pos=n-k+1;
    OutputLL(L,pos);
}