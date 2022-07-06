#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
//KRUS
struct node_k
{
	int key;
	int weight;
	struct node_k *next;
};
struct ver_k
{
	int u;
	int v;
	int w;
	struct ver_k *next;
};
struct node_sing  // each node
{
	int key;
	int rep;
	int weight;
	char color;
};

//PRIM
struct Edge
{
	int u,v,w;
};

struct Vert
{
	int ver1,ver2;
};
struct Edge Adj[1000][1000];
int n;
int reach[1000],s[1000];
struct Vert Heap[1000];
int Index[1000],sizeofheap;
//Utility Function
void Max_Heapify(struct Vert *x, int n, int i)
{   struct Vert temp; char p,q; int largest,l,r; 
    
     largest=i;  
     l = 2 * i + 1;
     r = 2 * i + 2;
     /*
    if (l<n && x[l].Rank<x[largest].Rank)
       {largest=l; }
    if(r<n && x[r].Rank<x[largest].Rank)
       {largest=r;}
        if (largest != i) 
    {   temp=x[i]; x[i]=x[largest]; x[largest]=temp;
        Max_Heapify(x,n,largest); } */
}
void Build_Max_Heap(struct Vert *x, int n)
{   int i;
for(i=(n/2-1);i>=0;i--)
    { Max_Heapify(x,n,i); 
    }
}
void Heapsort(struct Vert *x, int n)
{   Build_Max_Heap(x,n);
   int i; struct Vert temp;
     for(i=(n-1);i>=0;i--)
    {  temp=x[0]; x[0]=x[i]; x[i]=temp;
       // Max_Heapify(x,n,i); 
       }

   }
