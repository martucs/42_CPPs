#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>

class	RPN
{
	public:
		RPN();		
		RPN(const RPN&);
		~RPN();

		RPN	&operator=(const RPN&);
		
		bool	isOperation(char c);
		int	parseLine(std::string line);
		int	calculateLine(std::string line);	

	private:
		char		_operations[4];
		int		_numberOfValues;
		std::stack<float>	_stack;
};

#endif
