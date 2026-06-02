#include <stdio.h>

int main()
{
    int n,frames;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    int pages[n];

    for(int i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&frames);

    int frame[frames];
    int recent[frames];

    for(int i=0;i<frames;i++)
    {
        frame[i]=-1;
        recent[i]=0;
    }

    int faults=0;

    for(int i=0;i<n;i++)
    {
        int found=0;

        for(int j=0;j<frames;j++)
        {
            if(frame[j]==pages[i])
            {
                recent[j]=i;
                found=1;
                break;
            }
        }

        if(!found)
        {
            int lru=0;

            for(int j=1;j<frames;j++)
            {
                if(recent[j]<recent[lru])
                    lru=j;
            }

            frame[lru]=pages[i];
            recent[lru]=i;
            faults++;
        }
    }

    printf("Page Faults = %d\n",faults);

    return 0;
}
