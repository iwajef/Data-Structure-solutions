
/*
 * @Author: iwajef
 * @Date: 2020-9-10
 *
 */

#include <stdio.h>
#include <string.h>


typedef struct {
	char name[20]; // maximun length of 20 for student's first name
	int mathGrade;
}Student;


void AppendElementToArray(int* array, int length, int element);
void AppendElementToArray(Student* array, int length, Student element);
void PrintArray(Student* array, int length);
void DeleteElement(Student* array, int length, int index);


int main()
{
	// initializing variables
	int k;
	Student StudentArray[1000]; // maximun of 1000 students
	
	// input data
	printf("Please enter the number of students: \n");
	scanf("%d", &k);
	printf("Please enter the name and the grades of each student: \n");
	for (int i = 0; i < k; i++)
	{
		scanf("%s", &StudentArray[i].name);
		scanf("%d", &StudentArray[i].mathGrade);
	}
	printf("\n");
	
	// check the input data if it is valid
	// invalid: grade < 0 or grade > 100
	// if invalid, delete the invalid element and k--
	int invalidIndices[1000];
	int invalidDataCounter = 0;
	for (int i = 0; i < k; i++)
	{
		if (StudentArray[i].mathGrade < 0)
		{
			printf("The grade cannot be a negative number!\n");
			invalidDataCounter++;
			AppendElementToArray(invalidIndices, invalidDataCounter, i);
		}
		else if (StudentArray[i].mathGrade > 100)
		{
			printf("The grade cannot be over 100!\n");
			invalidDataCounter++;
			AppendElementToArray(invalidIndices, invalidDataCounter, i);
		}
	}
	if (invalidDataCounter > 0)
	{
		for (int i = 0; i < invalidDataCounter; i++)
		{
			DeleteElement(StudentArray, k, invalidIndices[i]);
			k--;
		}
	}
	
	
	
	printf("\n\n==============================\n\n");
	
	
	
	// Part 1: using array indices
	int scoreOver90 = 0;
	int scoreFrom80To89 = 0;
	int scoreFrom70To79 = 0;
	int scoreFrom60To69 = 0;
	int scoreUnder60 = 0;
	
	Student scoreOver90Array[1000];
	Student scoreFrom80To89Array[1000];
	Student scoreFrom70To79Array[1000];
	Student scoreFrom60To69Array[1000];
	Student scoreUnder60Array[1000];
	
	// iterate through the array
	for (int i = 0; i < k; i++)
	{
		if (StudentArray[i].mathGrade >= 90)
		{
			scoreOver90++;
			AppendElementToArray(scoreOver90Array, scoreOver90, StudentArray[i]);
		}
		else if (StudentArray[i].mathGrade >= 80 && StudentArray[i].mathGrade <= 89)
		{
			scoreFrom80To89++;
			AppendElementToArray(scoreFrom80To89Array, scoreFrom80To89, StudentArray[i]);
		}
		else if (StudentArray[i].mathGrade >= 70 && StudentArray[i].mathGrade <= 79)
		{
			scoreFrom70To79++;
			AppendElementToArray(scoreFrom70To79Array, scoreFrom70To79, StudentArray[i]);
		}
		else if (StudentArray[i].mathGrade >= 60 && StudentArray[i].mathGrade <= 69)
		{
			scoreFrom60To69++;
			AppendElementToArray(scoreFrom60To69Array, scoreFrom60To69, StudentArray[i]);
		}
		else
		{
			scoreUnder60++;
			AppendElementToArray(scoreUnder60Array, scoreUnder60, StudentArray[i]);
		}
	}
	// print the detailed information
	printf("Printing details using array indices.\n");
	printf("The number of students grade over 90 is %d.\n", scoreOver90);
	printf("Detailed scores: ");
	PrintArray(scoreOver90Array, scoreOver90);
	printf("The number of students grade from 80 to 89 is %d.\n", scoreFrom80To89);
	printf("Detailed scores: ");
	PrintArray(scoreFrom80To89Array, scoreFrom80To89);
	printf("The number of students grade from 70 to 79 is %d.\n", scoreFrom70To79);
	printf("Detailed scores: ");
	PrintArray(scoreFrom70To79Array, scoreFrom70To79);
	printf("The number of students grade from 60 to 69 is %d.\n", scoreFrom60To69);
	printf("Detailed scores: ");
	PrintArray(scoreFrom60To69Array, scoreFrom60To69);
	printf("The number of students grade under 60 is %d.\n", scoreUnder60);
	printf("Detailed scores: ");
	PrintArray(scoreUnder60Array, scoreUnder60);
	
	printf("\n\n==============================\n\n");

	
	
	// Part 2: using pointers
	int scoreOver90_2 = 0;
	int scoreFrom80To89_2 = 0;
	int scoreFrom70To79_2 = 0;
	int scoreFrom60To69_2 = 0;
	int scoreUnder60_2 = 0;
	
	Student scoreOver90Array_2[1000];
	Student scoreFrom80To89Array_2[1000];
	Student scoreFrom70To79Array_2[1000];
	Student scoreFrom60To69Array_2[1000];
	Student scoreUnder60Array_2[1000];
	
	// initialize a pointer points to the first element of the array
	Student* p = StudentArray;
	
	// iterate through the array using a pointer
	int tempCounter = 0;
	while (tempCounter < k)
	{
		if (p->mathGrade >= 90)
		{
			scoreOver90_2++;
			AppendElementToArray(scoreOver90Array_2, scoreOver90_2, *p);
		}
		else if (p->mathGrade >= 80 && p->mathGrade <= 89)
		{
			scoreFrom80To89_2++;
			AppendElementToArray(scoreFrom80To89Array_2, scoreFrom80To89_2, *p);
		}
		else if (p->mathGrade >= 70 && p->mathGrade <= 79)
		{
			scoreFrom70To79_2++;
			AppendElementToArray(scoreFrom70To79Array_2, scoreFrom70To79_2, *p);
		}
		else if (p->mathGrade >= 60 && p->mathGrade <= 69)
		{
			scoreFrom60To69_2++;
			AppendElementToArray(scoreFrom60To69Array_2, scoreFrom60To69_2, *p);
		}
		else
		{
			scoreUnder60_2++;
			AppendElementToArray(scoreUnder60Array_2, scoreUnder60_2, *p);
		}
		p++;
		tempCounter++;
	}
	
	// print the detailed information
	printf("Printing details using pointers.\n");
	printf("The number of students grade over 90 is %d.\n", scoreOver90_2);
	printf("Detailed scores: ");
	PrintArray(scoreOver90Array_2, scoreOver90_2);
	printf("The number of students grade from 80 to 89 is %d.\n", scoreFrom80To89_2);
	printf("Detailed scores: ");
	PrintArray(scoreFrom80To89Array_2, scoreFrom80To89_2);
	printf("The number of students grade from 70 to 79 is %d.\n", scoreFrom70To79_2);
	printf("Detailed scores: ");
	PrintArray(scoreFrom70To79Array_2, scoreFrom70To79_2);
	printf("The number of students grade from 60 to 69 is %d.\n", scoreFrom60To69_2);
	printf("Detailed scores: ");
	PrintArray(scoreFrom60To69Array_2, scoreFrom60To69_2);
	printf("The number of students grade under 60 is %d.\n", scoreUnder60_2);
	printf("Detailed scores: ");
	PrintArray(scoreUnder60Array_2, scoreUnder60_2);
	
	
	return 0;
}


