/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#include "True.hpp"

Component_True::Component_True()
	: _outPin(nts::TRUE)
{
}

nts::Tristate Component_True::compute(std::size_t pin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	return _outPin;
}

nts::Tristate &Component_True::getPin(std::size_t pin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	return _outPin;
}

void Component_True::setLink(std::size_t, nts::IComponent &,
				std::size_t)
{
	throw std::out_of_range("pin out of authorized range");
}

void Component_True::dump() const
{
	std::cout 
		<< "=== True ===" << std::endl
		<< "Pin 1: " << _outPin << std::endl
		<< "============" << std::endl;
}
