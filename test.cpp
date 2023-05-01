# include <iostream>
#include <algorithm>
using namespace std;

struct process
{
    int pno;
    int bt;
};

bool comparison(process a ,process b)
{
    return (a.bt < b.bt);
}

void Find_WaitingTime(process proc[] , int n , int wt[])
{
    wt[0] = 0;
    for (size_t i = 1; i < n; i++)
    {
        wt[i] = proc[i-1].bt + wt[i-1];
    }
}

void Find_TurnAroundTime(process proc[] , int n , int wt[] , int tat[])
{
    for (size_t i = 0; i < n; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }
    
}

void FindAverageTime(process proc[] , int n)
{
    int wt[n] , tat[n];
    float AverageWaitingTime = 0;
    float AverageTurnaroundTime = 0;

    Find_WaitingTime(proc , n , wt);
    Find_TurnAroundTime(proc , n , wt , tat);
    cout<<"P no\t\t"<<"BT\t\t"<<"WT\t\t"<<"TAT\t\t"<<endl;
    for (size_t i = 0; i < n; i++)
    {
        AverageWaitingTime += wt[i];
        AverageTurnaroundTime += tat[i];

        cout << proc[i].pno << "\t\t"<< proc[i].bt << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    AverageTurnaroundTime /= n;
    AverageWaitingTime /= n;

    cout << "\n average waiting time is " << (float)AverageWaitingTime << endl;
    cout << "average turnaround time is " << (float)AverageTurnaroundTime << endl;
}

void SJFScheduling(process proc[] , int n)
{
    sort(proc , proc+n , comparison);

    cout<<"Order in which Processes got executed "<<endl;

    for (size_t i = 0; i < n; i++)
    {
        cout << proc[i].pno << "\t";
    }

    FindAverageTime(proc , n);
    
}

int main(){
    
    process proc[] = { { 1, 10}, { 2, 5 }, { 3, 8} };  
    int n = sizeof proc / sizeof proc[0];
    SJFScheduling(proc, 3);
    return 0;
}