#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int max_range, n, initial_head;
    int queue[100]; // Assuming a maximum of 100 requests
    int visited[100] = {0}; // To track processed requests
    int total_seek_time = 0;

    // Input in the exact format from the image
    printf("Enter the maximum range of Disk: ");
    scanf("%d", &max_range);
    printf("Enter the number of queue requests: ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &initial_head);
    printf("Enter the disk positions to be read(queue):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Process using SSTF algorithm
    printf("\n");
    int current_head = initial_head;
    for (int i = 0; i < n; i++) {
        // Find the closest unvisited position
        int min_seek = INT_MAX;
        int next_pos = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int seek = abs(current_head - queue[j]);
                if (seek < min_seek) {
                    min_seek = seek;
                    next_pos = j;
                }
            }
        }

        // Mark the position as visited and calculate seek
        visited[next_pos] = 1;
        int seek = abs(current_head - queue[next_pos]);
        total_seek_time += seek;

        // Print in the requested format
        printf("head movement from %d to %d :%d\n", current_head, queue[next_pos], seek);
        current_head = queue[next_pos];
    }

    // Print total and average seek time
    float average_seek_time = (float)total_seek_time / n;
    printf("\n");
    printf("Total seek Time= %d\n", total_seek_time);
    printf("Average Seek Time= %.5f\n", average_seek_time);

    return 0;
}