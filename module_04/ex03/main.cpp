/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:16:46 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/19 15:16:21 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Character.hpp"
//#include "Colors.h"
#include "Cure.hpp"
#include "Ice.hpp"
#include "utils.hpp"
//#include "MateriaSource.hpp"
#include <iostream>

void	testMateriaSource(void)
{
	std::cout << YELLOW << std::endl <<  "-------------------------------" << std::endl
		<< "\tMATERIA SOURCE TEST" << std::endl
		<<  "-------------------------------" << RESET << std::endl;
	std::cout << std::endl << "-- MATERIA SOURCE CREATION" << std::endl;
//	MateriaSource * source = new MateriaSource();
	Ice Ice1;
}

int	main(void)
{
	testMateriaSource();
	return (0);
}
