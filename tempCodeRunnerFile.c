int checkp(char *str)
{
    int i = 0;
    struct stack si;
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
            if (isempty(si))
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
    if (isempty(si))
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