/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:49:09 by martalop          #+#    #+#             */
/*   Updated: 2025/04/27 20:06:41 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation", 145, 137)
{
	std::cout << "Shrubbery Creation Form constructor called" << std::endl;
	setSignStatus(false);
	_target = "Random target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation", 145, 137)
{
	std::cout << "Shrubbery Creation Form constructor called" << std::endl;
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& var): AForm(var)
{
	std::cout << "Shrubbery Creation Form copy constructor called" << std::endl;
	*this = var;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form destructor called" << std::endl;
}

void	ShrubberyCreationForm::setTarget(const std::string target)
{
	_target = target;
}

std::string	ShrubberyCreationForm::getTarget(void)
{
	return (_target);
}

void	drawTrees(std::ofstream &file)
{
	file << std::endl;
	file << "                  %%%,%%%%%%%          \n"
		<< "                   ,'%% \\-*%%%%%%%    \n"
		<< "             ;%%%%%*%   _%%%%\"        \n"
	   	<< "              ,%%%       \(_.*%%%%.    \n"
	   	<< "              % *%%, ,%%%%*\(    '     \n"
	   	<< "            %^     ,*%%% )|,%%*%,_     \n"
	   	<< "                 *%    \\ / #).-\"*%%* \n"
	   	<< "                     _.) ,/ *%,        \n"
	   	<< "             _________/)#(_____________\n";
	file << std::endl << std::endl;
	file << "               '.,\n" 
		<< "                 'b      *\n" 
		<< "                  '$    #.\n" 
		<< "                   $:   #:\n" 
		<< "                   *#  @):\n" 
		<< "                   :@,@):   ,.**:'\n" 
		<< "         ,         :@@*: ..**'\n" 
		<< "           '#o.    .:(@'.@*\"'\n" 
		<< "              'bq,..:,@@*'   ,*\n" 
		<< "              ,p$q8,:@)'  .p*'\n" 
		<< "             '    '@@Pp@@*'\n" 
		<< "                   Y7'.'\n" 
		<< "                  :@):.\n" 
		<< "                 .:@:'.\n" 
		<< "               .::(@:.\n";
	file << std::endl;

}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::ofstream	file;
	std::string		fileName;

	if (!getSignStatus())
		throw FormNotSignedException(); 
	if (executor.getGrade() > this->getExecGrade()) 
		throw GradeTooLowException();
	fileName = _target + "_shrubbery";
	file.open(fileName.c_str());
	if (!file.is_open())
		throw (std::runtime_error(std::string("Failed to open file: ") + _target + "_shrubbery"));
	drawTrees(file);
	file.close();
}	

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& var)
{
	std::cout << "Shrubbery Creation Form copy assignment operator" << std::endl;
	if (this != &var)
	{
		setSignStatus(var.getSignStatus());
		_target = var._target;
	}
	return (*this);
}

