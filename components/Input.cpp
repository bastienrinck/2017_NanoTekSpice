/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#include "Input.hpp"

Component_Input::Component_Input()
	: _inPins(1)
	, _outPins(1)
{
	for (auto &i : _outPins)
		i = nts::UNDEFINED;
	_inPins[0] = &(_outPins[0]);
}

nts::Tristate Component_Input::compute(std::size_t pin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	return *(_inPins[pin - 1]);
}

nts::Tristate &Component_Input::getPin(std::size_t pin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	return *(_inPins[pin - 1]);
}

void Component_Input::setLink(std::size_t, nts::IComponent &,
				std::size_t)
{
	throw std::out_of_range("pin out of authorized range");
}

void Component_Input::dump() const
{
	std::cout 
		<< "=== Input ===" << std::endl
		<< "Pin 1: " << *(_inPins[0]) << std::endl
		<< "=============" << std::endl;
}
