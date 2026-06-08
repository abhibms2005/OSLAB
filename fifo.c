#include<stdio.h>

int search(int frames[], int cap, int key){
    for(int i=0; i<cap; i++){
        if(frames[i] == key){
            return 1;
        }
    }
    return 0;
}

void printframes(int frames[], int cap){
    for(int i=0; i<cap; i++){
        printf("%d\t", frames[i]);
    }
    printf("\n");
}

int main(){

    int pages[100],capacity,n; //string lngth=no. of pages(n)
    int frames[100];

    printf("ENter number of pages: ");
    scanf("%d", &n);
    printf("ENter no of frames: ");
    scanf("%d", &capacity);
    printf("Enter string: ");
    for (int i=0; i<n; i++){
        scanf("%d", &pages[i]);
    }
    
    for(int i=0; i<capacity; i++){
        frames[i] = -1;
    }

    int faults = 0;
    int front = 0;

    for(int i=0; i<n; i++){
        if(!search(frames, capacity, pages[i])){
            frames[front] = pages[i];
            front = (front+1)%capacity;
            faults++;
        }
        printframes(frames, capacity);
    }

    printf("Total no of faults = %d", faults);

}