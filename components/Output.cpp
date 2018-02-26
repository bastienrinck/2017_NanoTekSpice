/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#include "Output.hpp"

Component_Output::Component_Output()
	: _inPins(1)
{}

nts::Tristate Component_Output::compute(std::size_t pin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	return *_inPins[pin];
}

nts::Tristate &Component_Output::getPin(std::size_t pin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	return *(_inPins[pin - 1]);
}

void Component_Output::setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	_inPins[pin - 1] = &(other.getPin(otherPin));
}

void Component_Output::dump() const
{}
