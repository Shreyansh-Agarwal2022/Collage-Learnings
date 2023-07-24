#include <stdio.h>
#include <stdlib.h>
#define size 10
struct intstack
{
    int arr[size];
    int sp;
};

void ipush(struct intstack *s, int v)
{
    if (s->sp)
    {
        s->arr[s->sp] = v;
        s->sp++;
    }
    else
    {
        printf("\nStack Overflow...");
        exit(0);
    }
}
int ipop(struct intstack *s)
{
    if (s->sp == 0)
    {
        printf("\n Stack Underflow...");
        exit(0);
    }
    else
    {
        --s->sp;
        return s->arr[s->sp];
    }
}
int ipeek(struct intstack s)
{
    if (s.sp == 0)
    {
        printf("\n Stack Underflow...");
        exit(0);
    }
    else
    {
        return s.arr[s.sp - 1];
    }
}