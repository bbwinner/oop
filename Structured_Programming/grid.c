# include <stdio.h>
# include <stdint.h>
# include "grid.h"
# define MAX 75000

void init(uint64_t arr[], int n){
    scanf("%d", &n);
    for(int i=0; i<MAX; ++i){
        scanf("%llu", &arr[i]);
    }
}