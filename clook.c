#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int headposition, n, i, j, k, seek = 0, maxrange = 199;
    int difference, temp, temp1 = 0, temp2 = 0;
    float averageSeekTime;
    printf("Enter the number of queue requests: ");
    scanf("%d", &n);
    int queue[n], queue1[n], queue2[n];
    printf("Enter the head position: ");
    scanf("%d", &headposition);
    printf("Enter the disk positions to be read (queue): ");
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    for(i = 0; i < n; i++) {
        if(queue[i] < headposition) {
            queue1[temp1] = queue[i];
            temp1++;
        } else if(queue[i] > headposition) {
            queue2[temp2] = queue[i];
            temp2++;
        }
    }
    for(i = 0; i < temp1 - 1; i++) {
        for(j = i + 1; j < temp1; j++) {
            if(queue1[i] > queue1[j]) {
                int temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    } 
    for(i = 0; i < temp2 - 1; i++) {
        for(j = i + 1; j < temp2; j++) {
            if(queue2[i] > queue2[j]) {
                int temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }
    printf("\nC-LOOK Order: %d", headposition);
    for(i = 0; i < temp2; i++) {
        seek += abs(headposition - queue2[i]);
        headposition = queue2[i];
        printf(" -> %d", headposition);
    }
    if(temp1 > 0) {
        int smallest = queue1[0];
        seek += abs(headposition - smallest);
        headposition = smallest;
        printf(" -> %d", headposition);
        for(i = 1; i < temp1; i++) {
            seek += abs(headposition - queue1[i]);
            headposition = queue1[i];
            printf(" -> %d", headposition);
        }
    } 
    printf("\n\nTotal Head Movement: %d", seek);
    printf("\nAverage Head Movement: %.2f\n", (float)seek / n); 
    return 0;
}

