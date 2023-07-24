//#include "intstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define size 10

struct stack
{
    char arr[size];
    int sp;
};

int isempty(struct stack*s)
{
    if (s->sp == 0)
        return 1;
    else
        return 0;
}

void push(struct stack *s, char v)
{
    //printf("%d %d\n",s->sp,size);
    if (s->sp < size)
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

char pop(struct stack *s)
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

char peek(struct stack s)
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

int precedence(char ch)
{
    if (ch == '#')
        return 0;
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/' || ch == '%')
        return 3;
    if (ch == '^')
        return 4;
    else
    {
        printf("\n Invalid operator....");
        return 0;
    }
}
int isoperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return 1;
    else
        return 0;
}
int checki(char *str)
{
    int i = 0;
    struct stack s;
    s.sp=0;
    char ch;
    char x;
    while (str[i] != '\0')
    {
        ch = str[i];
        // printf("%d %c\n",isoperator(ch),ch);
        if (isoperator(ch) == 1)
        {
            // printf("Hi\n");
            if (isempty(&s))
            {
                return 0;
            }
            x = pop(&s);
        }
        else if (ch != '(' && ch != ')')
        {
            // printf("Hi\n");
            push(&s, ch);
        }
        i++;
    }
    if (isempty(&s))
        return 0;
    else
        return 1;
}
int checkp(char *str)
{
    int i = 0;
    struct stack si;
    si.sp=0;
    char ch;
    char x;
    while (str[i] != '\0')
    {
        ch = str[i];
        // printf("%d %c\n",isoperator(ch),ch);
        if (ch == '(')
        {
            // printf("Hi\n");
            push(&si, '(');
            // printf("\t%c\n",peek(si));
        }
        else if (ch == ')')
        {
            if (isempty(&si))
            {
                return 0;
            }
            // printf("He\n");
            // printf("\t%c\n",peek(si));
            x = pop(&si);
        }
        i++;
    }
    //x = pop(&si);
    if (isempty(&si))
    {
        // printf("Hr\n");
        return 1;
    }
    else
    {
        // printf("\t%c\n",pop(&si));
        // printf("\t%c\n",peek(si));
        return 0;
    }
}
char *convert(char *in)
{
    char *po = (char *)malloc(100 * sizeof(char));
    int i = 0, j = 0;
    char x;
    struct stack s;
    s.sp=0;
    if (!checki(in) || !checkp(in))
    {
        printf("Expression is not correct\n");
        return (NULL);
    }
    while (in[i] != '\0')
    {
        //printf("He\n");
        if (isalnum(in[i]))
        {
            //printf("Hi 1\n");
            po[j] = in[i];
            j++;
        }
        else if (in[i] == '(')
        {
            //printf("Hi 2\n");
            push(&s, in[i]);
        }

        else if (in[i] == ')')
        {
            //printf("Hi 3\n");
            while (peek(s) != '(')
            {
                po[j] = pop(&s);
                j++;
            }
            x = pop(&s);
        }
        else if (isoperator(in[i]))
        {
            //printf("Hi 4\n");
            while (!isempty(&s) && peek(s) != '(' && precedence(peek(s)) >= precedence(in[i]))
            {
                //printf("Hi 5\n");
                po[j] = pop(&s);
                j++;
            }
            push(&s, in[i]);
        }
        i++;
    }
    while (!isempty(&s))
    {
        //printf("Hi 6\n");
        po[j] = pop(&s);
        j++;
    }
    po[j] = '\0';
    //printf("%s\n", po);
    return po;
}
int main()
{
    char str[50] = "e*(a+b)/(c+d)";
    char *po = convert(str);
    //printf("%d %d\n",checkp(str),checki(str));
    printf("%s\n", po);
    return 0;
}
/*void main()
{
    struct stack s;
    s.sp=0;
    printf("%d\n",s.sp);
}*/