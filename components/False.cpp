/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#include "False.hpp"

Component_False::Component_False()
	: _outPin(nts::FALSE)
{
}

nts::Tristate Component_False::compute(std::size_t pin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	return _outPin;
}

nts::Tristate &Component_False::getPin(std::size_t pin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	return _outPin;
}

void Component_False::setLink(std::size_t, nts::IComponent &,
				std::size_t)
{
	throw std::out_of_range("pin out of authorized range");
}

void Component_False::dump() const
{
	std::cout 
		<< "=== False ===" << std::endl
		<< "Pin 1: " << _outPin << std::endl
		<< "=============" << std::endl;
}
