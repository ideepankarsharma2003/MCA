#include <stdio.h>

int main()
{
    int num_frames, num_pages, frames[10], pages[30], temp[10];
    int flag1, flag2, flag3, i, j, k, pos, max, faults = 0, hit;

    printf("Enter number of frames: ");
    scanf("%d", &num_frames);

    printf("Enter number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter page references string: ");
    for (i = 0; i < num_pages; i++)
    {
        scanf("%d", &pages[i]);
    }

    // Initialize frames with -1 as initial value
    for (i = 0; i < num_frames; i++)
    {
        frames[i] = -1;
    }

    for (i = 0; i < num_pages; i++)
    {
        flag1 = flag2 = 0;
        hit = 0;

        // Check if page is already in frame
        for (j = 0; j < num_frames; j++)
        {
            if (frames[j] == pages[i])
            {
                flag1 = flag2 = 1;
                hit = 1;
                break;
            }
        }

        // If page is not in frame (Page Fault)
        if (flag1 == 0)
        {
            for (j = 0; j < num_frames; j++)
            {
                // Find a free frame
                if (frames[j] == -1)
                {
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        // If there is no free frame
        if (flag2 == 0)
        {
            flag3 = 0;
            for (j = 0; j < num_frames; j++)
            {
                temp[j] = -1;
                for (k = i + 1; k < num_pages; k++)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < num_frames; j++)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            // All pages in frames will be referred for long time
            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;
                for (j = 1; j < num_frames; j++)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            faults++;
        }

        if (hit == 0)
        {
            printf("\n");
            for (j = 0; j < num_frames; j++)
            {
                printf("%d\t", frames[j]);
            }
        }
    }

    printf("\n\nTotal Page Faults = %d\n\n", faults);

    return 0;
}
