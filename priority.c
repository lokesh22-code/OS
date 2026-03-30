#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], p[n], pr[n];

    // Input burst time and priority
    for(i = 0; i < n; i++) {
        scanf("%d %d", &bt[i], &pr[i]); // BT and Priority
        p[i] = i + 1; // Process ID
    }

    // Sort based on priority (lower number = higher priority)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(pr[i] > pr[j]) {

                // swap priority
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

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

    // Output
    for(i = 0; i < n; i++) {
        printf("P%d WT=%d TAT=%d\n", p[i], wt[i], tat[i]);
    }

    return 0;
}
