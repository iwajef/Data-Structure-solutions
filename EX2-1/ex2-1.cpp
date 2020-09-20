
/* 
 * @Author: iwajef
 * @Date: 2020-9-19
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct {
	ElemType* elem;
	int length;
	int listsize;	
}SqList;


int InitList(SqList &L);
int InputList(SqList &L, ElemType e);
int ListInsert(SqList &L, int i, ElemType e);
int ListDelete(SqList &L, int i, ElemType &e);
void ListTraverse(SqList L);


int main()
{
	SqList L;
	InitList(L);  // first initialize a new SqList L
	
	bool flag = true;
	char ch;
	while (flag)
	{
		printf("Enter '1' to initialize a sequential list.\n");
		printf("Enter '2' to exit the program...\n");
		scanf("%c", &ch);
		switch (ch)
		{
			case '1':
				
				// Input the value to the list
				int n;
				printf("Enter the number of elements u want to insert.\n");
				printf("Then enter the elements...\n");
				scanf("%d", &n);
				for (int i = 0; i < n; i++)
				{
					ElemType elem;
					scanf("%d", &elem);
					InputList(L, elem);
				}
				printf("\nThe list: ");
				ListTraverse(L);  // just prints the value
				
				// Insert an element to the specific index of the list
				printf("Enter an index and a number to insert...\n");
				int indexToInsert;
				int numToInsert;
				scanf("%d", &indexToInsert);
				scanf("%d", &numToInsert);
				ListInsert(L, indexToInsert, numToInsert);
				printf("\nThe list: ");
				ListTraverse(L);
				
				// Delete an element
				printf("Enter an index to delete...\n");
				int indexToDelete;
				int numDeleted;
				scanf("%d", &indexToDelete);
				ListDelete(L, indexToDelete, numDeleted);
				printf("\nThe number u deleted is %d.", numDeleted);
				printf("\nThe list: ");
				ListTraverse(L);
				
				break;
				
			case '2':
				
			default:
				flag = false;
				printf("Program exited. Press any button to exit.\n");
		}
		getchar();
	}
	
	return 0;
}


/* 
 * Initialize a new empty sequential list w/ size of LIST_INIT_SIZE
 * @param: SqList &L: the sequential list which is going to be initialized
 * @return: 1 if successfully initialized
 *          0 or exit(-1) otherwise
 * 
 */
int InitList(SqList &L)
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
	{
		exit(-1);
	}
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return 1;
}


/* 
 * Fill the sequential list with the input data
 * @param: SqList &L: the sequential list which is going to write data in
 *         ElemType e: the element comes from input
 * @return: 1 if successfully input the data in
 *          0 or exit(-1) otherwise
 * 
 */
int InputList(SqList &L, ElemType e)
{
	if (L.length >= L.listsize)
	{
		ElemType* newbase;
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(-1);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	L.elem[L.length] = e;
	L.length++;
	return 1;
}


/* 
 * Insert a element to the specific index of the sequential list
 * @param: SqList &L: w
 *         int i: the index that the element is going to be inserted
 *         ElemType e: the element itself
 * @return: 1 if successfully insert the element to the index
 *          0 or exit(-1) otherwise bruhh
 * 
 */
int ListInsert(SqList &L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1) return 0;
	if (L.length >= L.listsize)
	{
		ElemType* newbase;
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(-1);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType* q = &(L.elem[i - 1]);
	for (ElemType* p = &(L.elem[L.length - 1]); p >= q; p--)
	{
		*(p + 1) = *p;
	}
	*q = e;
	L.length++;
	return 1;
}


/* 
 * Delete an element in the sequential list and return the value
 * @param: SqList &L: t
 *         int i: the index of the element which is going to be deleted
 *         ElemType &e: returns the deleted element with the value e
 * @return: 1 if successfully delete the element in the index
 *          0 or exit(-1) otherwise againnn
 * 
 */
int ListDelete(SqList &L, int i, ElemType &e)
{
	if (i < 1 || i > L.length) return 0;
	ElemType* p = L.elem + (i - 1);
	e = *p;
	ElemType* q = L.elem + L.length - 1;
	for (++p; p <= q; p++)
	{
		*(p - 1) = *p;
	}
	L.length--;
	return 1;
}


/* 
 * Just traverse the whole sequential list and prints the value of each element
 * @param: SqList L: f
 * 
 */
void ListTraverse(SqList L)
{
	ElemType* p = L.elem;
	for (; p < &(L.elem[L.length - 1]); p++)
	{
		printf("%d ", *p);
	}
	printf("%d\n\n", L.elem[L.length - 1]);
}


