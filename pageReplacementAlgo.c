#include <stdio.h>

void FIFO(int pages[], int n, int frames)
{
    int frame[20], i, j, k = 0, fault = 0, found;

    for (i = 0; i < frames; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++)
    {
        found = 0;

        for (j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            frame[k] = pages[i];
            k = (k + 1) % frames;
            fault++;
        }
    }

    printf("Page Faults = %d\n", fault);
}

void LRU(int pages[], int n, int frames)
{
    int frame[20], time[20];
    int i, j, fault = 0, count = 0;
    int found, pos, min;

    for (i = 0; i < frames; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        found = 0;

        for (j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            min = time[0];
            pos = 0;

            for (j = 1; j < frames; j++)
            {
                if (time[j] < min)
                {
                    min = time[j];
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            count++;
            time[pos] = count;
            fault++;
        }
    }

    printf("Page Faults = %d\n", fault);
}

void Optimal(int pages[], int n, int frames)
{
    int frame[20];
    int i, j, k, fault = 0;
    int found, pos, farthest;

    for (i = 0; i < frames; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++)
    {
        found = 0;

        for (j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            int empty = -1;

            for (j = 0; j < frames; j++)
            {
                if (frame[j] == -1)
                {
                    empty = j;
                    break;
                }
            }

            if (empty != -1)
            {
                frame[empty] = pages[i];
            }
            else
            {
                farthest = -1;
                pos = -1;

                for (j = 0; j < frames; j++)
                {
                    int nextUse = 9999;

                    for (k = i + 1; k < n; k++)
                    {
                        if (frame[j] == pages[k])
                        {
                            nextUse = k;
                            break;
                        }
                    }

                    if (nextUse > farthest)
                    {
                        farthest = nextUse;
                        pos = j;
                    }
                }

                frame[pos] = pages[i];
            }

            fault++;
        }
    }

    printf("Page Faults = %d\n", fault);
}

int main()
{
    int n, frames, choice;
    int pages[50], i;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("\nPage Replacement Algorithms\n");
    printf("1. FIFO\n");
    printf("2. LRU\n");
    printf("3. Optimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        FIFO(pages, n, frames);
        break;

    case 2:
        LRU(pages, n, frames);
        break;

    case 3:
        Optimal(pages, n, frames);
        break;

    default:
        printf("Invalid Choice\n");
    }

    return 0;
}
