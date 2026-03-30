#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    // Input burst time
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    // Calculate waiting time
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Output
    for(i = 0; i < n; i++) {
        printf("P%d WT=%d TAT=%d\n", i+1, wt[i], tat[i]);
    }

    return 0;
}
