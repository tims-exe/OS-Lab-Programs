#include<stdio.h>

void main() {
    int cySize, prePos, currPos, queSize, i, ptr, seek = 0;

    // Input the number of cylinders
    printf("Enter the Number of Cylinders: ");
    scanf("%d", &cySize);

    // Input the previous head position
    printf("Enter the Previous Head Position: ");
    scanf("%d", &prePos);

    // Input the current head position
    printf("Enter the Current Position: ");
    scanf("%d", &currPos);

    // Input the queue size
    printf("Enter the Queue Size: ");
    scanf("%d", &queSize);

    int requests[queSize + 1]; // Array to store requests, plus one for current position
    printf("Enter the Requests in Order: ");
    for (i = 1; i <= queSize; i++) {
        scanf("%d", &requests[i]);
    }
    requests[0] = currPos; // Set the first element as the current position

    // sort the requests
    for (i = 0; i <= queSize; i++) {
        for (int j = 0; j < queSize-i; j++){
            if (requests[j] > requests[j+1]){
                int temp = requests[j];
                requests[j] = requests[j+1];
                requests[j+1] = temp;
            }
        }
    }

    // Find the position in the sorted array where the current position resides
    for (i = 0; i <= queSize; i++) {
        if (requests[i] >= currPos) {
            ptr = i;
            break;
        }
    }

    int direction = (currPos > prePos) ? 1 : 0;

    if (direction == 1) {
        printf("\nScanning Towards Right... Then Towards Left...\n\n");
        for (i = ptr; i <= queSize; i++) {
            printf("%d-->", requests[i]);
            seek += abs(currPos - requests[i]);
            currPos = requests[i];
        }

        seek += abs(currPos - (cySize - 1));
        currPos = cySize-1;
        printf("%d -->", currPos);

        for (i = ptr-1; i >= 0; i--) {
            printf("%d -->", requests[i]);
            seek += abs(currPos - requests[i]);
            currPos = requests[i];
        }
    }
    else {
        printf("\nScanning Towards Left... Then Towards Right...\n\n");
        for (i = ptr; i >= 0; i--) {
            printf("%d-->", requests[i]);
            seek += abs(currPos - requests[i]);
            currPos = requests[i];
        }

        seek += currPos;
        currPos = 0;
        printf("%d -->", currPos);

        for (i = ptr+1; i <= queSize; i++) {
            printf("%d -->", requests[i]);
            seek += abs(currPos - requests[i]);
            currPos = requests[i];
        }
    }
    // Output total seek time
    printf("\n  Total Seek Time    : %d", seek);
    // Output average seek time
    printf("\n  Average Seek Time  : %.2f\n", (float)seek / queSize);

}