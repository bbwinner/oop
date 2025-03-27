# include "grid.h"
# define MAX 75000

void init(uint64_t arr[]){
    for(int i=0; i<MAX; ++i){
        scanf("%llu", &arr[i]);
    }
}

int count_row(uint64_t arr[], int n){
    int row=0;
    for(int i=0; i<MAX; ++i){
        for(int j=0; j<64-n+1; ++j){
            uint64_t temp = ((1ULL<<(n))-1)<<j;
            if((arr[i] & temp) == temp) row++;
        }
    }
    return row;
}