#include <stdio.h>
#include <stdlib.h>
struct Edge {
  int u; 
  int v;  
  int w;  
};
struct Graph 
{
  int V;  
  int E;  
  struct Edge *edge;  
};
void Merge_Sort(int A[], int p, int q,int count[])
{   if (p < q) 
    { int mid;
        mid=(q+p)/2;
       
        Merge_Sort(A,p, mid,count);
        Merge_Sort(A,mid+1,q,count);
        //Merge(A,p,mid,q,count);    
    }
}
void InsertionSortAs (int *B)
{
  int i=0, temp, k, j=0;
   while (B[i] < 9900)
    {
      j++;
      i++;
    }

  
  for (i = 1; i < j; i++)
    {
      temp = B[i];
      k = i - 1;
      while (temp < B[k] && k >= 0)
	{
	  B[k + 1] = B[k];
	  k--;
	}
      B[k + 1] = temp;

    }
}

void InsertionSortDs (int *C)
{
  int i = 0, temp, j, k=0;
  while (C[i] < 9900)
    {
      k++;
      i++;
    }
 
  for (i = 1; i < k; i++)
    {
      temp = C[i];
      j = i - 1;
      while (temp < C[j] && j >= 0)
	{
	  C[j + 1] = C[j];
	  j--;
	}
      C[j + 1] = temp;

    }
 int D[k];
 for(i=0;i<k;i++)
 {D[i]=C[k-1-i];}
  for(i=0;i<k;i++)
 {C[i]=D[i];}
}
int Subset(int A[], int F, int x, int n, int *l)
{  
     int i,j,k; int sum,max;
    max=F; 
    for(i=x+1;i<n;i=j)
    {  
         j=i+1; 
        if(max<A[i])
        { max+=A[i];(*l)++; }
        
        while(j<n)
        {
            k=max+A[j];
            if(max<k)
            {max=k;(*l)++;}
            j++;
        }
       return max;
    }
}
void display(int arr[], int size) 
{
  int i;
  for(i = 0; i < size; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int negcycle_calcford(struct Graph *G, int strt,int n, int m) 
{
  int i, j;
  int u, v, w;
  
  int d[n];
  int p[n];
  for (i = 0; i < n; i++) 
  {
    d[i] = 99900; //Sentinel value denoting Infinity
    p[i] = 0;
  }
  
  d[strt] = 0;
 
  for(i = 1; i <= n-1; i++) {
    for(j = 0; j < m; j++) {
  
      u = G->edge[j].u;
      v = G->edge[j].v;
      w = G->edge[j].w;
      
      if(d[u] != 99900 && d[v] > d[u] + w) 
      {
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
  }
  
  for(i = 0; i < m; i++) 
  {
    u = G->edge[i].u;
    v = G->edge[i].v;
    w = G->edge[i].w;
    if(d[u] != 99900 && d[v] > d[u] + w) {
      return 1;
    }
  }
  for(i=0;i<m;i++)
  {
      int val;
      val=d[G->edge[i].u]+G->edge[i].w;
      if(d[G->edge[i].v]>val)
      {return 1;}
  }
  return -1;
}
int main() 
{  
  struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
  int n,m;
  scanf("%d",&n);
  scanf("%d",&m);
  G->V = n;  
  G->E = m;  

  G->edge = (struct Edge*)malloc(m * sizeof(struct Edge));
  
  for(int i=0;i<m;i++)
  {
      int a,b,c;
      scanf("%d",&a);
      scanf("%d",&b);
      scanf("%d",&c);
      G->edge[i].u=a;
      G->edge[i].v=b;
      G->edge[i].w=c;
  }
  int ret;
  
  ret=negcycle_calcford(G,0,n,m);  
  printf("%d\n",ret);
  
  return 0;
}

