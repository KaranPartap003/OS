/* Producer Consumer Problem*/


# include <stdio.h>
# include <stdlib.h>

int mutex = 1 , full = 0 , empty = 4 , x = 0, i = 1;

void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\n producer produces the item %d" ,x);

    ++mutex;
}

void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\n consumer consumed the item %d" ,x);
    x--;
    ++mutex;
}

int main(){
    int n;
    printf("\n 1.Producer \n 2.Consumer \n 3.Exit");

    while (1)
    {
        printf("\n Enter your choice");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            if (mutex && (empty!=0))
            {
                producer();
            }
            else
            {
                printf("\n Buffer is full");
            }
            break;
        
        case 2:
            if (mutex && full!=0)
            {
                consumer();
            }
            else
            {
                printf("\n Buffer is empty");
            }
            
            break;
        
        case 3: exit(0);
            break;
        }
    }
    
    return 0;
}