#include <stdio.h>
#include <stdlib.h>
struct S1
{
    int key;
    struct S1 *rep;
};
struct S2
{
    int key;
    struct S2 *rep;
    int rank;
};
struct LIST1
{
    struct S1 *node;
};
struct LIST2
{
    struct S2 *node;
};
struct LIST1 *L1;
struct LIST1 *L2;
struct LIST2 *L3;
struct LIST2 *L4;
int Bvisit = 0;
int Cvisit = 0;
int Dvisit = 0;
void MAKESET(int val)
{
    int i,j,k,l;
    i=0;
    j=0;
    k=0;
    l=0;
    if (L1[val].node != NULL)
    {
        printf("-1");
        return;
    }
    printf("%d ", val);
    struct S1 *S1_node;
    S1_node = (struct S1 *)malloc(sizeof(struct S1));
    struct S1 *node_a;

    node_a = (struct S1 *)malloc(sizeof(struct S1));
    struct S2 *node_b = (struct S2 *)malloc(sizeof(struct S2));

    S1_node->key = val;
    node_a->key = val;

    S1_node->rep = S1_node;
    node_a->rep = node_a;

    L1[val].node = S1_node;
    L2[val].node = node_a;
    i++;
    j++;

    struct S2 *S2_node_b;
    S2_node_b = (struct S2 *)malloc(sizeof(struct S2));
    S2_node_b->key = val;
    S2_node_b->rep = S2_node_b;
    S2_node_b->rank = 0;

    node_b->key = val;
    node_b->rep = node_b;
    node_b->rank = 0;

    L3[val].node = S2_node_b;
    L4[val].node = node_b;
    k++;
    l++;
}
struct S1 *FINDSET_A(int val, int DA1[], int marker[])
{
    marker[0] = 0;
    struct S1 *found_a;
    found_a = L1[val].node;

    if (L1[val].node != NULL)
    {
        DA1[0]++;
        found_a = L1[val].node;
        marker[0] = 1;
        while (found_a)
        {
            if (found_a->rep == found_a)
                break;
            else
                found_a = found_a->rep;
            DA1[0]++;
        }
    }
    return found_a;
}
void UNION_A(int v, int w, int DA1[],int marker[], int err[])
{
    err[0] = 0;
    struct S1 *S1_node;
    S1_node = (struct S1 *)malloc(sizeof(struct S1));
    struct S1 *makefirst = (struct S1 *)malloc(sizeof(struct S1));

    S1_node = FINDSET_A(v,DA1,marker);
    if (marker[0] == 0)
    {
        printf("-1 ");
        err[0] = 1;
        return;
    }
    makefirst = FINDSET_A(w,DA1,marker);
    if (marker[0] == 0)
    {
        printf("-1 ");
        err[0] = 1;
        return;
    }
    if (S1_node->key == makefirst->key)
    {
        printf("%d ", S1_node->key);
    }
    else
    {
        makefirst->rep = S1_node;
        printf("%d ", S1_node->key);
    }
}
struct S2 *FINDSET_B(int val,int DA2[])
{
    struct S2 *S2_node;
    Bvisit = 0;
    if (L1[val].node == NULL)
    {
        S2_node = NULL;
        return S2_node;
    }
    Bvisit = 1;
    S2_node = L3[val].node;
    DA2[0]++;
    while (S2_node)
    {
        if (S2_node->rep == S2_node)
            break;
        else
            S2_node = S2_node->rep;
        DA2[0]++;
    }
    return S2_node;
}
void UNION_B(int v, int w, int DA2[])
{
    struct S2 *S2_node_b;
    S2_node_b = (struct S2 *)malloc(sizeof(struct S2));
    struct S2 *makenew;
    makenew = (struct S2 *)malloc(sizeof(struct S2));
    S2_node_b->rank = makenew->rank = 0;

    S2_node_b = FINDSET_B(v,DA2);
    if (Bvisit == 0)
    {
        printf("-1 ");
        return;
    }
    makenew = FINDSET_B(w,DA2);
    if (Bvisit == 0)
    {
        printf("-1 ");
        return;
    }

    if (S2_node_b->rank > makenew->rank)
    {
        makenew->rep = S2_node_b;
        printf("%d ", S2_node_b->key);
    }
    else if (S2_node_b->rank < makenew->rank)
    {
        S2_node_b->rep = makenew;
        printf("%d ", makenew->key);
    }
    else
    {
        makenew->rep = S2_node_b;
        printf("%d ", S2_node_b->key);

        (S2_node_b->rank)++;
    }
    // printf("rank union");
}
struct S1 *PATHCOMPRESSION(struct S1 *b, int DA3[])
{
    if (b != b->rep)
        b->rep = PATHCOMPRESSION(b->rep,DA3);
    DA3[0]++;
    return b->rep;
}
struct S1 *FINDSET_C(int val, int DA3[])
{
    struct S1 *getvala=NULL;
    Cvisit = 0;
    if (L1[val].node == NULL)
    {
        getvala = NULL;
        return getvala;
    }

