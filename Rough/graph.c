#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10][10], i, j, row, clmn, count, cnt=0;
    printf("Enter dimension ");
    scanf("%d %d", &row, &clmn);
    for(i=0; i<row; i++){
        for(j=0; j<clmn; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Inputed adjacency matrix: \n");
    for(i=0; i<row; i++){
        for(j=0; j<clmn; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<row; i++){
        count = 0;
        for(j=0; j<clmn; j++){
            if(a[i][j] == 1){
                count++;
                cnt++;
            }
        }
        printf("vertex %d has %d degree\n", i+1, count);
    }
    cnt = 0;
    printf("No of edges %d\n", cnt);
    for(i=0; i<row; i++){
        for(j=0; j<clmn; j++){
            if((i!=j) && (a[i][j] ==1)){
                cnt++;
            }
        }
    }
    if(cnt == 1){
        printf("This is a complete graph\n");
    }
    else{
        printf("This is not a complete graph\n");
    }


    return 0;
}
