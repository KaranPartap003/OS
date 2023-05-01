# include <iostream>
#include <algorithm>
using namespace std;
# define max 30

struct process
{
    int at;
    int bt;
};

bool comparator(process a, process b)
{
    return (a.at < b.at);
}

void FindWT(process proc[] , int n , int wt[])
{
    wt[0] = 0;

    for (size_t i = 1; i < n; i++)
    {
        wt[i] = proc[i-1].bt + wt[i-1];
    }
}

void FindTAT(process proc[] , int n , int wt[] , int tat[])
{
    for (size_t i = 0; i < n; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }
}

void FindAvgtime(process proc[] , int n)
{
    int wt[n] , tat[n];
    float awt=0 , atat = 0;

    FindWT(proc , n , wt);
    FindTAT(proc , n , wt , tat);


    for (size_t i = 0; i < n; i++)
    {
        awt += wt[i];
        atat += tat[i];

        cout << proc[i].at << "\t\t"<< proc[i].bt << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    awt /= n;
    atat /= n;
    cout << "avg wt " << awt << endl;
    cout << "avg tat " << atat << endl;
}

int main(){
    process proc[] = {{0,5},{3,9},{6,6}};
    sort(proc , proc+3 , comparator);
    FindAvgtime(proc , 3);
    return 0;
}