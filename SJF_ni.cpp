#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process
{
public:
    int pid;
    int at; // Arrival Time
    int bt; // Burst Time
};

bool compareProcesses(const Process &p1, const Process &p2)
{
    return p1.bt < p2.bt;
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; ++i)
    {
        cout << "Enter details for process " << i + 1 << ":" << endl;
        cout << "Process ID: ";
        cin >> processes[i].pid;
        cout << "Arrival Time: ";
        cin >> processes[i].at;
        cout << "Burst Time: ";
        cin >> processes[i].bt;
    }

    // Sort processes by burst time
    sort(processes.begin(), processes.end(), compareProcesses);

    int ct = 0;  // Current Time
    int wt = 0;  // Waiting Time
    int tat = 0; // Turnaround Time

    for (Process process : processes)
    {
        if (process.at > ct)
        {
            ct = process.at;
        }
        ct += process.bt;
        tat += ct - process.at;
        wt += tat - process.bt;
    }

    cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (Process process : processes)
    {
        cout << process.pid << "\t\t" << process.at << "\t\t"
             << process.bt << "\t\t" << wt << "\t\t" << tat << endl;
    }

    cout << "Average Waiting Time: " << (float)wt / n << endl;
    cout << "Average Turnaround Time: " << (float)tat / n << endl;

    return 0;
}