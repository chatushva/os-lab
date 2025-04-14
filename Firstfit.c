#include <stdio.h>

#define MAX 25

int main() {
    int block[MAX], file[MAX], blockUsed[MAX] = {0}, fileBlock[MAX];
    int i, j, nb, nf, frag[MAX];

    printf("\nFirst Fit Memory Allocation\n");
    
    // Get number of blocks and files
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    printf("Enter number of files: ");
    scanf("%d", &nf);

    // Get sizes of blocks
    printf("\nEnter block sizes:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
    }

    // Get sizes of files
    printf("\nEnter file sizes:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &file[i]);
    }

    // First Fit Allocation
    for (i = 0; i < nf; i++) {
        fileBlock[i] = -1;  // Default to not allocated
        for (j = 0; j < nb; j++) {
            if (!blockUsed[j] && block[j] >= file[i]) {
                fileBlock[i] = j;  // Allocate block
                frag[i] = block[j] - file[i];  // Calculate fragmentation
                blockUsed[j] = 1;  // Mark block as used
                break;  // Go to next file
            }
        }
    }

    // Output result
    printf("\nFileNo\tFileSize\tBlockNo\tBlockSize\tFragment");
    for (i = 0; i < nf; i++) {
        if (fileBlock[i] != -1) {
            printf("\n%d\t%d\t\t%d\t%d\t\t%d", i + 1, file[i], fileBlock[i] + 1, block[fileBlock[i]], frag[i]);
        } else {
            printf("\n%d\t%d\t\tNot Allocated", i + 1, file[i]);
        }
    }

    return 0;
}

/*#include <stdio.h>
Includes the standard I/O functions like printf() and scanf().

#define MAX 25
Sets a constant MAX value to 25, which is the max number of blocks or files we can handle.

int main() { ... }
Entry point of the program.

Variable Declarations:
c
Copy
Edit
int block[MAX], file[MAX], blockUsed[MAX] = {0}, fileBlock[MAX];
int i, j, nb, nf, frag[MAX];
block[]: stores the sizes of memory blocks.

file[]: stores the sizes of files.

blockUsed[]: keeps track of which blocks have been allocated (0 = free, 1 = used).

fileBlock[]: stores which block is assigned to each file.

frag[]: stores internal fragmentation for each file.

i, j: loop counters.

nb: number of blocks.

nf: number of files.

Output Message
c
Copy
Edit
printf("\nFirst Fit Memory Allocation\n");
Just prints a title message for clarity.

Taking Input: Number of Blocks and Files
c
Copy
Edit
printf("Enter number of blocks: ");
scanf("%d", &nb);
printf("Enter number of files: ");
scanf("%d", &nf);
Reads the total number of memory blocks (nb) and files (nf).

Taking Input: Block Sizes
c
Copy
Edit
printf("\nEnter block sizes:\n");
for (i = 0; i < nb; i++) {
    printf("Block %d: ", i + 1);
    scanf("%d", &block[i]);
}
Takes size input for each block and stores it in the block[] array.

Taking Input: File Sizes
c
Copy
Edit
printf("\nEnter file sizes:\n");
for (i = 0; i < nf; i++) {
    printf("File %d: ", i + 1);
    scanf("%d", &file[i]);
}
Takes size input for each file and stores it in the file[] array.

First Fit Allocation Logic
c
Copy
Edit
for (i = 0; i < nf; i++) {
    fileBlock[i] = -1;
For each file, set the default block to -1 (meaning not allocated yet).

c
Copy
Edit
    for (j = 0; j < nb; j++) {
        if (!blockUsed[j] && block[j] >= file[i]) {
Check each block to see if it's:

Not already used (!blockUsed[j])

Large enough to fit the file (block[j] >= file[i])

c
Copy
Edit
            fileBlock[i] = j;
            frag[i] = block[j] - file[i];
            blockUsed[j] = 1;
            break;
If block is suitable:

Assign it to the file (fileBlock[i] = j)

Calculate the leftover space (fragmentation).

Mark the block as used.

break the loop, because First Fit only uses the first suitable block.

Display Output Table
c
Copy
Edit
printf("\nFileNo\tFileSize\tBlockNo\tBlockSize\tFragment");
Header for the output table.

c
Copy
Edit
for (i = 0; i < nf; i++) {
    if (fileBlock[i] != -1) {
        printf("\n%d\t%d\t\t%d\t%d\t\t%d", i + 1, file[i], fileBlock[i] + 1, block[fileBlock[i]], frag[i]);
    } else {
        printf("\n%d\t%d\t\tNot Allocated", i + 1, file[i]);
    }
}
For each file:

If it was allocated, print its number, size, block number, block size, and internal fragmentation.

If not allocated, display "Not Allocated".

return 0;
Ends the main() function cleanly.

✅ Let Me Know If You Want:

First Fit Memory Allocation
Enter number of blocks: 3
Enter number of files: 2

Enter block sizes:
Block 1: 100
Block 2: 500
Block 3: 200

Enter file sizes:
File 1: 120
File 2: 150

FileNo	FileSize	BlockNo	BlockSize	Fragment
1	120		2	500		380
2	150		3	200		50
*/
