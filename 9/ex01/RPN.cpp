#include "RPN.hpp"

RPN::RPN()
{
	_operations = "+-*/";
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
		_operations = var._operations;
		_stack = var._stack;
	}
	return (*this);
}

bool	RPN::isOperation(char c)
{
	for (size_t i = 0; i < _operations.size(); i++)
	{
		if (c == _operations[i])
			return (true);
	}
	return (false);
}

int	RPN::parseLine(std::string line)
{
	size_t	i = 0;

	for (i = 0; i < line.size(); i++)
	{
		if (!isdigit(line[i]) && line[i] != ' ' && !isOperation(line[i]))
			return (-1);
		if (isOperation(line[i]) && line[i - 1] != ' ')
			return (-1);
		if (isdigit(line[i]) && line[i + 1] && isdigit(line[i + 1])) // no acepto numeros de 2 digitos
			return (-1);
	}
	for (i = 0; i < line.size(); i++)
	{
		if (isdigit(line[i]))
			break;
	}
	if (i == line.size() || (!strchr(line.c_str(), '+') && !strchr(line.c_str(), '-') && !strchr(line.c_str(), '*') && !strchr(line.c_str(), '/')))
		return (-1);
	return (0);
}


int	RPN::calculateLine(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isOperation(str[i]) && str[i] != ' ')
			_stack.push(atoi(&str[i]));
		if (isOperation(str[i]) && _stack.size() < 2)
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
				second_elem = _stack.top();
				_stack.pop();
				first_elem = _stack.top();
				_stack.pop();
				res = static_cast<float>(first_elem) + static_cast<float>(second_elem);
				_stack.push(res);
			}
			if (str[i] == '-')
			{
				second_elem = _stack.top();
				_stack.pop();
				first_elem = _stack.top();
				_stack.pop();
				res = static_cast<float>(first_elem) - static_cast<float>(second_elem);
				_stack.push(res);
			}
			if (str[i] == '*')
			{
				second_elem = _stack.top();
				_stack.pop();
				first_elem = _stack.top();
				_stack.pop();
				res = static_cast<float>(first_elem) * static_cast<float>(second_elem);
				_stack.push(res);
			}
			if (str[i] == '/')
			{
				second_elem = _stack.top();
				if (second_elem == 0)
				{
					std::cout << "Error: cannot divide by 0" << std::endl;
					return (-1);
				}
				_stack.pop();
				first_elem = _stack.top();
				_stack.pop();
				res = static_cast<float>(first_elem) / static_cast<float>(second_elem);
				_stack.push(res);
			}
		}
	}
	if (_stack.size() > 1 )
	{
		std::cout << "Error: too many elements / missing operation" << std::endl;
		return (-1);
	}
	std::cout << _stack.top() << std::endl;
	return (0);
}
