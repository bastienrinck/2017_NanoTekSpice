/*
** EPITECH PROJECT, 2017
** TekSpice
** File description:
** oui
*/

#include <iostream>
#include "compute/Simulator.hpp"
#include "TekSpice.hpp"

int main(int ac, char **av)
{
	Simulator s;

	if (s.start(ac, av))
		return 0;
	return 84;
}