/*
 * Append an element to an array
 * 
 * @param: int* array: the array u want to append element to
 *         int length: the length of the element
 *         int element: the element u want to append
 *
 */
void AppendElementToArray(int* array, int length, int element)
{
	array[length - 1] = element;
}


/*
 * Append an element to an array
 * 
 * @param: Student* array: the array u want to append element to
 *         int length: the length of the element
 *         Student element: the element u want to append
 *
 */
void AppendElementToArray(Student* array, int length, Student element)
{
	array[length - 1] = element;
} 


/*
 * Print the array
 * 
 * @param: Student* array: the array u want to print
 *         int length: the length of the array
 * 
 */
void PrintArray(Student* array, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		printf("%s ", array[i].name);
		printf("%d\t", array[i].mathGrade);
	}
	printf("%s ", array[length - 1].name);
	printf("%d", array[length - 1].mathGrade);
	printf("\n");
}


/* 
 * Delete an element from the array
 * 
 * @param: Student* array: an array u want to delete element
 * 		   int length: the length of the original array
 *         int index: the index of the element
 * 
 */
void DeleteElement(Student* array, int length, int index)
{
	for (int i = index - 1; i < length - 1; i++)
	{
		array[i] = array[i + 1];
	}
	strcpy(array[length - 1].name, "");
	array[length - 1].mathGrade = 0;
}

