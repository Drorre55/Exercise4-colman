#include "Utils.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


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
void MoveItemFromEndToStartSlice(int arr[], int start, int end, bool includeEdge) {
	int itemToMove = arr[end];

	start = includeEdge ? start - 1 : start;
	for (int q = end - 1; q > start; q--) {
		arr[q + 1] = arr[q];
	}
	// put current number in the start of the slice
	arr[start + 1] = itemToMove;
}

void InsertionSort( int arr[], int size )
{
	for (int i = 1; i < size; i++) {
		int currentNumber = arr[i];
		
		// iterate over the numbers to the left of current number, from closest to the farthest one
		for (int j = i - 1; j >= 0; j--) {
			int previousNumber = arr[j];
			
			if (currentNumber > previousNumber) {
				MoveItemFromEndToStartSlice(arr, j, i, false);
				break;
			}
			else if (j == 0) {
				MoveItemFromEndToStartSlice(arr, j, i, true);
			}
		}
	}
}
//-----------------------------------------------------------------------------------------------//
//Q3
void FlipMatrix( int mat[MATRIX_SIZE][MATRIX_SIZE], int option )
{
	int matCopy[MATRIX_SIZE][MATRIX_SIZE];
	memcpy(matCopy, mat, sizeof(int) * MATRIX_SIZE * MATRIX_SIZE);

	switch (option) {
	case 1:
		for (int row = 0; row < MATRIX_SIZE; row++) {
			for (int column = 0; column < MATRIX_SIZE; column++) {
				mat[column][MATRIX_SIZE - 1 - row] = matCopy[row][column];
			}
		}
		break;

	case 2:
		for (int row = 0; row < MATRIX_SIZE; row++) {
			for (int column = 0; column < MATRIX_SIZE; column++) {
				mat[MATRIX_SIZE - 1 - column][row] = matCopy[row][column];
			}
		}
		break;

	case 3:
		for (int row = 0; row < MATRIX_SIZE; row++) {
			for (int column = 0; column < MATRIX_SIZE; column++) {
				mat[MATRIX_SIZE - 1 - row][column] = matCopy[row][column];
			}
		}
		break;

	case 4:
		for (int row = 0; row < MATRIX_SIZE; row++) {
			for (int column = 0; column < MATRIX_SIZE; column++) {
				mat[row][MATRIX_SIZE - 1 - column] = matCopy[row][column];
			}
		}
		break;
	}
}
//-----------------------------------------------------------------------------------------------//
//Q4
int* InsertionSortString(char str[], size_t len) {
	int* ascii = malloc(len * sizeof *ascii);
	if (!ascii) return -1;

	for (int i = 0; i < len; i++) {
		ascii[i] = str[i];
	}

	InsertionSort(ascii, len);
	return ascii;
}

int CountSemiSimilar( char a[][M], char b[][M], int n )
{
	int numSemiSimilar = n;
	
	for (int i = 0; i < n; i++) {
		size_t lenA = strlen(a[i]);
		size_t lenB = strlen(b[i]);
		if (lenA != lenB) {
			numSemiSimilar--;
			continue;
		}
		
		size_t len = lenA;

		int* sortedAsciiA = InsertionSortString(a[i], len);
		int* sortedAsciiB = InsertionSortString(b[i], len);

		for (int j = 0; j < len; j++) {
			if (sortedAsciiA[j] != sortedAsciiB[j]) {
				numSemiSimilar--;
				break;
			} 
		}
		free(sortedAsciiA);
		sortedAsciiA = NULL;
		free(sortedAsciiB);
		sortedAsciiB = NULL;
	}
	return numSemiSimilar;
}
//-----------------------------------------------------------------------------------------------//