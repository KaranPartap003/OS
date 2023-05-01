# include <iostream>
using namespace std;
#define max 30

int main(){
    int n, t , p[max] , wt[max] , bt[max] , tat[max];
    float awt = 0;
    float atat = 0;

    cout << "enter number of processes "<<endl;
    cin>>n;

    cout << "Enter process id" << endl;
    for (size_t i = 0; i < n; i++)
    {
        cin>>p[i];
    }
    cout << "Enter process  burst time" << endl;
    for (size_t i = 0; i < n; i++)
    {
        cin>>bt[i];
    }
    
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; i < n-i-1 ; j++)
        {
            if (bt[i] > bt[i+1])
            {
                t = bt[i];
                bt[i] = bt[i+1];
                bt[i+1] = t;

                t = p[i];
                p[i] = p[i+1];
                p[i+1] = t;
            }
        }
        
    }

    cout <<"Pid    BT    WT    TAT"<<endl;

    for (size_t i = 1; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (size_t j = 0; j < i; i++)
        {
            wt[i] = wt[i] + bt[j];
        }
        tat[i] = wt[i]+bt[i];
        awt += wt[i];
        atat += tat[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << p[i] << "    " << bt[i] << "    " << wt[i] << "    " << tat[i];
    }
    
    awt /= n;
    atat /= n;
    cout << "average waiting time " << awt << endl;
    cout << "average turnaround time " << atat << endl;
    
    return 0;
}