#include <stdio.h>

#define MAX_FRAMES 3  // Number of frames

int isPageInMemory(int frames[], int page) {
    for (int i = 0; i < MAX_FRAMES; i++)
        if (frames[i] == page)
            return 1;
    return 0;
}

void fifoPageReplacement(int pages[], int numPages) {
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int front = 0, pageFaults = 0;

    printf("Page Reference String:\n");
    for (int i = 0; i < numPages; i++) {
        printf("%d -> ", pages[i]);
        
        if (!isPageInMemory(frames, pages[i])) {
            frames[front] = pages[i];
            front = (front + 1) % MAX_FRAMES; // Circular queue
            pageFaults++;
        }

        // Display current frames
        for (int j = 0; j < MAX_FRAMES; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int numPages = sizeof(pages) / sizeof(pages[0]);
    
    fifoPageReplacement(pages, numPages);
    
    return 0;
}
