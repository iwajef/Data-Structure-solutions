
/*
 * Author: iwajef
 * Date: 2020-10-22
 */

#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define OVERFLOW -1
#define ERROR 0
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef struct {
    char* base;
    char* top;
    int stacksize;
}SqStack;

typedef struct QNode {
    char data;
    struct QNode* next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;


int InitStack(SqStack& S);
int Push(SqStack& S, char e);
int Pop(SqStack& S, char& e);
int StackEmpty(SqStack& S);
int InitQueue(LinkQueue& Q);
int EnQueue(LinkQueue& Q, char e);
char DeQueue(LinkQueue& Q);
int GetHead(LinkQueue Q, char& e);
int QueueEmpty(LinkQueue Q);
void PrintQueue(LinkQueue Q);


int main()
{
    char c, head;
    SqStack S;
    LinkQueue Q;

    InitStack(S);
    InitQueue(Q);
    printf("Input queue elements: \n");
    while ((c = getchar()) != '\n')
        EnQueue(Q, c);
    printf("Initial Queue: \n");
    PrintQueue(Q);

    // reverse the queue using a stack
    while (!QueueEmpty(Q))
    {
        c = DeQueue(Q);
        Push(S, c);
    }
    while (!StackEmpty(S))
    {
        Pop(S, c);
        EnQueue(Q, c);
    }
    printf("Reversed Queue: \n");
    PrintQueue(Q);

    // print the first element of the queue
    head = Q.front->next->data;
    printf("The first element: \n");
    printf("%c\n", head);

    return 0;
}


// functions for linked queue
int InitQueue(LinkQueue& Q)
{
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front) exit(OVERFLOW);
    Q.front->next = NULL;
    return OK;
}


int EnQueue(LinkQueue& Q, char e)
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}


char DeQueue(LinkQueue& Q)
{
    char e;
    QueuePtr p;
    if (Q.front == Q.rear) return ERROR;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    free(p);
    return e;
}


int GetHead(LinkQueue Q, char& e)
{
    if (Q.front == Q.rear) return ERROR;
    e = Q.front->data;
    return OK;
}


int QueueEmpty(LinkQueue Q)
{
    return Q.front == Q.rear;
}


void PrintQueue(LinkQueue Q)
{
    QueuePtr tmp = Q.front->next;
    while (tmp != NULL)
    {
        printf("%c ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}


// functions for stack
int InitStack(SqStack& S)
{
    S.base = (char*)malloc(STACK_INIT_SIZE*sizeof(char));
    if (!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}


int Push(SqStack& S, char e)
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (char*)realloc(S.base, (S.stacksize+STACK_INCREMENT)*sizeof(char));
        if (!S.base) exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACK_INCREMENT;
    }
    *S.top++ = e;
    return OK;
}


int Pop(SqStack& S, char& e)
{
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}


int StackEmpty(SqStack& S)
{
    return S.top == S.base;
}
