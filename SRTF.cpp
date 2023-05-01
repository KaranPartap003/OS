# include <iostream>
using namespace std;

struct process
{
    int pid;
    int bt;
    int art;
};

void findwaitingtime(process proc[] , int n , int wt[])
{
    int rt[n];

    for (size_t i = 0; i < n; i++)
    {
        rt[i] = wt[i];
    }
    
    int complete = 0, t=0,finish_time,shortest=0,minm = INT_MAX;
    bool check = false;
    while (complete != n)
    {
        // Find process with minimum remaining time among the processes that arrives 
        // till the current time` 
        for (size_t i = 0; i < n; i++)
        {
            if (proc[i].art <= t && rt[j] < minm && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false)
        {
            t++;
            continue;
        }
        //reduce shortest remaining time job by 1
        rt[shortest]--;
        // update minimum
        minm = rt[shortest];
        if (minm == 0)
        {
            minm = INT_MAX;
        }

        //If process is executed 
        if (rt[shortest] == 0)
        {
            complete++;
            check = false;

            //calculate finish time
            finish_time = t+1;

            //calculate waiting time
            wt[shortest] = finish_time - proc[shortest].art - proc[shortest].bt;
        }
        //Increment time
        t++;
    }
    
}

int main(){
    
    return 0;
}