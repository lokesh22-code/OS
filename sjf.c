#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], p[n];

    // Input burst time and assign process IDs
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        p[i] = i + 1;   // P1, P2, P3...
    }

    // Sort burst time + process ID together
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(bt[i] > bt[j]) {

                // swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // swap process ID
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
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

    // Output (correct process order)
    for(i = 0; i < n; i++) {
        printf("P%d WT=%d TAT=%d\n", p[i], wt[i], tat[i]);
    }

    return 0;
}
