#include "main.h"

int Postfix_Eval(char *Postfix_exp, Stack_t *stk)
{
    int i = 0;
    int op1, op2, res;

    while (Postfix_exp[i] != '\0')
    {
        if (isdigit(Postfix_exp[i]))
        {
            push(stk, Postfix_exp[i] - '0');
        }
        else
        {
            op2 = peek(stk);
            pop(stk);

            op1 = peek(stk);
            pop(stk);

            switch (Postfix_exp[i])
            {
                case '+': res = op1 + op2;
                          break;

                case '-': res = op1 - op2;
                          break;

                case '*': res = op1 * op2;
                          break;

                case '/': res = op1 / op2;
                          break;

                case '%': res = op1 % op2;
                          break;

                default:  return 0; 
            }

            push(stk, res);
        }
        i++;
    }

    return peek(stk);
}