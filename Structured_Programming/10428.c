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
    dia = count_dia(grid, n);
    adia = count_adia(grid, n);
    
    printf("%d\n%d\n%d\n%d\n", row, col, dia, adia);
}