void Heap_Increase(struct Vert *x,int i,struct Vert H)
{  int p; struct Vert temp;
 //  if(H.Rank<=x[i].Rank)
   x[i]=H;  p=(i-1)/2; 
 // while (i>0 && x[p].Rank<x[i].Rank) 
  {temp=x[i]; x[i]=x[p]; x[p]=temp;
   i=p;}
}
void Merge(int A[], int p, int q, int r,int count[])
{    
    int i,j,k,n1,n2;
    int inversion=0;
    n1=q-p+1;  n2=r-q;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
       { L[i] = A[p+i]; }
    for (j = 0; j < n2; j++)
       { R[j] = A[q+j+1]; }
    L[n1]=999000; R[n2]=999000; 
    i = 0; j = 0;  
    
    
    for(k=p;k<=r;k++)
    {   count[0]++; 
       if (L[i] <= R[j]) 
       {A[k] = L[i]; i+=1; }
       else 
       {A[k] = R[j]; j+=1; }
    }
}
void Merge_Sort(int A[], int p, int q,int count[])
{   if (p < q) 
    { int mid;
        mid=(q+p)/2;
       
        Merge_Sort(A,p, mid,count);
        Merge_Sort(A,mid+1,q,count);
        Merge(A,p,mid,q,count);    
    }
}
//KRUSKAL ALGORITHM STAGING
void CREATE_KRUS_NODE(struct ver_k **K, int u, int v, int weight)
{
	(*K) = (struct ver_k*)malloc(sizeof(struct ver_k));
	(*K)->u = u;
	(*K)->v = v;
	(*K)->w = weight;
	(*K)->next = NULL;
}
struct ver_k* INSERT_K(struct ver_k *NK, int u, int v, int weight)
{
	if(NK == NULL)
	{
		struct ver_k *K;
        CREATE_KRUS_NODE(&K,u, v, weight);
		return K;
	}
	else
	{
		if(NK->w > weight)
		{
			struct ver_k *K;
            CREATE_KRUS_NODE(&K, u, v, weight);
			K->next = NK;
			return K;			
		}
		else
		{
            NK->next = INSERT_K(NK->next, u, v, weight);
			return NK;
		}
	}
}
struct Graph
{
	int vno;
	struct node_sing *vertex;
	struct node_k **AdjList;
};
int Retrep(struct Graph *G, int val)
{
	return G->vertex[val].rep;
}
void GraphCreate_K(struct Graph **G,int val)
{
	(*G) = (struct Graph*)malloc(sizeof(struct Graph));
	(*G)->AdjList = malloc(val * sizeof(struct node_k*));
	(*G)->vertex = malloc(val * sizeof(struct node_sing));
    (*G)->vno = val;
	for( int i = 0; i < val; i++)
	{
		(*G)->AdjList[i] = NULL;
        (*G)->vertex[i].rep = -1;
		(*G)->vertex[i].key = i;
		(*G)->vertex[i].color = 'w';
		(*G)->vertex[i].weight = 99900;
	}
}
void CreateAdj_K(struct node_k **K, int key)
{
	if(key == -1)
		(*K)= NULL;
	else
	{
		(*K) = (struct node_k *)malloc(sizeof(struct node_k));
		(*K)->key = key;
		(*K)->weight = 0;
		(*K)->next = NULL;
	}
}
struct node_k* InsertAdj_K(struct node_k *vert1, struct node_k *vert2)
{
	if(vert1 == NULL)
		return vert2;
	else
	{
		vert1->next = InsertAdj_K(vert1->next, vert2);
		return vert1;
	}
}
struct Graph* Union_K(struct Graph *G, int u, int v)
{
	int i;
	for(i = 0; i < G->vno; i++)
	{
        if(G->vertex[i].rep == v)
			{
                G->vertex[i].rep = u;
            }
    }
	return G;
}
void MinSpanCalc_K(struct Graph *G, long int Sum_k[])
{
	int i, u, v;
	struct ver_k *K = NULL;
	for(i = 0; i < G->vno; i++)
	{
		G->vertex[i].weight = 99900;
		G->vertex[i].color = 'w';
		G->vertex[i].rep = i;
		struct node_k *pr = G->AdjList[i];
		while(pr != NULL)
		{
			K = INSERT_K(K, i, pr->key, pr->weight);
			pr = pr->next;
		}
	}
	
	while(K != NULL)
	{
		u = K->u;
		v = K->v;
		if(Retrep(G, u) != Retrep(G, v))
		{
			Sum_k[0] += K->w;
			G = Union_K(G, Retrep(G, u), Retrep(G, v));
		}
		K = K->next;
	}
}

//PRIMS ALGORITHM STAGING
int RIGHTCHILD(int val)
{ return (2*val)+2;}
int LEFTCHILD(int val)
{ return (2*val)+1; }
int PARENT(int val)
{ return (val-1)/2; }
void Swap(struct Vert *a,struct Vert *b)
{
	struct Vert temp = *a;
	*a = *b;
	*b = temp;
	int tt = Index[a->ver2];
	Index[a->ver2] = Index[b->ver2];
	Index[b->ver2] = tt;
}

void Insert_P(struct Vert x)
{
	Heap[sizeofheap] = x;
	Index[x.ver2] = sizeofheap;	
	int  i = sizeofheap;
	sizeofheap++;
	while(i!=0 && Heap[PARENT(i)].ver1 > Heap[i].ver1)
	{
		Swap(&Heap[PARENT(i)],&Heap[i]);
		i = PARENT(i);
	}
}
void DECREASE_P(int x,int w)
{
	int i = Index[x];
	if(Heap[i].ver1 > w)
	{
		Heap[i].ver1 = w;
		while(i!=0 && Heap[PARENT(i)].ver1 > Heap[i].ver1)
		{
			Swap(&Heap[PARENT(i)],&Heap[i]);
			i = PARENT(i);
		}
	}
}
void Heapify(int i) 
{ 
    int least = i;
    int r = RIGHTCHILD(i); 
    int l = LEFTCHILD(i); 
         
    if (Heap[l].ver1 < Heap[i].ver1 && l < sizeofheap) 
        least = l; 
    if (Heap[r].ver1 < Heap[least].ver1 && r < sizeofheap) 
        least = r; 
    if (least != i) 
    { 
        Swap(&Heap[i], &Heap[least]); 
        Heapify(least); 
    } 
} 
struct Vert EXTRACT_MIN() 
{ 
    struct Vert root = Heap[0]; 
    if (sizeofheap <= 0) 
        return root; 
    if (sizeofheap == 1) 
    { 
        sizeofheap--; 
        return Heap[0]; 
    } 
  
