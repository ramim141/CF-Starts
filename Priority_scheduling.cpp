#include <iostream>
#include <vector>

using namespace std;

void findWaitingTime(const vector<int>& processes, int n, const vector<int>& burstTime, vector<int>& waitingTime, const vector<int>& priority) {
    vector<int> completionTime(n);
    completionTime[0] = burstTime[0];
    waitingTime[0] = 0;

    for (int i = 1; i < n; i++) {
        completionTime[i] = completionTime[i - 1] + burstTime[i - 1];
        waitingTime[i] = completionTime[i] - burstTime[i];
    }
}

void findTurnaroundTime(const vector<int>& processes, int n, const vector<int>& burstTime, const vector<int>& waitingTime, vector<int>& turnaroundTime) {
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }
}

void findAverageTime(const vector<int>& processes, int n, const vector<int>& burstTime, const vector<int>& priority) {
    vector<int> waitingTime(n), turnaroundTime(n);

    findWaitingTime(processes, n, burstTime, waitingTime, priority);
    findTurnaroundTime(processes, n, burstTime, waitingTime, turnaroundTime);

    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i] << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << static_cast<float>(totalWaitingTime) / n << "\n";
    cout << "Average Turnaround Time: " << static_cast<float>(totalTurnaroundTime) / n << "\n";
}

int main() {
    vector<int> processes = {1, 2, 3};
    int n = processes.size();
    vector<int> burstTime = {6, 8, 7};
    vector<int> priority = {2, 1, 3}; // Lower number means higher priority

    findAverageTime(processes, n, burstTime, priority);
    return 0;
}
