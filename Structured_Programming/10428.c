# include "grid.h"
# define MAX 75000

int main(){
    int row=0, col=0, dia=0, adia=0;

    // Actually private member
    int n;
    uint64_t grid[MAX];
    scanf("%d", &n);
    init(grid);

    row = count_row(grid, n);
    col = count_col(grid, n);
    
    // for(int i=0; i<MAX-n+1; ++i){
    //     uint64_t temp;
    //     short int flag;
    //     // row
    //     for(int j=0; j<64; ++j){
    //         flag = 1;
    //         for(int k=0; k<n; ++k) if(!(arr[i+k]&((1ULL<<j)))) flag=0;
    //         if(flag) col++;
    //     }
 
    //     // dia
    //     for(int j=0; j<64-n+1; ++j){
    //         flag = 1;
    //         for(int k=0; k<n; ++k) if(!(arr[i+k]&((1ULL<<(j+n-k-1))))) flag=0;
    //         if(flag) dia++;
    //         flag = 1;
    //         for(int k=0; k<n; ++k) if(!(arr[i+k]&((1ULL<<(j+k))))) flag=0;
    //         if(flag) adia++;
    //     }
    // }
    printf("%d\n%d\n%d\n%d\n", row, col, dia, adia);
}