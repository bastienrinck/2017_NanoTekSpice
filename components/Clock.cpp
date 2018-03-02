/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#include "Clock.hpp"

Component_Clock::Component_Clock()
	: _outPin(nts::UNDEFINED)
{
}

nts::Tristate Component_Clock::compute(std::size_t pin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	_outPin = (_outPin == nts::TRUE) ? nts::FALSE : nts::TRUE;
	return _outPin;
}

nts::Tristate &Component_Clock::getPin(std::size_t pin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	return _outPin;
}

void Component_Clock::setLink(std::size_t, nts::IComponent &,
				std::size_t)
{
	throw std::out_of_range("pin out of authorized range");
}

void Component_Clock::dump() const
{
	std::cout 
		<< std::endl << "=== Clock ===" << std::endl
		<< "Pin 1: " << _outPin << std::endl
		<< "=============" << std::endl;
}
