#include <iostream>
#include <vector>
using namespace std;

void Find_WaitingTime(int n, int bt[] , int  wt[])
{
    wt[0] = 0;
    for (size_t i = 1; i < n; i++)
    {
        wt[i] = bt[i-1] + wt[i-1];
    }
    
}

void Find_TurnAroundTime(int n ,int bt[4] , int wt[4], int tat[4])
{
    for (size_t i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
    
}

void findAvgTime( int n ,int pid[4] , int bt[])
{
    int wt[n]; int tat[n] ;
    int totalWT = 0;
    int totalTAT = 0 ;

    Find_WaitingTime( n, bt , wt);
    Find_TurnAroundTime( n ,bt , wt , tat);

    cout << "pid    Burst time    Waiting time    Turnaround Time  " << endl;

    for (size_t i = 0; i < n; i++)
    {
        totalWT += wt[i];
        totalTAT += tat[i];
        cout << "  " << pid[i] << "\t\t" << bt[i] << "\t    " << wt[i] << "\t\t" << tat[i] << endl;
    }
    cout << "\nAverage Waiting Time = " << (float)totalWT / (float)4;
    cout << "\nAverage Turnaround Time = " << (float)totalTAT / (float)4;
}

int main()
{
    int n, processes[20], burst_time[20];

    cout << "Enter the number of processes: ";
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        cout << "enter burst time of " << i+1 << " process" << endl;
        cin>>burst_time[i]; 
        processes[i] = i+1;
    }
    findAvgTime(n, processes, burst_time);
    return 0;
}