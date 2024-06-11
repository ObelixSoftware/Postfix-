#include "Interpreter.h"
#include<cmath>

double Interpreter::compute(const std::string& expression)
{
	int i = 0;
	double v1, v2, ret;
	v1 = ret = v2 = 0.0;

	std::string tok = "";

	while (i < expression.length())
	{
		// Skip white space
		while (isspace(expression[i]))
		{
			i++;
		}
		// Check for digits and .
		if (isdigit(expression[i]) || expression[i] == '.' || expression[i] == '-')
		{
			while (isdigit(expression[i]) || expression[i] == '.' || expression[i] == '-')
			{
				tok += expression[i];
				i++;
			}
			// Push on stack number.
			myStack.push(atof(tok.c_str()));
			tok = "";
		}
		// Check for operator
		else if (IsOp(expression[i]))
		{
			if (expression[i] == '+')
			{
				v1 = myStack.pop();
				v2 = myStack.pop();
				ret = (v1 + v2);
			}
			if (expression[i] == '-')
			{
				v1 = myStack.pop();
				v2 = myStack.pop();
				ret = v2 - v1;
			}
			if (expression[i] == '*')
			{
				v1 = myStack.pop();
				v2 = myStack.pop();
				ret = (v1 * v2);
			}
			if (expression[i] == '/')
			{
				v1 = myStack.pop();
				v2 = myStack.pop();
				ret = (v2 / v1);
			}
			if (expression[i] == '!')
			{
				v1 = myStack.pop();
				ret = factorial(v1);
			}
			if (expression[i] == '^')
			{
				v1 = myStack.pop();
				v2 = myStack.pop();
				ret = pow(v2, v1);
			}
			i++;
			myStack.push(ret);
		}
		else
		{
			std::cout << "Invaild expression" << std::endl;
			break;
		}
	}
	return myStack.pop();
}

bool Interpreter::IsOp(char c)
{
	// Check for operators.
	switch (c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '!':
	case '^':
		return true;
	default:
		return false;
	}
}

long Interpreter::factorial(const int n)
{
    long f = 1;
    for (int i=1; i<=n; ++i)
        f *= i;
    return f;
}