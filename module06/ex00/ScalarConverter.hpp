/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:23:53 by plang             #+#    #+#             */
/*   Updated: 2024/10/29 15:06:18 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
	public:
		~ScalarConverter();

		class CustomException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		
		static void	convert(std::string);
};

#endif