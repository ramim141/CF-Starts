#include<bits/stdc++.h>
using namespace std;

#define MAX_PROCESSES 10

struct Process {
    int pid;
    int burst_time;
    int priority;
    int completion_time;
    int waiting_time;
};

void swap(struct Process *xp, struct Process *yp) {
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortProcesses(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void priorityScheduling(struct Process processes[], int n) {
    int time = 0;
    float total_waiting_time = 0;

    cout<<"Gantt Chart:"<<endl;
    cout<<"0";

    for (int i = 0; i < n; i++) {
        time += processes[i].burst_time;
        processes[i].completion_time = time;
        processes[i].waiting_time = time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        cout<<" -- P"<<processes[i].pid<<" -- "<< time;
    }

    cout<<endl;
    cout<<"Average Waiting Time: "<< (float)total_waiting_time/n << endl;
}

int main() {
    int n;
    struct Process processes[MAX_PROCESSES];
    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter burst time and priority for each process "<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"Process "<<i+1<<endl;
        cout<<"Burst time: ";
        cin>>processes[i].burst_time;
        cout<<"Priority: ";
        cin>>processes[i].priority;
        processes[i].pid = i + 1;
    }
    sortProcesses(processes, n);
    priorityScheduling(processes, n);
    return 0;
}