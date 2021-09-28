//
// Created by Павел Бахаруев on 28.09.2021.
//
#include <stdio.h>
#include <stdbool.h>
//Struct of the Process
typedef struct Process{
    int start;
    int end;
    int wt;
    int ct;
    int tat;
    bool done;
}Process;

int main(){
    int n;
    Process Processes[100];
    printf("Enter arrival time and Burst of each process and number of processes: ");
    scanf("%d",&n);

    //input
    for (int i = 0; i < n; i++) {
        printf("\n");
        printf("Start time of process [%d] ", i);
        scanf("%d", &Processes[i].start);
        printf("End time of process [%d] ", i);
        scanf("%d", &Processes[i].end);
        Processes[i].done = 0;
    }
    //Sort by the end (burst) time
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (Processes[j].end > Processes[j+1].end){
                Process t = Processes[j];
                Processes[j] = Processes[j+1];
                Processes[j+1] = t;
            }
        }
    }
    int time = 0;
    float tat_sum = 0;
    float wt_sum = 0;
    //execute processes
    for (int i = 0; i < n; i++) {
        int start_min = 9999;
        int process_index = -1;
        for (int j = 0; j < n; j++) {
            if (Processes[j].start <= time && !Processes[j].done) {
                process_index = j;
                break;
            }
        }
        //check if the previous cycle not met
        if (process_index == -1) {
            int start_min = 999;
            for (int j = 0; j < n; j++) {
                if (Processes[j].start < start_min && !Processes[j].done) {
                    start_min = Processes[j].start;
                    process_index = i;
                }
            }
        }
        //special cases
        Processes[process_index].wt = time - start_time_min;
        if(Processes[process_index].wt < 0){
            Processes[process_index].wt = 0;
        }

        Processes[process_index].ct = time + Processes[process_index].end;
        time = Processes[process_index].end;

        Processes[process_index].done = 1;

        Processes[process_index].ct = time + Processes[process_index].end;
        time = Processes[process_index].end;
        printf("\nProcess %d\n", process_index);
        printf("AT is %d\n", Processes[process_index].start);
        printf("WT is %d\n", Processes[process_index].wt);
        Processes[process_index].tat = Processes[process_index].ct - Processes[process_index].start;
        printf("TAT is %d\n", Processes[process_index].tat);
        Processes[process_index].done = 1;
        tat_sum += Processes[process_index].tat;
        wt_sum += Processes[process_index].wt;
    }
    printf("\n---\nAverage WT of %d processes is %.2f\n", n, wt_sum/n);
    printf("Average TAT of %d processes is  %.2f\n", n, tat_sum/n);
}
