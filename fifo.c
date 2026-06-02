#include <stdio.h>

int main()
{
    int n,frames;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    int pages[n];

    printf("Enter page reference string:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&frames);

    int frame[frames];
    int count=0,faults=0,front=0;

    for(int i=0;i<frames;i++)
        frame[i]=-1;

    for(int i=0;i<n;i++)
    {
        int found=0;

        for(int j=0;j<frames;j++)
        {
            if(frame[j]==pages[i])
            {
                found=1;
                break;
            }
        }

        if(!found)
        {
            frame[front]=pages[i];
            front=(front+1)%frames;
            faults++;
        }
    }

    printf("Page Faults = %d\n",faults);

    return 0;
}
