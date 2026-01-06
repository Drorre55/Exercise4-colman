#include "Utils.h"
#include <stdbool.h>


/*
Student Name : Dror Regev
Student ID: 321604050
Date: 05/01/2026
Program purpose: Exercise 4 on Computer Science 101 - Functions
*/


//-----------------------------------------------------------------------------------------------//
//Q1
int RemoveDuplicates( int arr[], int size )
{
	int currentIndex = 0;
	// Iterate over the numbers in arr
	for (int i = 0; i < size; i++) {
		bool isDuplicate = false;
		// check if the number was already seen
		for (int j = 0; j < currentIndex; j++) {
			if (arr[i] == arr[j]) {
				isDuplicate = true;
				break;
			}
		}
		// put the new number in the correct index in arr
		if (!isDuplicate) {
			arr[currentIndex] = arr[i];
			currentIndex++;
		}
	}

	return arr, currentIndex;
}
//-----------------------------------------------------------------------------------------------//
//Q2
void InsertionSort( int arr[], int size )
{

}
//-----------------------------------------------------------------------------------------------//
//Q3
void FlipMatrix( int mat[MATRIX_SIZE][MATRIX_SIZE], int option )
{
	
}
//-----------------------------------------------------------------------------------------------//
//Q4
int CountSemiSimilar( char a[][M], char b[][M], int n )
{
	return 0;
}
//-----------------------------------------------------------------------------------------------//