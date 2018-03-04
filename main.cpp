/*
** EPITECH PROJECT, 2017
** TekSpice
** File description:
** oui
*/

#include <iostream>
#include <signal.h>
#include "compute/Simulator.hpp"
#include "TekSpice.hpp"

void sig_handler(int sig)
{
	std::cerr << "Fatal error E00" << sig << std::endl;
	kill(0, SIGINT);
}

int main(int ac, char **av)
{
	Simulator s;

	signal(SIGSEGV, sig_handler);
	signal(SIGABRT, sig_handler);
	try {
		if (s.start(ac, av))
			return 0;
	} catch (std::exception &e) {
		std::cerr << "Fatal error: " << e.what() << std::endl;
	}
	return 84;
}
