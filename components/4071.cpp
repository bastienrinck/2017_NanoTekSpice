/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#include <algorithm>
#include "4071.hpp"

Component_4071::Component_4071()
	: _inPins(14)
	, _outPins(4)
{
	for (auto &i : _outPins)
		i = nts::UNDEFINED;
	_inPins[2] = std::make_tuple(&(_outPins[0]), nullptr);
	_inPins[3] = std::make_tuple(&(_outPins[1]), nullptr);
	_inPins[9] = std::make_tuple(&(_outPins[2]), nullptr);
	_inPins[10] = std::make_tuple(&(_outPins[3]), nullptr);
	_computablePins = {3, 4, 10, 11};
	_prohibedPins = {7, 14};
	_pair[2] = {1, 2};
	_pair[3] = {5, 6};
	_pair[9] = {8, 9};
	_pair[10] = {12, 13};
}

nts::Tristate Component_4071::compute(std::size_t pin)
{
	if (std::find(_computablePins.begin(), _computablePins.end(), pin) ==
		_computablePins.end())
		throw std::out_of_range("pin not computable");
	if (!&getPin(_pair[pin-1][0]) || !&getPin(_pair[pin-1][1]))
		return nts::UNDEFINED;
	return Logic::or_(
		getPin(_pair[pin-1][0]),
		getPin(_pair[pin-1][1]),
		*(std::get<0>(_inPins[pin-1]))
	);
}

nts::Tristate &Component_4071::getPin(std::size_t pin)
{
	return *(std::get<0>(_inPins[pin - 1]));
}

void Component_4071::setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin)
{
	if (std::find(_computablePins.begin(), _computablePins.end(), pin) !=
		_computablePins.end())
		throw std::out_of_range("computable pins are read-only");
	_inPins[pin - 1] = std::make_tuple(&(other.getPin(otherPin)), &other);
}
