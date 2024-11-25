#include <iostream>
#include <vector>

using namespace std;

void findWaitingTime(const vector<int>& processes, int numberOfProcesses, const vector<int>& burstTime, vector<int>& waitingTime) {
    vector<int> completionTime(numberOfProcesses);
    completionTime[0] = burstTime[0];
    waitingTime[0] = 0;

    for (int i = 1; i < numberOfProcesses; i++) {
        completionTime[i] = completionTime[i - 1] + burstTime[i - 1];
        waitingTime[i] = completionTime[i] - burstTime[i];
    }
}

void findTurnaroundTime(const vector<int>& processes, int numberOfProcesses, const vector<int>& burstTime, const vector<int>& waitingTime, vector<int>& turnaroundTime) {
    for (int i = 0; i < numberOfProcesses; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }
}

void findAverageTime(const vector<int>& processes, int numberOfProcesses, const vector<int>& burstTime) {
    vector<int> waitingTime(numberOfProcesses), turnaroundTime(numberOfProcesses);

    findWaitingTime(processes, numberOfProcesses, burstTime, waitingTime);
    findTurnaroundTime(processes, numberOfProcesses, burstTime, waitingTime, turnaroundTime);

    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < numberOfProcesses; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < numberOfProcesses; i++) {
        cout << processes[i] << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << static_cast<float>(totalWaitingTime) / numberOfProcesses << "\n";
    cout << "Average Turnaround Time: " << static_cast<float>(totalTurnaroundTime) / numberOfProcesses << "\n";
}

int main() {
    vector<int> processes = {1, 2, 3};
    int numberOfProcesses = processes.size();
    vector<int> burstTime = {6, 8, 7};

    findAverageTime(processes, numberOfProcesses, burstTime);

    return 0;
}
