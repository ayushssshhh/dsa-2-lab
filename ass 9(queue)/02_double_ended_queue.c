#include <stdio.h>
#define MAX 5
int DQ[MAX];
int L = -1;
int R = -1;
void insert_DQ_left(int ele)
{
    if (L == (R + 1) % MAX)
    {
        printf("Overflow");
        return;
    }
    if (L == -1)
    {
        L = R = 0;
    }
    else if (L == 0)
    {
        L = MAX - 1;
    }
    else
        L--;
    DQ[L] = ele;
}
void insert_DQ_right(int ele)
{
    if (L == (R + 1) % MAX)
    {
        printf("Overflow");
        return;
    }
    if (L == -1)
    {
        L = R = 0;
    }
    else if (R == (MAX - 1))
    {
        R = 0;
    }
    else
        R++;
    DQ[R] = ele;
}
void deletion_DQ_left()
{
    if (L == -1)
    {
        printf("Underflow");
        return;
    }
    if (L == R)
    {
        L = R = -1;
    }
    else if (L == MAX - 1)
    {
        L == 0;
    }
    else
        L++;
}
void deletion_DQ_right()
{
    if (L == -1)
    {
        printf("Underflow");
        return;
    }
    if (L == R)
    {
        L = R = -1;
    }
    else if (R == 0)
    {
        R = MAX - 1;
    }
    else
        R--;
}
void display_DQ()
{
    if (L < R)
    {
        for (int i = L; i < (MAX); i++)
        {
            printf("%d\t", DQ[i]);
        }
    }
    else
    {
        for (int i = L; i < (MAX); i++)
        {
            printf("%d\t", DQ[i]);
        }
        for (int i = 0; i <= R; i++)
        {
            printf("%d\t", DQ[i]);
        }
    }
}
int main()
{
    insert_DQ_left(1);
    insert_DQ_left(2);
    insert_DQ_right(3);
    insert_DQ_right(4);
    deletion_DQ_left();
    deletion_DQ_right();
    display_DQ();
    return 0;
}