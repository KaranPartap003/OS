# include <iostream>
using namespace std;

void FindWaitingTime(int processes[] , int n , int bt[] , int wt[], int qt)
{
    int rem_bt[n]; //to store remaining burst time

    //initialising rem_bt with bt
    for (size_t i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }

    int t = 0; // current time
    //keep traversing untill all are done
    while (1)
    {
        bool completed = true;
        //traversing all processes
        for (size_t i = 0; i < n; i++)
        {
            // processing only if some burst time is left
            if (rem_bt[i] > 0)
            {
                completed = false;//updating flag

                if (rem_bt[i] > qt)
                {
                    t += qt;

                    rem_bt[i] -= qt;
                }
                else
                {
                    t += rem_bt[i];

                    //waiting time is current time - burst time
                    wt[i] = t - bt[i];

                    rem_bt[i] = 0;
                }
            }
        }
        if (completed)
        {
            break;
        }
    }
}

void FindTurnaroundTime(int processes[] ,int n , int bt[] , int wt[] , int tat[])
{
    for (size_t i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void findavgtime(int processes[] , int n , int bt[] , int qt)
{
    int wt[n] , tat[n];
    float total_wt , total_tat;

    FindWaitingTime(processes , n ,bt ,wt ,qt);
    FindTurnaroundTime(processes , n ,bt , wt , tat);
     cout << "PN\t "<< " \tBT "
        << "  WT " << " \tTAT\n";
 
    // Calculate total waiting time and total turn
    // around time
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}

int main()
{
    int processes[] = { 1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
 
    // Burst time of all processes
    int burst_time[] = {10, 5, 8};
 
    // Time quantum
    int quantum = 2;
    findavgtime(processes, n, burst_time, quantum);
    return 0;
}