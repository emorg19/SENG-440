#include <stdio.h>
#include <stdint.h>
#include "arm_neon.h"

#define SHIFT_AMOUNT 10
#define SHIFT_MASK ((1 << SHIFT_AMOUNT) -1)
#define size 4

typedef int32_t int_type;
typedef int32x4_t vec_type;

int_type matrix[size][size] = { {1,1,1,-1}, {1,1,-1,1}, {1,-1,1,1}, {-1,1,1,1} };
//int_type matrix[size][size] = {{1, -1, 0, -4, 0, -1, 3, 3, 4, -1}, {-2, 1, -2, 3, -3, -1, 4, -2, -2, -2}, {-3, 3, 2, 1, 0, -3, -1, -2, 2, 1}, {4, 0, -1, 4, -2, 2, -1, 0, 2, -2}, {-4, 1, -4, -2, 0, -3, -2, 0, 3, -4}, {2, 2, 1, 2, 0, -1, -4, 1, 3, -3}, {2, -1, -4, 1, -3, -1, 1, -1, -1, -1}, {4, -3, 4, -1, 0, -1, 3, -1, 3, 0}, {-1, -2, -1, -2, -1, -1, 2, -3, 0, -2}, {-3, -2, 1, 3, 0, -4, -2, -4, 2, 2}};

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
	int_type temp;
	for(int i = 0; i < size*2; i++) 
	{
		temp = augmented[row1][i];
		augmented[row1][i] = augmented[row2][i];
		augmented[row2][i] = temp;
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
void eliminate() {
	int_type first;
	int_type second;
	for(int k = 0; k < size; k++) 
		{
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
			{
			if(i != k) 
			{
				int_type ratio = second/first;

				// load 1 row into 2 vectors
				int32x4_t row = vld1q_s32(augmented[i]);
				int32x4_t aug = vld1q_s32(augmented[i]+size);

				// scale the row to eliminate
				row = vaddq_s32(row, vmulq_n_s32(row, -ratio));
				aug = vaddq_s32(aug, vmulq_n_s32(aug, -ratio));

				// store vectors back into row
				vst1q_s32(augmented[i], row);	
				vst1q_s32(augmented[i]+size, aug);	
			}
		}
	}
}

void print_fractional() 
{
	float float_matrix[size][size];
	for(int i = 0; i < size; i++) 
	{
                int normal = augmented[i][i];
                for(int j = 0; j < size; j++) 
		{
                        float_matrix[i][j] = (float) augmented[i][j+size] / normal;
                }
        } 

	// now printing
	printf("{\n");
        for(int i = 0; i < size; i++) 
	{
                for(int j = 0; j < size; j++) 
		{
                        printf("%.5f, ", float_matrix[i][j]);
                }
                printf("\n");
        }
        printf("}\n");
}
			
int main(void) 
{
	augment();

	eliminate();

	printf("Fractional result:\n");
	print_fractional();
}
