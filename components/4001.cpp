/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#include <iostream>
#include "4001.hpp"

Component_4001::Component_4001()
	: _inPins(14)
	, _outPins(4)
{
	for (auto &i : _outPins)
		i = nts::UNDEFINED;
	_inPins[2] = &(_outPins[0]);
	_inPins[3] = &(_outPins[1]);
	_inPins[9] = &(_outPins[2]);
	_inPins[10] = &(_outPins[3]);
	_pair[2] = {1, 2};
	_pair[3] = {5, 6};
	_pair[9] = {8, 9};
	_pair[10] = {12, 13};
}

nts::Tristate Component_4001::compute(std::size_t pin)
{
	return Logic::nor(
		getPin(_pair[pin-1][0]),
		getPin(_pair[pin-1][1]),
		*(_inPins[pin-1])
	);
}

nts::Tristate &Component_4001::getPin(std::size_t pin)
{
	return *(_inPins[pin - 1]);
}

void Component_4001::setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin)
{
	_inPins[pin - 1] = &(other.getPin(otherPin));
}
