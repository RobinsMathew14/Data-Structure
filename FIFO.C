#include <stdio.h>

void fifoPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity], front = 0, pageFaults = 0, pageHits = 0;

    for (int i = 0; i < capacity; i++)
        frames[i] = -1; // Initialize frames as empty

    printf("\nFIFO Page Replacement:\n");
    printf("----------------------------\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;

        // Check if page is already in frames (Page Hit)
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                found = 1;
                pageHits++;
                break;
            }
        }

        // If page is not found, replace using FIFO
        if (!found) {
            frames[front] = page;
            front = (front + 1) % capacity;
            pageFaults++;
        }

        // Print frame contents
        printf("Page %d -> [", page);
        for (int j = 0; j < capacity; j++) {
            if (frames[j] != -1)
                printf(" %d ", frames[j]);
            else
                printf(" - ");
        }
        printf("] %s\n", found ? "Hit  " : "Miss  ");
    }

    float hitRatio = (float) pageHits / n;
    float missRatio = (float) pageFaults / n;

    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);
    printf("Hit Ratio: %.2f\n", hitRatio);
    printf("Miss Ratio: %.2f\n", missRatio);
}

int main() {
    int n, capacity;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &capacity);

    fifoPageReplacement(pages, n, capacity);

    return 0;
}