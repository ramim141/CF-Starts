#include <stdio.h>

void calculateWaitingTime(int processIds[], int numberOfProcesses, int burstTimes[], int waitingTimes[]) {
    waitingTimes[0] = 0; // Waiting time for the first process is 0
    for (int i = 1; i < numberOfProcesses; i++) {
        waitingTimes[i] = burstTimes[i - 1] + waitingTimes[i - 1];
    }
}

void calculateTurnaroundTime(int processIds[], int numberOfProcesses, int burstTimes[], int waitingTimes[], int turnaroundTimes[]) {
    for (int i = 0; i < numberOfProcesses; i++) {
        turnaroundTimes[i] = burstTimes[i] + waitingTimes[i];
    }
}

void calculateAverageTimes(int processIds[], int numberOfProcesses, int burstTimes[]) {
    int waitingTimes[numberOfProcesses], turnaroundTimes[numberOfProcesses];
    calculateWaitingTime(processIds, numberOfProcesses, burstTimes, waitingTimes);
    calculateTurnaroundTime(processIds, numberOfProcesses, burstTimes, waitingTimes, turnaroundTimes);

    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < numberOfProcesses; i++) {
        totalWaitingTime += waitingTimes[i];
        totalTurnaroundTime += turnaroundTimes[i];
    }

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < numberOfProcesses; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processIds[i], burstTimes[i], waitingTimes[i], turnaroundTimes[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / numberOfProcesses);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / numberOfProcesses);
}

int main() {
    int processIds[] = {1, 2, 3};
    int numberOfProcesses = sizeof(processIds) / sizeof(processIds[0]);
    int burstTimes[] = {6, 8, 7};

    calculateAverageTimes(processIds, numberOfProcesses, burstTimes);
    return 0;
}
