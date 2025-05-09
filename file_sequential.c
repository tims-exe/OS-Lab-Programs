#include<stdio.h>

// Global variables declaration
int nof, i, strBlk[10], noBlk[10], key;

int main()
{
    // Prompt for the number of files
    printf("\nEnter the Number of Files  :  ");
    scanf("%d", &nof);

    // Loop to iterate over each file
    for (i = 1; i <= nof; i++)
    {
        // Prompt for the starting block and number of blocks for each file
        printf("Enter Starting Block & No of Blocks of File %d  : ", i);
        scanf("%d %d", &strBlk[i], &noBlk[i]);    
    }

    // Prompt for the file number to search
    printf("\nEnter the File Number to Search  : ");
    scanf("%d", &key);

    // Check if the file number is valid
    if(key > nof)
        printf("\tFile Not Found !!!\n");
    else
    {
        // Print header for file details
        printf("\n  %10s   %10s   %20s   ", "File Name", "Start Block", "Occupied Blocks");
        
        // Print details of the specified file
        printf("\n  %7d   %10d               ", key, strBlk[key]);
        
        // Print occupied blocks of the specified file
        for (i = 0; i < noBlk[key]; i++)
            printf(" %d ", strBlk[key] + i);
    }
    return 0;
}