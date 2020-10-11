
/* 
 * Author: iwajef
 * Date: 2020-10-11
 */

#include <cstdio>
#include <cstdlib>

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef struct {
    char* base;
    char* top;
    int stackSize;
} SqStack;

int InitStack(SqStack& S);
int StackLength(SqStack S);
bool StackEmpty(SqStack S);
int Push(SqStack& S, char e);
int Pop(SqStack& S, char& e);
int GetTop(SqStack& S, char e);
void ReverseStack(SqStack& S, char* arr);
void PrintStack(SqStack S);


int main()
{
    SqStack S;
    InitStack(S);
    int n;
    printf("Please enter the stack size \n");
    printf("Then enter characters: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char ch;
        scanf(" %c", &ch);  // be careful of the space " %c"
        Push(S, ch);
    }
    printf("The stack: (prints from base to top)\n");
    PrintStack(S);

    char A[255];
    ReverseStack(S, A);
    printf("The reversed stack: (prints from base to top)\n");
    PrintStack(S);

    return 0;
}


/*
 * Initialize an empty stack with initial stack size 100
 * returns OVERFLOW if malloc failed
 *         OK if successfully initialized
 */
int InitStack(SqStack& S)
{
    S.base = (char*)malloc(STACK_INIT_SIZE*sizeof(char));
    if (!S.base) return OVERFLOW;
    S.top = S.base;  // empty stack
    S.stackSize = STACK_INIT_SIZE;
    return OK;
}


/*
 * Simply returns the stack length
 */
int StackLength(SqStack S)
{
    return S.top - S.base;
}


/*
 * Return true if stack is empty
 */
bool StackEmpty(SqStack S)
{
    return S.top == S.base;
}


/*
 * Push an element into the stack S
 */
int Push(SqStack& S, char e)
{
    if (StackLength(S) >= S.stackSize)  // stack overflow, reallocate space
    {
        S.base = (char*)realloc(S.base, (S.stackSize + STACK_INCREMENT)*sizeof(char));
        if (!S.base) return OVERFLOW;
        S.top = S.base + S.stackSize;
        S.stackSize += STACK_INCREMENT;  // increase the stack size by STACK_INCREMENT
    }
    *S.top++ = e;  // same as *S.top = e; S.top++;
    return OK;
}


/*
 * Pop an element from the stack, and store the value with e
 * Returns ERROR if stack is empty
 *         OK if successfully Pop-ed
 */
int Pop(SqStack& S, char& e)
{
    if (StackEmpty(S)) return ERROR;
    e = *--S.top;  // same as S.top--; e = *S.top;
    return OK;
}


/*
 * Get the element on the top, but not pop it, and store the value with e
 * Returns ERROR if stack is empty
 *         OK it successfully get
 */
int GetTop(SqStack& S, char& e)
{
    if (StackEmpty(S)) return ERROR;
    e = *(S.top - 1);
    return OK;
}


/*
 * Reverse a stack using an empty array, and Pop() function
 */
void ReverseStack(SqStack& S, char* arr)  // arr must be an empty array
{
    int counter = 0;
    while (!StackEmpty(S))
    {
        char ch;
        Pop(S, ch);
        *(arr + counter) = ch;
        counter++;
    }
    for (int i = 0; i < counter; i++)
    {
        Push(S, arr[i]);
    }
}


/*
 * Just print the elements in the stack
 * from base up to top
 */
void PrintStack(SqStack S)
{
    for (char* p = S.base; p < S.top; p++)
        printf("%c ", *p);
    printf("\n");
}
