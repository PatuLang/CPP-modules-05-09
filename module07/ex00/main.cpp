/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:15:46 by plang             #+#    #+#             */
/*   Updated: 2024/11/12 17:14:27 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	int		a = 0;
	int		b = 9;
	double	c = 1.9;
	double	d = 99.9;

	std::string one = "z_hello";
	std::string two = "a_hello";
	char		three = 'Z';
	char 		four = 'A';

	std::cout << "\noriginal ------------->\n\n";

	// swap function template in use
	
	std::cout << a << " " << b << "\n";
	std::cout << c << " " << d << "\n";
	std::cout << one << " " << two << "\n";
	std::cout << three << " " << four << "\n";

	std::cout << "\nswaping ------------->\n\n";

	::swap<int>(a, b);
	::swap<double>(c, d);
	::swap<std::string>(one, two);
	::swap<char>(three, four);

	std::cout << a << " " << b << "\n";
	std::cout << c << " " << d << "\n";
	std::cout << one << " " << two << "\n";
	std::cout << three << " " << four << "\n";

	// min function template in use

	std::cout << "\nreturning min ------->\n\n";

	std::cout << ::min<int>(a, b) << "\n";
	std::cout << ::min<double>(c, d) << "\n";
	std::cout << ::min<std::string>(one, two) << "\n";
	std::cout << ::min<char>(three, four) << "\n";

	// max function template in use

	std::cout << "\nreturning max ------->\n\n";

	std::cout << ::max<int>(a, b) << "\n";
	std::cout << ::max<double>(c, d) << "\n";
	std::cout << ::max<std::string>(one, two) << "\n";
	std::cout << ::max<char>(three, four) << "\n";

	{
		const int a = 5;
		const int b = 7;
		std::cout << "Testing max with consts -----------\n";

		std::cout << ::max<const int>(a,b) << "\n";
	}
	return 0;
}
