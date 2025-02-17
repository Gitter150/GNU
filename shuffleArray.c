#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void shuffle(int *arr, int n){
    int used[n];
    for(int i=0;i<n;i++) used[i] = 0;
    int temp[n];
    srand(time(NULL));
    int random;
    int shuffled_indices[n];
    
    for(int i=0;i<n;i++){
        while(1) {
            random = rand() % n;
            if(!used[random]) {
                used[random] = 1;
                break;
            }
        }
        shuffled_indices[i] = random;
    }

    for(int i=0;i<n;i++) temp[i] = arr[shuffled_indices[i]];
    
    for(int i=0;i<n;i++) arr[i] = temp[i];
}

int main() {
    int arrayToBeShuffled[] = {0,5,2,5,7,6,5432}; // Actual array to be shuffled. Modify it at your will!
    int len = (int) sizeof(arrayToBeShuffled)/sizeof(arrayToBeShuffled[0]); 

    shuffle(arrayToBeShuffled, len); 

    printf("The shuffled array is\n");
    for(int i=0;i<len;i++) printf("%d ",arrayToBeShuffled[i]);
    printf("\n");

    return 0;
}
