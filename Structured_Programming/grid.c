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

int count_col(uint64_t arr[], int n){
    int col=0;
    for(int i=0; i<MAX-n+1; ++i){
        bool flag;
        for(int j=0; j<64; ++j){
            flag = 1;
            for(int k=0; k<n; ++k) if(!(arr[i+k]&((1ULL<<j)))) flag=0;
            if(flag) col++;
        }
    }
    return col;
}

int count_dia(uint64_t arr[], int n){
    int dia=0;
    for(int i=0; i<MAX-n+1; ++i){
        for(int j=0; j<64-n+1; ++j){
            bool flag=1;
            for(int k=0; k<n; ++k) if(!(arr[i+k]&((1ULL<<(j+n-k-1))))) flag=0;
            if(flag) dia++;
        }
    }
    return dia;
}

int count_adia(uint64_t arr[], int n){
    int adia=0;
    for(int i=0; i<MAX-n+1; ++i){
        for(int j=0; j<64-n+1; ++j){
            bool flag=1;
            for(int k=0; k<n; ++k) if(!(arr[i+k]&((1ULL<<(j+k))))) flag=0;
            if(flag) adia++;
        }
    }
    return adia;
}