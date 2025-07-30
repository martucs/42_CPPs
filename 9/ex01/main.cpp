#include "RPN.hpp"

int	main(int argc, char** args)
{
	RPN	calculator;

	if (argc != 2)
	{
		std::cout << "Usage: ./RPN \"inverted Polish mathematical expression\"" << std::endl;
		return (1);
	}
	if (calculator.parseLine(args[1]) == -1)
	{
		std::cerr << "Error: wrong format in line\n";
		return (1);
	}
	if (calculator.calculateLine(args[1]) == -1)
		return (1);
	return (0);
}
