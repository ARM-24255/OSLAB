#include <stdio.h>

int main()
{
    int m, n, i, j, choice;
    int block[20], blockSize[20], process[20];
    int allocation[20], index;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter sizes of memory blocks:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter sizes of processes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &process[i]);

    printf("\nMemory Allocation Techniques");
    printf("\n1. First Fit");
    printf("\n2. Best Fit");
    printf("\n3. Worst Fit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    for(i = 0; i < m; i++)
        blockSize[i] = block[i];

    for(i = 0; i < n; i++)
        allocation[i] = -1;

    switch(choice)
    {
        case 1:
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < m; j++)
                {
                    if(blockSize[j] >= process[i])
                    {
                        allocation[i] = j;
                        blockSize[j] -= process[i];
                        break;
                    }
                }
            }
            printf("\nFirst Fit Allocation\n");
            break;

        case 2:
            for(i = 0; i < n; i++)
            {
                index = -1;
                for(j = 0; j < m; j++)
                {
                    if(blockSize[j] >= process[i])
                    {
                        if(index == -1 || blockSize[j] < blockSize[index])
                            index = j;
                    }
                }

                if(index != -1)
                {
                    allocation[i] = index;
                    blockSize[index] -= process[i];
                }
            }
            printf("\nBest Fit Allocation\n");
            break;

        case 3:
            for(i = 0; i < n; i++)
            {
                index = -1;
                for(j = 0; j < m; j++)
                {
                    if(blockSize[j] >= process[i])
                    {
                        if(index == -1 || blockSize[j] > blockSize[index])
                            index = j;
                    }
                }

                if(index != -1)
                {
                    allocation[i] = index;
                    blockSize[index] -= process[i];
                }
            }
            printf("\nWorst Fit Allocation\n");
            break;

        default:
            printf("Invalid Choice!\n");
            return 0;
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
