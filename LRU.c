#include <stdio.h>
int main() {
    int i, j, k, min, rs[25], m[10], count[10], flag[25];
    int n, f, pf = 0, next = 1;

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
        flag[i] = 0;
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        count[i] = 0;
        m[i] = -1;
    }

    printf("\nThe Page Replacement process is:\n");

    for (i = 0; i < n; i++) {
        int found = 0;

        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                flag[i] = 1;
                count[j] = next++;
                found = 1;
                break;
            }
        }

        if (!found) {
            int replaceIndex = 0;

            // If frames aren't full yet
            if (i < f) {
                replaceIndex = i;
            } else {
                for (j = 1; j < f; j++) {
                    if (count[replaceIndex] > count[j])
                        replaceIndex = j;
                }
            }

            m[replaceIndex] = rs[i];
            count[replaceIndex] = next++;
            pf++;
        }

        for (j = 0; j < f; j++)
            printf("%d\t", m[j]);
        if (!flag[i])
            printf("PF No. -- %d", pf);
        printf("\n");
    }

    printf("\nTotal Page Faults using LRU: %d\n", pf);
    return 0;
}


// ---

// Line-by-Line Explanation:

// 1. #include <stdio.h>
// Includes the standard input-output library.


// 2. int main()
// The main function where execution begins.


// 3. Variable Declarations

// rs[25]: Reference string array.

// m[10]: Memory frames.

// count[10]: Used for tracking recency for LRU.

// flag[25]: Marks whether a page hit occurred.

// n: Length of the reference string.

// f: Number of frames.

// pf: Page fault count.

// next: Logical counter to keep track of how recently a page was used.



// 4. Input reference string length and elements
// scanf inputs reference string length and then the elements of the reference string into rs.


// 5. Input frame count
// Takes number of memory frames.


// 6. Initialize memory and counters
// All memory slots (m) are set to -1 and count to 0.


// 7. Start page replacement simulation
// For each page in the reference string:


// 8. Check if the page is already in memory (Page Hit)
// If found, update the count with the latest next value.


// 9. If page is not in memory (Page Fault)

// If frame slots are still filling up, use the next free frame.

// Else, replace the least recently used page by checking the smallest value in count.



// 10. Update memory and counters
// Replace the page and increase the next and pf.


// 11. Print current frame status and page fault info


// 12. After all iterations, print total page faults.




// ---

// Want me to add comments directly in the minimized code as well?

//Enter the length of reference string: 5
Enter the reference string: 1
2
5
3
7
Enter the number of frames: 4

The Page Replacement process is:
1	-1	-1	-1	PF No. -- 1
1	2	-1	-1	PF No. -- 2
1	2	5	-1	PF No. -- 3
1	2	5	3	PF No. -- 4
7	2	5	3	PF No. -- 5

Total Page Faults using LRU: 5
