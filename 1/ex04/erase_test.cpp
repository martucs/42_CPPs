#include <string>
#include <iostream>


int	main(void)
{
	std::string	line;

	line = "hola que tal";
	std::cout << "line = " << line << std::endl;
	line.erase(5, 3);
	std::cout << "line = " << line << std::endl;
	return (0);
}
