#include "RPN.hpp"

RPN::RPN()
{
	_operations[0] = '+';
	_operations[1] = '-';
	_operations[2] = '*';
	_operations[3] = '/';
	_numberOfValues = 0;
}

RPN::RPN(const RPN& var)
{
	*this = var;
}

RPN::~RPN()
{
}

RPN&	RPN::operator=(const RPN& var)
{
	if (this != &var)
	{
		_numberOfValues = var._numberOfValues;
		_stack = var._stack;
	}
	return (*this);
}

bool	RPN::isOperation(char c)
{
	for (int i = 0; i < 4; i++)
	{
		if (c == _operations[i])
			return (true);
	}
	return (false);
}

int	RPN::parseLine(std::string line)
{
	for (size_t i = 0; i < line.size(); i++)
	{
		if (!isdigit(line[i]) && line[i] != ' ' && !isOperation(line[i]))
			return (-1);
		if (isOperation(line[i]) && line[i - 1] != ' ')
			return (-1);
	}
	return (0);
}


int	RPN::calculateLine(std::string str)
{
	for (size_t i = 0; i < str.size() && _numberOfValues < 10; i++)
	{
		if (i != 0 && !isOperation(str[i]) && str[i] != ' ' && !str[i + 1])
		{
			std::cout << "i = " << i << std::endl;
			std::cout << "Error: no operation specified" << std::endl;
			return (-1);
		}
		else if (!isOperation(str[i]) && str[i] != ' ')
		{
			std::cout << "pushing " << atoi(&str[i]) << " into stack\n";
			_stack.push(atoi(&str[i]));
			_numberOfValues++;
		}
		else if (isOperation(str[i]) && _stack.size() < 2)
		{
			std::cout << "Error: not enough elements to make operation" << std::endl;
			return (-1);
		}
		else if (isOperation(str[i]))
		{
			int	first_elem;
			int	second_elem;
			float	res;

			if (str[i] == '+')
			{
				std::cout << "\nSUM\n";
				second_elem = _stack.top();
				_stack.pop();
				first_elem = _stack.top();
				_stack.pop();
				res = static_cast<float>(first_elem) + static_cast<float>(second_elem);
				std::cout << "first elem = " << first_elem << std::endl;
				std::cout << "second elem = " << second_elem << std::endl;
				std::cout << "res = " << res << std::endl;
				_stack.push(res);
				std::cout << "pushing " << _stack.top() << " into stack\n";
				std::cout << "finished SUM\n\n";
			}
			if (str[i] == '-')
			{
				std::cout << "\nSUBSTRACTION\n";
				second_elem = _stack.top();
				_stack.pop();
				first_elem = _stack.top();
				_stack.pop();
				res = static_cast<float>(first_elem) - static_cast<float>(second_elem);
				std::cout << "first elem = " << first_elem << std::endl;
				std::cout << "second elem = " << second_elem << std::endl;
				std::cout << "res = " << res << std::endl;
				_stack.push(res);
				std::cout << "pushing " << _stack.top() << " into stack\n";
				std::cout << "finished SUM\n\n";
			}
			if (str[i] == '*')
			{
				std::cout << "\nMULT\n";
				second_elem = _stack.top();
				_stack.pop();
				first_elem = _stack.top();
				_stack.pop();
				res = static_cast<float>(first_elem) * static_cast<float>(second_elem);
				std::cout << "first elem = " << first_elem << std::endl;
				std::cout << "second elem = " << second_elem << std::endl;
				std::cout << "res = " << res << std::endl;
				_stack.push(res);
				std::cout << "pushing " << _stack.top() << " into stack\n";
				std::cout << "finished SUM\n\n";
			}
			if (str[i] == '/')
			{
				std::cout << "\nDIV\n";
				second_elem = _stack.top();
				_stack.pop();
				first_elem = _stack.top();
				_stack.pop();
				res = static_cast<float>(first_elem) / static_cast<float>(second_elem);
				std::cout << "first elem = " << first_elem << std::endl;
				std::cout << "second elem = " << second_elem << std::endl;
				std::cout << "res = " << res << std::endl;
				_stack.push(res);
				std::cout << "pushing " << _stack.top() << " into stack\n";
				std::cout << "finished SUM\n\n";
			}
		}
	}
	if (_numberOfValues > 10)
		std::cout << "Error: too many values received" << std::endl;

	std::cout << "Final res = " << _stack.top() << std::endl;
//	std::cout << "\ntotal num of values received = " << _numberOfValues << std::endl;
	return (0);
}
