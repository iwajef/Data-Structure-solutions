
/* 
 * Author: iwajef
 * Date: 2020-09-24
 */

#include <cstdio>
#include <cstdlib>

#define ListLength 5
#define ElemType int

typedef struct LNode {

    ElemType data;
    struct LNode* next;

}LNode, *LinkList;

void CreateList_L(LinkList& L, int n);
void SortList_L(LinkList& L, int n);
void MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc);
void PrintList_L(LinkList L, int n);
bool GetElem_L(LinkList L, int i, ElemType& e);
bool ListInsert_L(LinkList& L, int i, ElemType e);
bool ListDelete_L(LinkList& L, int i, ElemType& e);


int main()
{
    LinkList La, Lb, Lc;
    printf("Enter %d numbers to create La...\n", ListLength);
    CreateList_L(La, ListLength);
    printf("Original La: \n");
    PrintList_L(La, ListLength);

    printf("Enter %d numbers to create Lb...\n", ListLength);
    CreateList_L(Lb, ListLength);
    printf("Original Lb: \n");
    PrintList_L(Lb, ListLength);

    SortList_L(La, ListLength);
    printf("La sorted: \n");
    PrintList_L(La, ListLength);
    SortList_L(Lb, ListLength);
    printf("Lb sorted: \n");
    PrintList_L(Lb, ListLength);

    MergeList_L(La, Lb, Lc);
    printf("Lc: \n");
    PrintList_L(Lc, ListLength * 2);

    return 0;
}


void CreateList_L(LinkList& L, int n)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = n; i > 0; i--)  // descending order
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}


void SortList_L(LinkList& L, int n)
{
    // sort the linked list using bubble sort
    LinkList p, q;
    for (int i = 0; i < n - 1; i++)
    {
        p = L->next;
        q = L->next->next;
        for (int j = 0; j < n - 1; j++)
        {
            if (p->data >= q->data)  // non-descending order
            {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            p = p->next;
            q = q->next;
        }
    }
}


void MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc)
{
    // linked list La, Lb is in non-descending order
    // merged list Lc is also in non-descending order
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    LinkList pc;
    Lc = pc = La;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
}


bool GetElem_L(LinkList L, int i, ElemType& e)
{
    LinkList p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)  // node not found
        return false;
    e = p->data;
    return true;
}


bool ListInsert_L(LinkList& L, int i, ElemType e)
{
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return false;
    LinkList s = (LinkList)malloc(sizeof(LNode));  // create a new node
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}


bool ListDelete_L(LinkList& L, int i, ElemType& e)
{
    LinkList p = L;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1)
        return false;
    LinkList q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}


void PrintList_L(LinkList L, int n)
{
    LinkList p = L->next;
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}
