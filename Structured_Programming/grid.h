# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# define MAX 75000

void init(uint64_t arr[]);
int count_row(uint64_t arr[], int n);
int count_col(uint64_t arr[], int n);
int count_dia(uint64_t arr[], int n);