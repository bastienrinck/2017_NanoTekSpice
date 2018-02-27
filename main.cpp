/*
** EPITECH PROJECT, 2017
** TekSpice
** File description:
** oui
*/

#include <iostream>
#include "parser/Parser.hpp"
#include "TekSpice.hpp"

int main(int ac, char **av)
{
	TekSpice t;
	Parser p;

	(void)ac;
	p.parse_file(av[1]);
	/*std::shared_ptr<nts::IComponent> i1 = t.createComponent("input", "");
	std::shared_ptr<nts::IComponent> i2 = t.createComponent("input", "");
	std::shared_ptr<nts::IComponent> c4001 = t.createComponent("4001", "");
	std::shared_ptr<nts::IComponent> o1 = t.createComponent("output", "");
	i1->getPin(1) = nts::FALSE;
	i2->getPin(1) = nts::FALSE;
	c4001->setLink(1, *i1, 1);
	c4001->setLink(2, *i2, 1);
	o1->setLink(1, *c4001, 3);
	c4001->compute(3);
	std::cout << "o1: " << o1->getPin(1) << std::endl;*/
}
