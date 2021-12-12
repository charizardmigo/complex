//NAME: PRIESTLEY FOMECHE
//AIM: SHORTEST JOB FIRST ALGORITHM
//DATE: 13TH DECEMBER, 2021

#include <stdio.h>

int main (void)
{
    int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("\n");

    //Prompts user to input burst time for the processes
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    //sorting of burst times
        for (i = 0; i < n; i++) {
            pos = i;

            for (j = i + 1; j < n; j++) {
                if (bt[j] < bt[pos])
                    pos = j;
            }

            temp = bt[i];
            bt[i] = bt[pos];
            bt[pos] = temp;
            temp = p[i];
            p[i] = p[pos];
            p[pos] = temp;
        }

        wt[0] = 0;

        for (i = 1; i < n; i++) {
            wt[i] = 0;

            for (j = 0; j < i; j++) {
                wt[i] += bt[j];
                total += wt[i];
            }

            avg_wt = (float)total;
            total = 0;
            printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");

            for(i = 0; i < n; i++) {
                tat[i] = bt[i] + wt[i];
                total += tat[i];
                printf("\nP%d\t\t%d\t\t\t%d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
            }

            avg_tat = (float)total;
            printf("\n\nAverage Waiting Time = %.4f\n", avg_wt);
            printf("\nAverage Turnaround Time = %.4f\n", avg_tat);
        }

    return 0;
}

