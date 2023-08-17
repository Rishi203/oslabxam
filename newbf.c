#include <stdio.h>

int main() {
    int bno, pno, bsize[10], psize[10];
    int i, j;
    int alloc[10];

    for(i=0; i<10; i++){
        alloc[i] = -1;
    }
    printf("Enter the number of BLOCKS: ");
    scanf("%d", &bno);

    printf("Enter the BLOCK size: ");
    for (i = 0; i < bno; i++) {
        scanf("%d", &bsize[i]);
    }

    printf("Enter the number of PROCESSES: ");
    scanf("%d", &pno);

    printf("Enter the PROCESS size: ");
    for (i = 0; i < pno; i++) {
        scanf("%d", &psize[i]);
    }

    for (i = 0; i < pno; i++) {
        int bestBlock = -1;
        for (j = 0; j < bno; j++) {
            if (bsize[j] >= psize[i]) {
                if (bestBlock == -1 || bsize[j] < bsize[bestBlock]) {
                    bestBlock = j;
                }
            }
        }

        if (bestBlock != -1) {
            alloc[i] = bestBlock;
            bsize[bestBlock] -= psize[i];
        }
    }

    printf("PNO \t PSIZE \t Block number \t Fragment Size\n");

    for (i = 0; i < pno; i++) {
        if (alloc[i] != -1) {
            printf("%d \t %d \t %d \t\t %d\n", i, psize[i], alloc[i], bsize[alloc[i]]);
        } else {
            printf("%d \t %d \t not allocated\n", i, psize[i]);
        }
    }

    return 0;
}
