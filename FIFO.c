#include <stdio.h>

int main() {
    int n, f, rs[25], m[10], i, j, k, pf = 0, pos = 0;

    printf("Enter length of reference string: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) 
    m[i] = -1;

    printf("\nPage Replacement Process:\n");

    for(i = 0; i < n; i++) {
        for(k = 0; k < f; k++)
            if(m[k] == rs[i]) break;

        if(k == f) { // page not found
            m[pos] = rs[i];
            pos = (pos + 1) % f;
            pf++;
            for(j = 0; j < f; j++)
                printf("%d ", m[j]);
            printf("  Page Fault %d", pf);
        } else {
            for(j = 0; j < f; j++)
                printf("%d ", m[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pf);
    return 0;
}


// ---

// Line-by-Line Explanation (Simplified):

// #include <stdio.h>

// Includes standard I/O functions (printf, scanf).



// ---

// int main() {

// Start of the program.



// ---

// int n, f, rs[25], m[10], i, j, k, pf = 0, pos = 0;

// n: length of reference string

// f: number of frames

// rs[25]: holds up to 25 page requests

// m[10]: memory frames (up to 10)

// i, j, k: loop variables

// pf: page fault counter

// pos: keeps track of which frame to replace (FIFO pointer)



// ---

// printf("Enter length of reference string: ");
// scanf("%d", &n);

// Ask user how many pages in the reference string.



// ---

// printf("Enter reference string: ");
// for(i = 0; i < n; i++)
//     scanf("%d", &rs[i]);

// Take the actual page numbers.



// ---

// printf("Enter number of frames: ");
// scanf("%d", &f);

// Ask how many memory slots are available.



// ---

// for(i = 0; i < f; i++) m[i] = -1;

// Initialize memory frames as empty (-1 means empty).



// ---

// printf("\nPage Replacement Process:\n");

// Just a heading for output.



// ---

// Main FIFO Logic:

// for(i = 0; i < n; i++) {

// Loop through each page request.



// ---

// for(k = 0; k < f; k++)
//         if(m[k] == rs[i]) break;

// Check if the page is already in memory.



// ---

// if(k == f) {

// If page is not found in memory:


// m[pos] = rs[i];  // Replace the oldest page
//         pos = (pos + 1) % f;  // Move to next position (circular)
//         pf++;  // Page fault occurred


// ---

// for(j = 0; j < f; j++)
//             printf("%d ", m[j]);  // Print memory state
//         printf("  Page Fault %d", pf);  // Print fault number
//     } else {
//         for(j = 0; j < f; j++)
//             printf("%d ", m[j]);  // Just print state (no fault)
//     }
//     printf("\n");

// Shows the content of frames after each step.



// ---

// printf("\nTotal Page Faults: %d\n", pf);

// Final count of how many page faults occurred.



// ---

// return 0;
// }

/* Enter length of reference string: 10
Enter reference string: 1 
2
3
4
2
1
5
2
4
3
Enter number of frames: 3

Page Replacement Process:
1 -1 -1   Page Fault 1
1 2 -1   Page Fault 2
1 2 3   Page Fault 3
4 2 3   Page Fault 4
4 2 3 
4 1 3   Page Fault 5
4 1 5   Page Fault 6
2 1 5   Page Fault 7
2 4 5   Page Fault 8
2 4 3   Page Fault 9

Total Page Faults: 9
*/
