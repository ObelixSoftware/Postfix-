#include <cmath>
#include "Interpreter.h"
#include "MathUtil.h"

double *Interpreter::compute(const std::string &expression)
{
	int i = 0;
	double v1, v2, ret;
	v1 = ret = v2 = 0.0;

	std::string tok = "";
	bool isValidMathExpression = true;

	while (i < expression.length())
	{
		// Skip white space
		while (isspace(expression[i]))
		{
			i++;
		}
		// Check for digits and .
		if (isdigit(expression[i]) || isVariable(expression[i]) || expression[i] == '.' || expression[i] == '-')
		{
			while (isdigit(expression[i]) || isVariable(expression[i]) || expression[i] == '.' || expression[i] == '-')
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
				v1 = getValue(myStack.pop());
				v2 = getValue(myStack.pop());
				ret = v2 - v1;
			}
			if (expression[i] == '*')
			{
				v1 = getValue(myStack.pop());
				v2 = getValue(myStack.pop());
				ret = (v1 * v2);
			}
			if (expression[i] == '/')
			{
				v1 = getValue(myStack.pop());
				v2 = myStack.pop();
				ret = (v2 / v1);
			}
			if (expression[i] == '!')
			{
				v1 = getValue(myStack.pop());
				ret = MathUtil::factorial(v1);
			}
			if (expression[i] == '^')
			{
				v1 = getValue(myStack.pop());
				v2 = getValue(myStack.pop());
				ret = pow(v2, v1);
			}
			if (expression[i] == 'p')
			{
				char op1 = myStack.pop();
				if (table.isVariable(op1) && table.isValid(op1)) {
					std::cout << op1 << " = " << table.getValue(op1) << std::endl << std::endl;
				}
				else {
					std::cout << "Invalid variable reference: " << op1 << std::endl << std::endl;
				}
				isValidMathExpression = false;
			}
			if (expression[i] == '=')
			{
				char op1 = myStack.pop();
				char op2 = myStack.pop();

				if ((table.isVariable(op1) && table.isValid(op1)) && 
						(table.isVariable(op1) && table.isValid(op1))) {
					table.setValue(op1, table.getValue(op2));			
				}
				else if (table.isVariable(op1) && table.isValid(op1)) {
					if (isdigit(op2)) {
						table.setValue(op1, getValue(op2));
					}
				}
				if (table.isVariable(op2) && table.isValid(op2)) {
					if (isdigit(op1)) {
						table.setValue(op2, getValue(op1));
					}
				}
				else {
					std::cout << "Invalid variable reference: " << op2 << std::endl << std::endl;
				}
				isValidMathExpression = false;
			}
			i++;
			myStack.push(ret);
		}
		else
		{
			std::cout << "Invaild expression" << std::endl
					  << std::endl;
			isValidMathExpression = false;
			break;
		}
	}

	return isValidMathExpression == true ? new double(myStack.pop()) : nullptr;
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
	case 'p':
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

bool Interpreter::isVariable(char tok)  {
	return table.isVariable(tok) && table.isValid(tok);
}
