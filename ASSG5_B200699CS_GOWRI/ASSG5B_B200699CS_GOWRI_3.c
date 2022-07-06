#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Dijkstra_Calc(int n, int Graph[][n], int start) 
{
  int d[n], p[n];
  int cost[n][n];
  int reach[n];
  int  min_dist, next;
  int c; 
  int i, j;
  for(i=0;i<n;i++)
  {d[i]=-1;}

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == -5)
        cost[i][j] = 99900;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    d[i] = cost[start][i];
    p[i] = start;
    reach[i] = 0;
  }

  d[start] = 0;
  reach[start] = 1;
  c = 1;

  while (c < n - 1) {
    min_dist = 99900;

    for (i = 0; i < n; i++)
      if (d[i] < min_dist && !reach[i]) {
        min_dist = d[i];
        next = i;
      }

    reach[next] = 1;
    for (i = 0; i < n; i++)
      if (!reach[i])
        if (min_dist + cost[next][i] < d[i]) {
          d[i] = min_dist + cost[next][i];
          p[i] = next;
        }
    c++;
  }
  int max=d[0];
  for(i=1;i<n;i++)
  {
      if(max<d[i])
      {max=d[i];}
  }
  printf("%d ",start);
  for (i = 0; i < n; i++)
  {
    if (i != start) 
    {
        if(d[i]!=99900)
         {
             printf("%d ",d[i]);
         }
         else
         {
             printf("INF ");
         }
    }
  }
  printf("\n");
  return;
}
void Dijkstra_Destination(int n, int Graph[][n], int start, int end) 
{
  int d[n], p[n];
  int cost[n][n];
  int reach[n];
  int  min_dist, next;
  int c; 
  int i, j;
  for(i=0;i<n;i++)
  {d[i]=-1;}

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == -5)
        cost[i][j] = 99900;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    d[i] = cost[start][i];
    p[i] = start;
    reach[i] = 0;
  }

  d[start] = 0;
  reach[start] = 1;
  c = 1;

  while (c < n - 1) {
    min_dist = 99900;

    for (i = 0; i < n; i++)
      if (d[i] < min_dist && !reach[i]) {
        min_dist = d[i];
        next = i;
      }

    reach[next] = 1;
    for (i = 0; i < n; i++)
      if (!reach[i])
        if (min_dist + cost[next][i] < d[i]) {
          d[i] = min_dist + cost[next][i];
          p[i] = next;
        }
    c++;
  }
  /*
    for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source to %d: %d", i, d[i]);
    }
    */
   if(d[end]!=99900)
    {
        printf("%d\n",d[end]);
    }
   else
   {
       printf("UNREACHABLE\n");
   }
  return;
}
int main() 
{
    int n;
  scanf("%d",&n);
  int G[n][n];
  int i, j, u;
  for(i=0;i<n;i++)
  {
      for(j=0;j<n;j++)
      {G[i][j]=-5;}
  }
  /*
 for(i=0;i<n;i++)
 {
     for(j=0;j<n;j++)
     {printf("%d ",G[i][j]);}
     printf("\n");
 }
 */
  int val;
  char space;
 
  for(i=0;i<n;i++)
  {
    scanf("%d%c",&val,&space);
    //printf("Val: %d space:%c\n",val,space);
    while(space!='\n')
    {
        scanf("%d%c",&u,&space);
        G[val][u]=-2;
    }
  }
  for(i=0;i<n;i++)
  {
    scanf("%d%c",&val,&space);
    while(space!='\n')
    {
        scanf("%d%c",&u,&space);
        for(j=0;j<n;j++)
        {
            if(G[val][j]==-2)
            {
                G[val][j]=u; break;
            }
        }
    }
  }
  /*
 for(i=0;i<n;i++)
 {
     for(j=0;j<n;j++)
     {printf("%d ",G[i][j]);}
     printf("\n");
 }
 */
  char comm[5]; int source,dest;
  while(1)
  {
     scanf("%s",comm);
     if(!strcmp(comm,"apsp"))
     {
        scanf("%d",&source);
        Dijkstra_Calc(n,G, source);
     }
     else if(!strcmp(comm,"sssp"))
     {
        scanf("%d",&source);
        scanf("%d",&dest);
        Dijkstra_Destination(n,G, source,dest);
     }
     else if(!strcmp(comm,"stop"))
     {
         break;
     }
  }
 

  return 0;
}