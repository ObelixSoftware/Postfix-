#include <cmath>
#include <string>
#include "Interpreter.h"
#include "MathUtil.h"

double Interpreter::compute(const std::string &expression)
{
	int i = 0;
	double v1, v2;
	v1 = v2 = 0.0;
	double* ret = nullptr;

	std::string tok = "";

	while (i < expression.length())
	{
		// Skip white space
		while (isspace(expression[i]))
		{
			i++;
		}
		// Check for digits and .
		if (isdigit(expression[i]) || table.isValidVariable(expression[i]) || expression[i] == '.' || expression[i] == '-')
		{
			while (isdigit(expression[i]) || table.isValidVariable(expression[i]) || expression[i] == '.' || expression[i] == '-')
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
				checkRequireOperants(2);
				v1 = getValue(myStack.pop());
				v2 = getValue(myStack.pop());
				ret = new double(v1 + v2);
			}
			if (expression[i] == '-')
			{
				checkRequireOperants(2);
				v1 = getValue(myStack.pop());
				v2 = getValue(myStack.pop());
				ret = new double (v2 - v1);
			}
			if (expression[i] == '*')
			{
				checkRequireOperants(2);
				v1 = getValue(myStack.pop());
				v2 = getValue(myStack.pop());
				ret = new double(v1 * v2);
			}
			if (expression[i] == '/')
			{
				checkRequireOperants(2);
				v1 = getValue(myStack.pop());
				v2 = getValue(myStack.pop());
				checkDivByZero(v2);
				ret = new double(v2 / v1);
			}
			if (expression[i] == '!')
			{
				checkRequireOperants(1);
				v1 = getValue(myStack.pop());
				ret = new double(MathUtil::factorial(v1));
			}
			if (expression[i] == '^')
			{
				checkRequireOperants(2);
				v1 = getValue(myStack.pop());
				v2 = getValue(myStack.pop());
				ret = new double(pow(v2, v1));
			}
			if (expression[i] == 'p')
			{
				checkRequireOperants(1);
				char op1 = myStack.pop();
				if (table.isValidVariable(op1)) {
					std::cout << op1 << " = " << table.getValue(op1) << std::endl << std::endl;
				}
				else {
					throw std::runtime_error("Invalid variable reference: " + std::string(1, op1));
				}
			}
			if (expression[i] == '=')
			{
				checkRequireOperants(2);
				char op1 = myStack.pop();
				char op2 = myStack.pop();

				if (table.isValidVariable(op1) && table.isValidVariable(op2)) {
					table.setValue(op1, table.getValue(op2));			
				}
				else if (table.isValidVariable(op1)) {
					if (isdigit(op2)) {
						table.setValue(op1, getValue(op2));
					}
				}
				if (table.isValidVariable(op2)) {
					if (isdigit(op1)) {
						table.setValue(op2, getValue(op1));
					}
				}
				else {
					throw std::runtime_error("Invalid variable reference: " + std::string(1, op2));
				}
			}
			i++;
			if (ret != nullptr) {
				myStack.push(*ret);
			}
		}
		else
		{
			throw std::runtime_error("Invaild expression");
			break;
		}
	}

 	// Return math expression answer
	return myStack.pop();
}

/*
  Check if token is a operator
*/ 
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

/*
  Get the value from the token being number of value 
  of a veriable from symbol table
*/
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

/*
  Throw exception if devide by zero
*/
void Interpreter::checkDivByZero(double value) {
	if (value == 0) {
		throw std::runtime_error("Division by zero error");
	}
}

/*
  Throw exception if required operants provide not provided
*/
void Interpreter::checkRequireOperants(int requireOps) {
	if (myStack.capacity() < requireOps) {
		throw std::runtime_error("Expression require " + std::to_string(requireOps) + "x operants"); 
	}
}
