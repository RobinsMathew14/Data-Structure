#include <stdio.h>

int main() {
    int frames, pages, page_faults = 0, flag, pointer = 0;
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    
    int page_sequence[pages], frame[frames], status[pages];
    
    printf("Enter the page reference string:\n");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &page_sequence[i]);
    }

    // Initialize frames
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    // Process pages
    for (int i = 0; i < pages; i++) {
        flag = 0;

        // Check if page already in frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page_sequence[i]) {
                flag = 1;
                break;
            }
        }

        // If page not found, do replacement
        if (flag == 0) {
            frame[pointer] = page_sequence[i];
            pointer = (pointer + 1) % frames; // FIFO logic
            page_faults++;
            status[i] = 0; // Miss
        } else {
            status[i] = 1; // Hit
        }
    }

    // Print table header (pages)
    printf("\n        ");
    for (int i = 0; i < pages; i++) {
        printf("|  %-3d", page_sequence[i]);
    }
    printf("\n");

    // Print line after page numbers
    printf("--------");
    for (int i = 0; i < pages; i++) {
        printf("|------");
    }
    printf("\n");

    // Print each frame (f0, f1, f2...)
    for (int f = 0; f < frames; f++) {
        printf("f%-6d", f);
        for (int i = 0; i < pages; i++) {
            // Show what is present in frame `f` after ith page request
            int temp_frames[frames], temp_pointer = 0, found = 0;

            // Simulation again till current i to get frame status
            for (int j = 0; j < frames; j++) temp_frames[j] = -1;

            temp_pointer = 0;
            for (int k = 0; k <= i; k++) {
                int hit = 0;
                for (int j = 0; j < frames; j++) {
                    if (temp_frames[j] == page_sequence[k]) {
                        hit = 1;
                        break;
                    }
                }

                if (!hit) {
                    temp_frames[temp_pointer] = page_sequence[k];
                    temp_pointer = (temp_pointer + 1) % frames;
                }
            }

            // Print content of frame f
            if (temp_frames[f] != -1)
                printf("|  %-3d", temp_frames[f]);
            else
                printf("|      ");
        }
        printf("\n");

        // Divider line after each frame row
        printf("--------");
        for (int i = 0; i < pages; i++) {
            printf("|------");
        }
        printf("\n");
    }

    // Print hit/miss status row
    printf("        ");
    for (int i = 0; i < pages; i++) {
        if (status[i] == 1)
            printf("|   ✔️ ");
        else
            printf("|   X  ");
    }

    printf("\n\nTotal Page Faults = %d\n", page_faults);

    return 0;
}