    Cvisit = 1;
    getvala = PATHCOMPRESSION(L2[val].node,DA3);
    return getvala;
}
void UNION_C(int v, int w, int DA3[])
{
    struct S1 *S1_node;
    S1_node = (struct S1 *)malloc(sizeof(struct S1));
    struct S1 *makefirst;
    makefirst = (struct S1 *)malloc(sizeof(struct S1));

    S1_node = FINDSET_C(v,DA3);
    if (Cvisit == 0)
    {
        printf("-1 ");
        return;
    }
    makefirst = FINDSET_C(w,DA3);
    if (Cvisit == 0)
    {
        printf("-1 ");
        return;
    }
    if (S1_node->key == makefirst->key)
        printf("%d ", S1_node->key);

    else
    {
        makefirst->rep = S1_node;
        printf("%d ", S1_node->key);
    }
}
struct S2 *PATHCOMPRESSION_4(struct S2 *h, int DA4[])
{
    DA4[0]++;
    if (h != h->rep)
        h->rep = PATHCOMPRESSION_4(h->rep,DA4);
    return h->rep;
}
struct S2 *f4(int val, int DA4[])
{
    Dvisit = 0;
    struct S2 *S2_node_d=NULL;
    if (L1[val].node == NULL)
    {
        S2_node_d = NULL;
        return S2_node_d;
    }
    Dvisit = 1;

    S2_node_d = PATHCOMPRESSION_4(L4[val].node,DA4);
    return S2_node_d;
}
void UNION_D(int v, int w, int DA4[])
{
    struct S2 *temp = (struct S2 *)malloc(sizeof(struct S2));
    struct S2 *temp2 = (struct S2 *)malloc(sizeof(struct S2));

    temp->rank = temp2->rank = 0;
    temp = f4(v,DA4);
    if (Dvisit == 0)
    {
        printf("-1 ");
        return;
    }
    temp2 = f4(w,DA4);
    if (Dvisit == 0)
    {
        printf("-1 ");
        return;
    }

    if (temp->rank > temp2->rank)
    {
        temp2->rep = temp;
        printf("%d ", temp->key);
    }
    else if (temp->rank < temp2->rank)
    {
        temp->rep = temp2;
        printf("%d ", temp2->key);
    }
    else
    {
        temp2->rep = temp;
        printf("%d ", temp->key);
        // printf("Rank applied");
        (temp->rank)++;
    }
}
void ACCESS_COUNT(int DA1[], int DA2[], int DA3[], int DA4[])
{
    printf("%d %d %d %d", DA1[0], DA2[0], DA3[0], DA4[0]);
    printf("\n");
}
void UNION(int val1,int val2, int DA1[],int DA2[], int DA3[], int DA4[], int marker[], int err[])
{
    UNION_A(val1, val2,DA1,marker,err);
    if (err[0] == 1)
     { printf("-1 -1 -1");  return; }
    UNION_B(val1, val2,DA2);
    UNION_C(val1, val2,DA3);
    UNION_D(val1, val2,DA4);
}
void FIND(int val1,int DA1[],int DA2[],int DA3[],int DA4[],int marker[])
{
    struct S1 *getvala;
    struct S1 *getvalc;
    struct S2 *getvalb;
    struct S2 *getvald;
     getvala = FINDSET_A(val1,DA1,marker);
      if (marker[0] == 0)
        { printf("-1 -1 -1 -1\n");return; }
       else
        {
           printf("%d ", getvala->key);
           getvalb = FINDSET_B(val1,DA2);
           printf("%d ", getvalb->key);
           getvalc = FINDSET_C(val1,DA3);
           printf("%d ", getvalc->key);
           getvald = f4(val1,DA4);
           printf("%d ", getvald->key);  
           printf("\n");
        }
}
int main()
{
    char c;
    L1 = (struct LIST1 *)malloc(10000 * sizeof(struct LIST1));
    L2 = (struct LIST1 *)malloc(10000 * sizeof(struct LIST1));
    L3 = (struct LIST2 *)malloc(10000 * sizeof(struct LIST2));
    L4 = (struct LIST2 *)malloc(10000 * sizeof(struct LIST2));
    //struct S1  *found_a, *S1_node;
    //struct S2  *S2_node, *S2_node_d, *S2_node_b;
    int val1, val2;
    int DA1[1],DA2[1],DA3[1],DA4[1];
    DA1[0] = 0; DA2[0] = 0; DA3[0] = 0; DA4[0] = 0;
    int err[1];
    err[0]= 0;
    int marker[1];
    marker[0] = 0;

    for (int i = 0; i < 10000; i++)
        L1[i].node = NULL;
    
    while(1)
    {
        scanf(" %c", &c);
        switch (c)
        {
            case 'm': scanf("%d", &val1);
                      MAKESET(val1);
                      printf("\n");
                      break;
            case 'f': scanf("%d", &val1);
                      FIND(val1,DA1,DA2,DA3,DA4,marker);
                      break;
            case 'u': scanf("%d%d", &val1, &val2);
                      UNION(val1,val2,DA1,DA2,DA3,DA4,marker,err);
                      printf("\n");
                      break;
            case 's': ACCESS_COUNT(DA1,DA2,DA3,DA4);
                      return 0;
        }
    } 
}