#include "main.h"

int Prefix_Eval(char *Prefix_exp, Stack_t *stk)
{
    int i = 0;
    int op1, op2, res;

    while (Prefix_exp[i] != '\0')
    {
        if (isdigit(Prefix_exp[i]))
        {
            push(stk, Prefix_exp[i] - '0');
        }
        else
        {
            op1 = peek(stk);
            pop(stk);

            op2 = peek(stk);
            pop(stk);

            switch (Prefix_exp[i])
            {
                case '+': res = op1 + op2;
                          break;

                case '-': res = op1 - op2;
                          break;

                case '*': res = op1 * op2;
                          break;

                case '/': res = op1 / op2;
                          break;

                default:  return 0; 
            }

            push(stk, res);
        }
        i++;
    }

    return peek(stk);
}