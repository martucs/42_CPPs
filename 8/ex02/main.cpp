/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:55:39 by martalop          #+#    #+#             */
/*   Updated: 2025/05/19 21:08:16 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

/*int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout  << std::endl;
	std::cout  << std::endl;

	std::list<int> listt;
	listt.push_back(5);
	listt.push_back(17);
	std::cout << listt.back() << std::endl;
	listt.pop_back();
	std::cout << listt.size() << std::endl;
	listt.push_back(3);
	listt.push_back(5);
	listt.push_back(737);
	//[...]
	listt.push_back(0);
	std::list<int>::iterator it2 = listt.begin();
	std::list<int>::iterator ite2 = listt.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
//	std::stack<int> ss(listt);
	std::cout  << std::endl;
	return 0;
}*/

int	main()
{
	std::stack<int>	realStack;
	
	std::deque<int>	Deque;
	Deque.assign(4, 42);

	std::deque<int>::iterator it = Deque.begin();
	
	std::cout << "Deque:" << std::endl;
	std::cout << *it << std::endl;
	std::cout << std::endl;

	realStack.push(12);
	std::cout << "real stack:" << std::endl;
	std::cout << realStack.top() << std::endl;
	std::cout << std::endl;

	MutantStack<int>	mstack;
	
	mstack.push(10);
	mstack.push(20);
	mstack.push(30);
	std::cout << "Mutant stack:" << std::endl;
	MutantStack<int>::iterator	myStackItB = mstack.begin();
	MutantStack<int>::iterator	myStackItE = mstack.end();
//	MutantStack<int>::const_iterator		constIterator = mstack.begin();

	while (myStackItB != myStackItE)
	{
		std::cout << *myStackItB << std::endl;
		myStackItB++;
	}
	myStackItB -= 1;
	*myStackItB += 1;
	std::cout << "changed last num to: " << *myStackItB << std::endl;
//	*constIterator += 1; //trying to change first num to '11', will not compile
	return (0);
}