    Heap[0] = Heap[sizeofheap-1]; 
    sizeofheap--; 
    Heapify(0);   
    return root; 
} 
int main()
{
	char c;
	scanf("%c",&c);
	if(c=='a')
	{
		int n;
		scanf("%d", &n);
		struct Graph *G ;
        GraphCreate_K(&G,n);	
        int i;
        int val;
        int digit;
        int jnk;
		digit = getchar();
		for(i = 0; i < n; i++)
		{
			struct node_k *K = NULL;
			val = -1;
			while(1)
			{
				digit = getchar();
				if(digit == ' ')
				{
					CreateAdj_K(&K,val);
					G->AdjList[i] = InsertAdj_K(G->AdjList[i],K);
					val = -1;
					jnk = 1;
				}
                else if(digit == 10)
				{
					CreateAdj_K(&K,val);
					G->AdjList[i] = InsertAdj_K(G->AdjList[i], K);
					break;
				}
				else
				{
					if(val == -1)
						val = 0;
					val = val * 10 + ( (int)digit - 48 );
				}
			}
		}
		for(i = 0; i < n; i++)
		{
			struct node_k *present = G->AdjList[i];
			val = -99999;
		    jnk = 1;
			while(1)
			{
				digit = getchar();
				if(digit == '-')
					jnk = -1;
					
				else if(digit == ' ')
				{
					present->weight = jnk * val;
					val = -99999;
					jnk = 1;
					present = present->next;
				}
                else if(digit == 10)
				{
					if(val != -99999)
						present->weight = jnk * val;
					jnk = 1;
					break;
				}
				else
				{
					if(val == -99999)
						val = 0;
					val = val * 10 + ( (int)digit - 48 );
				}
			}
		}
		long int Sum_k[1];
        Sum_k[0] = 0;
        MinSpanCalc_K(G,Sum_k);
		printf("%ld\n", Sum_k[0]);
	}
	if(c=='b')
	{
		scanf("%d",&n);
		char digit = '\0';
		digit = getchar();
		for(int i=0;i<n;++i)
		{
			digit = getchar();
			if(digit=='\n') 
				continue;
			int value = digit - '0';
			while(digit!='\n')
			{
				digit = getchar();
				if(digit == '\n' || digit == ' ')
				{
					Adj[i][s[i]].v = value;
					Adj[i][s[i]].u = i;
					s[i]++;
					value = 0;
				}
				else 
					value = value*10 + digit - '0';			
			}
		}
		for(int i=0;i<n;++i)
			for(int j=0;j<s[i];++j)
			{
				int w;
				scanf("%d",&w);
				Adj[i][j].w = w;;
			}	
		struct Vert temp ;
		long long PRIM_MIN_SPAN = 0;
		temp.ver1 = 0;
		temp.ver2 = 0;	
		Insert_P(temp);
		for(int i=1;i<n;++i)
		{
			temp.ver2 = i;
			temp.ver1 = 99900;
			Insert_P(temp);
		}
		while(sizeofheap)
		{
			temp = Heap[0];
			EXTRACT_MIN();
			
			if(reach[temp.ver2]) 
				continue;
			reach[temp.ver2] = 1;
			PRIM_MIN_SPAN += temp.ver1;
			for(int i=0;i<s[temp.ver2];++i)
			{
				struct Edge x = Adj[temp.ver2][i]; 
				
				if(!reach[x.v]) DECREASE_P(x.v,x.w);
			}
		}
		printf("%lld\n",PRIM_MIN_SPAN);
	}
	return 0;
} 