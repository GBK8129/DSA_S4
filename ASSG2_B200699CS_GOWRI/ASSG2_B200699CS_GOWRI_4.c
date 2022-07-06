#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char Name[50];
    char RollNo[5];
};
void CreateNode(struct Node **H, char nm[], char rn[])
{
   (*H)=(struct Node*)malloc(sizeof(struct Node));
   strcpy((*H)->Name,nm);
   strcpy((*H)->RollNo,rn);
}
int ASCII(char a, char b, char c)
{
    int x,y,z;
    //printf("%d %d %d\n",a,b,c);
    if((a<'A' || a>'Z') && (a<'a' || a>'z'))
    {x=0;}
    else
    {x=a;}
    if((b<'A' || b>'Z') && (b<'a' || b>'z'))
    {y=0;}
    else
    {y=b;}
    if((c<'A' || c>'Z') && (c<'a' || c>'z'))
    {z=0;}
    else
    {z=c;}
    //printf("ASCII: %d %d %d\n",x,y,z);
    return ((x+y+z)%26)%10;
}
void InsertData(struct Node **H, char nm[])
{
    int i;
    int x,y,z;
    x=ASCII(nm[0],nm[1],nm[2]);
    y=ASCII(nm[0],nm[2],nm[4]);
    z=ASCII(nm[0],nm[4],nm[8]);
    //printf("xyz: %d%d%d",x,y,z);
    //printf("ASCII: %d %d %d\n",x,y,z);
    int pos;
    pos=x*100+y*10+z;
    char roll[5];
    roll[0]=nm[0];
    roll[1]=x+'0';
    roll[2]=y+'0';
    roll[3]=z+'0';
    //printf("Roll: %s\n",roll);
    struct Node *temp;
    CreateNode(&temp,nm,roll);
    //*H[pos]=temp;
    *(H+pos)=temp;
}
void Search(struct Node *H[],char rn[])
{
    int pos;
    pos=((rn[1]-'0')*100 + (rn[2]-'0')*10+(rn[3]-'0'));
    if(H[pos]==NULL || H[pos]->RollNo[0]!=rn[0])
    {printf("NOT FOUND\n"); return;}
    else 
    {printf("%s\n",H[pos]->Name); return;}
}
void Delete(struct Node **H, char rn[])
{
    int pos;
    pos=((rn[1]-'0')*100 + (rn[2]-'0')*10+(rn[3]-'0'));
    *(H+pos)=NULL;
}
int main()
{
    int age;
    //char nm[50];
    char rn[5];
    char c;
    char space;
    int i,j,k;
    char nm[50];
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
                      scanf("%s",nm);
                      InsertData(H,nm);
                      break;
            case 's': scanf("%c",&space);
                      scanf("%s",rn);
                      Search(H,rn);
                      break;
            case 'd': scanf("%c",&space);
                      scanf("%s",rn);
                      Delete(H,rn);
                      break;
            case 't': return 0;
                      
        }
    }
}