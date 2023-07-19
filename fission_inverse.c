#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include "inverse.h"
#define SHIFT_AMOUNT 20
#define SHIFT_MASK ((1 << SHIFT_AMOUNT) -1)

int_type augmented[size][size*2];
float float_matrix[size][size];

int_type augmented[size][size*2];

// prints the augmented matrix
void print(int_type a[size][size*2]) 
{
        printf("{\n");
        for(int i = 0; i < size; i++) 
	{
                for(int j = 0; j < size*2; j++) 
		{
                        printf("% 4lld, ", a[i][j]);
                }
                printf("\n");
        }
        printf("}\n");
}

// augments the square input matrix with the identity matrix and scales values for fixed point arithmetic
void augment() 
{
	for(int i = 0; i < size; i++) 
	{
		for(int j = 0; j < size; j++) 
		{
			// copying input matrix
			augmented[i][j] = matrix[i][j] << SHIFT_AMOUNT;
			// putting in identity matrix
			augmented[i][j+size] = ((i == j) << SHIFT_AMOUNT);
		}
	}
}

// swaps 2 rows for use in row interchange
void swap(int row1, int row2) 
{
	int_type temp[size*2];
	for(int i = 0; i < size*2; i++) 
	{
		temp[i] = augmented[row1][i];
	}
	for(int i = 0; i < size*2; i++) 
	{
		augmented[row1][i] = augmented[row2][i];
	}
	for(int i = 0; i < size*2; i++) 
	{
		augmented[row2][i] = temp[i];
	}
}

// returns the index of the largest element in a column for pivoting
int max_column(int col) 
{
	int_type max = augmented[0][col];
	int index = 0;
	for(int i = 1; i < size; i++) 
	{
		int_type current = augmented[i][col];
		if(current < 0) 
		{
			current *= -1; // taking absolute value incase the max is negative
		}
		if(current> max) 
		{
			max = current;
			index = i;
		}
	}
	return index;
}

// performs gaussian elimination with full pivoting
void eliminate() 
{
	int_type first;
	int_type second;
	for(int k = 0; k < size; k++) 
	{
		// finding the pivot row
		int pivot_index = max_column(k);
		if(k < pivot_index) 
		{
			swap(k, pivot_index);	
		}	

		first = augmented[k][k];
		for(int i = 0; i < size; i++) 
		{
			second = augmented[i][k];
			if(second == 0) 
			{
				continue; // skip rows where its already 0
			}
			if(i != k) 
			{
				for(int j = 0; j < size*2; j++) 
				{
					// this step does the elimination and subtracts across the row
					augmented[i][j] -= second*augmented[k][j] / first;
				}
			}
		}
	}
}

// The final matrix is printed as floating point for verification purposes
void print_fractional() 
{
	for(int i = 0; i < size; i++) 
	{
                double normal = augmented[i][i]; // normalizing the integer values to get back floating point
                for(int j = 0; j < size; j++) 
		{
                        float_matrix[i][j] = augmented[i][j+size] / normal;
                }
        } 

	// now printing
	printf("{\n");
        for(int i = 0; i < size; i++) 
	{
                for(int j = 0; j < size; j++) 
		{
                        printf("%f, ", float_matrix[i][j]);
                
		}
                printf("\n");
        }
        printf("}\n");
}

// prints out preprogramed expected matrix for testing
void print_expected() 
{
	printf("{\n"); 
	for(int i = 0; i < size; i++) 
	{
		for(int j = 0; j < size; j++) 
		{
			printf("%f, ", inv_matrix[i][j]);
		}
		printf("\n");
	}
	printf("}\n");
}
			
void end_timer(clock_t start_time)
{
	clock_t end_time = clock();
	double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("%f seconds to execute\n", time_spent);
}

int main(int argc, char *argv[]) 
{
	augment();

	// start the timer
	clock_t start_time = clock();
	
	// do gaussian elimination
	eliminate();

	// end timer and print time elapsed
	end_timer(start_time);

	// print out results for verification
	printf("Fractional result:\n");
	print_fractional();

	printf("Expected result:\n");
	print_expected();
}
