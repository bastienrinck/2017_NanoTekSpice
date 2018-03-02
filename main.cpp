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

	if (s.parseArgs(ac, av))
		s.getCommand();
	else
		std::cout << "Bad args" << std::endl;
	/*TekSpice t;
	std::shared_ptr<nts::IComponent> i1 = t.createComponent("input", "");
	std::shared_ptr<nts::IComponent> i2 = t.createComponent("input", "");
	std::shared_ptr<nts::IComponent> c4001 = t.createComponent("4001", "");
	std::shared_ptr<nts::IComponent> o1 = t.createComponent("output", "");
	printf("c4001: %p\n", c4001.get());
	printf("i1: %p\n", i1.get());
	printf("i2: %p\n", i2.get());
	i1->getPin(1) = nts::FALSE;
	i2->getPin(1) = nts::FALSE;
	c4001->setLink(1, *i1, 1);
	c4001->setLink(2, *i2, 1);
	o1->setLink(1, *c4001, 3);
	o1->compute(1);
	std::cout << "o1: " << o1->getPin(1) << std::endl;*/
}
