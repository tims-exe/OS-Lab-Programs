#include<stdio.h>

struct page{
    int count, last_used, content;
} frames[50];

void main() {
    int nos, nof, i, j, pf = 0;

    printf("Enter the Length of the Reference String: ");
    scanf("%d", &nos);
    printf("Enter the Frame Size: ");
    scanf("%d", &nof);

    int refStr[nos];

    // initialised values of frame
    for (i = 0; i < nof; i++) {
        frames[i].content = -1;
        frames[i].count = 0;
        frames[i].last_used = -1;
    }

    printf("Enter the Reference String: ");
    for (i = 0; i < nos; i++)
        scanf("%d", &refStr[i]);

    printf("\n\t Ref String\t Page Number\t\t Status\n");
	printf("---------------------------------------------------------------\n");

    for (i = 0; i < nos; i++ ){
        int found = 0;

        printf("\t%d\t\t", refStr[i]);

        // check if page is there in frame
        for (j = 0; j < nof; j++) {
            if (refStr[i] == frames[j].content) {
                found = 1;
                frames[j].count++;
                frames[j].last_used = i;
                break;
            }
        }

        if (!found) {
            pf++;

            // finding the least frequently used 
            int min_count = frames[0].count;
            int min_last_used = frames[0].last_used;
            int min_index = 0;

            for (j = 1; j < nof; j++) {
                if (frames[j].count < min_count || (frames[j].count == min_count && frames[j].last_used < min_last_used)){
                    min_count = frames[j].count;
                    min_last_used = frames[j].last_used;
                    min_index = j;
                }
            }        

            // replace least frequently used
            frames[min_index].content = refStr[i];
            frames[min_index].count = 1;
            frames[min_index].last_used = i;
        }

         // Output: Page in frames and page fault or hit
        for (j = 0; j < nof; j++)
            printf("%2d ", frames[j].content);
        
        if (found)
            printf("\tPage Hit\n");
        else
            printf("\tPage Fault\n");
    }

    printf("\nNumber of Page Fault: %d", pf);
    printf("\nNumber of Page Hits: %d\n", (nos - pf));
}