#include <cmath>
#include "Interpreter.h"
#include "MathUtil.h"

double *Interpreter::compute(const std::string &expression)
{
	int i = 0;
	double v1, v2, ret;
	v1 = ret = v2 = 0.0;

	std::string tok = "";
	bool valid = true;

	while (i < expression.length())
	{
		// Skip white space
		while (isspace(expression[i]))
		{
			i++;
		}
		// Check for digits and .
		if (isdigit(expression[i]) || table.isVariable(expression[i]) || expression[i] == '.' || expression[i] == '-')
		{
			while (isdigit(expression[i]) || table.isVariable(expression[i]) || expression[i] == '.' || expression[i] == '-')
			{
				tok += expression[i];
				i++;
			}
			myStack.push(tok[0]);
			tok = "";
		}
		// Check for operator
		else if (IsOperator(expression[i]))
		{
			if (expression[i] == '+')
			{
				v1 = getValue(myStack.pop());
				v2 = getValue(myStack.pop());
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
				ret = MathUtil::factorial(v1);
			}
			if (expression[i] == '^')
			{
				v1 = myStack.pop();
				v2 = myStack.pop();
				ret = pow(v2, v1);
			}
			if (expression[i] == '=')
			{
			}
			i++;
			myStack.push(ret);
		}
		else
		{
			std::cout << "Invaild expression" << std::endl
					  << std::endl;
			valid = false;
			break;
		}
	}

	return valid == true ? new double(myStack.pop()) : nullptr;
}

bool Interpreter::IsOperator(char c)
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
	case '=':
		return true;
	default:
		return false;
	}
}

double Interpreter::getValue(char tok)
{
	if (table.isVariable(tok))
	{
		if (table.isValid(tok))
		{
			return table.getValue(tok);
		}
		else
		{
			return false;
		}
	}
	else
	{
		char *pChar = &tok;
		return atof(pChar);
	}

	return 0;
}