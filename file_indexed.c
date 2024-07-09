#include<stdio.h>

/*

each file has its own blocks
number of blocks of each file stored in an array 
block stored in 2d array

*/

void main() {
    int nof, noBlk[10], block[10][10], key;

    printf("Enter number of Files : ");
    scanf("%d", &nof);

    for (int i = 1; i <= nof; i++) {
        printf("Enter number of blocks of file %d : ", i);
        scanf("%d", &noBlk[i]);

        printf("Enter the blocks : ");
        for (int j = 0; j < noBlk[i]; j++) {
            scanf("%d", &block[i][j]);
        }
    }

    printf("\nEnter File to be Searched : ");
    scanf("%d", &key);

    if (key > nof) {
        printf("\nFile not Found\n");
    }
    else {
        // Print header for file details
        printf("\n  %10s   %10s   %20s   ", "File Name", "Start Block", "Occupied Blocks");
        
        // Print details of the specified file
        printf("\n  %7d   %10d               ", key, block[key][0]);
        
        // Print occupied blocks of the specified file
        for (int i = 0; i < noBlk[key]; i++)
            printf(" %d ", block[key][i]);
    }
}