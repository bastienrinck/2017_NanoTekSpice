/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#include "Output.hpp"

Component_Output::Component_Output()
{}

nts::Tristate Component_Output::compute(std::size_t pin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	std::get<1>(_inPin)->compute(std::get<2>(_inPin));
	return *(std::get<0>(_inPin));
}

nts::Tristate &Component_Output::getPin(std::size_t pin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	return *(std::get<0>(_inPin));
}

void Component_Output::setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin)
{
	if (pin != 1)
		throw std::out_of_range("pin out of authorized range");
	_inPin = std::make_tuple(&(other.getPin(otherPin)), &other, otherPin);
}

void Component_Output::dump() const
{
	nts::Tristate *t = std::get<0>(_inPin);
	std::cout
		<< "=== Output ===" << std::endl
		<< "Pin 1: " << (t ? *t : -1) << std::endl
		<< "==============" << std::endl;
}
