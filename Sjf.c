#include<stdio.h>

struct process{
    int pid;
    int at;
    int bt;
};

void main(){
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process parr[n];

    for(i = 0; i < n; i++){
        parr[i].pid = i + 1;
        printf("Enter the arrival and burst time of process %d:", i + 1);
        scanf("%d %d", &parr[i].at, &parr[i].bt);
    }

    // Sort processes by burst time (SJF)
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(parr[j].bt > parr[j+1].bt){
                struct process temp = parr[j];
                parr[j] = parr[j + 1];
                parr[j + 1] = temp;
            }
        }
    }

    int ct[n];
    int tat[n];
    int wt[n];
    int current = 0;
    for(i = 0; i < n; i++){
        if(current < parr[i].at){
            current = parr[i].at;
        }
        current += parr[i].bt;
        ct[i] = current;
    }

    for(i = 0; i < n; i++){
        tat[i] = ct[i] - parr[i].at;
    }
    for(i = 0; i < n; i++){
        wt[i] = tat[i] - parr[i].bt;
    }
    float totaltat = 0;
    float totalwt = 0;

    for(i = 0; i < n; i++){
        totaltat += tat[i];
        totalwt += wt[i];
    }

    float avgwt = totalwt / n;
    float avgtat = totaltat / n;
    printf("\npid\tarrival time\tburst time\tcompletion time\tturnaround time\twaiting time\n");
    for(i = 0; i < n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n", parr[i].pid, parr[i].at, parr[i].bt, ct[i], tat[i], wt[i]);
    }

    printf("Average turnaround time: %f\n", avgtat);
    printf("Average waiting time: %f\n", avgwt);

    printf("Gantt chart\n");

    int currenttime = 0;

    for(i = 0; i < n; i++){
        while(currenttime < parr[i].at){
            printf(" . ");
            currenttime++;
        }
        printf("|");
        while(currenttime < ct[i]){
            printf("P%d|", parr[i].pid);
            currenttime++;
        }
    }
}
