#include <stdio.h>
#include <stdbool.h>
int main() {
    int n, m, i, j, k;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the number of resource types: ");
    scanf("%d", &m);
    
    int alloc[n][m], max[n][m], need[n][m];
    int avail[m], work[m], safeSeq[n];
    bool finish[n];
    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("\nEnter Max Matrix:\n");
    for(i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("\nEnter Available Resources: ");
    for(j = 0; j < m; j++) {
        scanf("%d", &avail[j]);
        work[j] = avail[j];
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    for(i = 0; i < n; i++) {
        finish[i] = false;
    }
    
    int count = 0;
    bool found;
    while(count < n) {
        found = false;
        
        for(i = 0; i < n; i++) {
            if(!finish[i]) {
                bool canAllocate = true;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                
                if(canAllocate) {
                    for(j = 0; j < m; j++) {
                        work[j] += alloc[i][j];
                    }
                    
                    safeSeq[count] = i;
                    finish[i] = true;
                    count++;
                    found = true;
                }
            }
        }
        if(!found) {
            printf("\nSystem is in an UNSAFE state!");
            return 0;
        }
    }
    printf("\nSystem is in SAFE state.");
    printf("\nSafe Sequence: ");
    for(i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
        if(i < n - 1) printf("-> ");
    }
    printf("\n");
    
    return 0;
}
