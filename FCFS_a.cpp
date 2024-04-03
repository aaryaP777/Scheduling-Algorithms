#include <iostream>
using namespace std;

void waitingtime(int processes[], int n, int burstTime[], int waitingTime[])
{
    waitingTime[0] = 0;

    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = burstTime[i - 1] + waitingTime[i - 1];
    }
}

void turnaroundtime(int processes[], int n, int burstTime[], int waitingTime[], int turnAroundTime[])
{
    for (int i = 0; i < n; i++)
    {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }
}

void avgtime(int processes[], int n, int burstTime[])
{
    int waitingTime[n], turnAroundTime[n], total_wt = 0, total_tat = 0;

    waitingtime(processes, n, burstTime, waitingTime);

    turnaroundtime(processes, n, burstTime, waitingTime, turnAroundTime);

    cout << "Processes  "
         << " Burst time  "
         << " Waiting time  "
         << " Turn around time\n";

    // Calculate total waiting time and total turn
    // around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + waitingTime[i];
        total_tat = total_tat + turnAroundTime[i];
        cout << "   " << i + 1 << "\t\t" << burstTime[i] << "\t    "
             << waitingTime[i] << "\t\t  " << turnAroundTime[i] << endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

int main()
{
    // process id's
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];

    // Burst time of all processes
    int burst_time[] = {10, 5, 8};

    avgtime(processes, n, burst_time);
    return 0;
}