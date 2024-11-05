/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:08:18 by plang             #+#    #+#             */
/*   Updated: 2024/11/05 14:57:41 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base*	generate(void)
{
	Base *p = nullptr;
	switch((rand() % 3))
	{
		case 0:
		{
			p = new A;
			break;
		}
		case 1:
		{
			p = new B;
			break;
		}
		case 2:
		{
			p = new C;
			break;
		}
	}
	return p;
}

void	identify(Base *p)
{
	try
	{
		A* Aa = dynamic_cast<A*>(p);
		if (Aa != nullptr)
			std::cout << "Type: A ptr\n";
	}
	catch(const std::bad_cast& e)
	{
	}
	try
	{
		B* Bb = dynamic_cast<B*>(p);
		if (Bb != nullptr)
			std::cout << "Type: B ptr\n";
	}
	catch(const std::bad_cast& e)
	{
	}
	try
	{
		C* Cc = dynamic_cast<C*>(p);
		if (Cc != nullptr)
			std::cout << "Type: C ptr\n";
	}
	catch(const std::bad_cast& e)
	{
	}
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type: A reference\n";
	}
	catch(const std::bad_cast& e)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type: B reference\n";
	}
	catch(const std::bad_cast& e)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type: C reference\n";
	}
	catch(const std::bad_cast& e)
	{
	}
}


int	main(void)
{
	srand((time(NULL)));
	Base *test1 = nullptr;
	test1 = generate();
	identify(test1);
	identify(*test1);

	Base *test2 = nullptr;
	test2 = generate();
	identify(test2);
	identify(*test2);

	Base *test3 = nullptr;
	test3 = generate();
	identify(test3);
	identify(*test3);

	delete test1;
	delete test2;
	delete test3;

	return 0;
}