#include "main.h"

int Infix_Postfix_conversion(char *Infix_exp, char *Postfix_exp, Stack_t *stk)
{
    int i=0,j=0;
    while(Infix_exp[i] != '\0')
    {
        if(isdigit(Infix_exp[i]))
        {
            Postfix_exp[j++] = Infix_exp[i];
        }
        else if(Infix_exp[i] == '(')
        {
            push(stk,Infix_exp[i]);
        }
        else if(Infix_exp[i] == ')')
        {
            while(peek(stk) != '(' && stk -> top != -1)
            {
                Postfix_exp[j++] = peek(stk);
                pop(stk);
            }
            pop(stk);
        }
        else
        {
            while(stk->top != -1 && priority(peek(stk)) >= priority(Infix_exp[i]))
            {
                Postfix_exp[j++] = peek(stk);
                pop(stk);
            }
            push(stk,Infix_exp[i]);
        }
        i++;
    }
    while(stk ->top!= -1)
    {
        Postfix_exp[j++] = peek(stk);
        pop(stk);
    }
    Postfix_exp[j]='\0';
    return 1;
}