/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#include <algorithm>
#include "4008.hpp"

/**
 * 
 *      +-------------------------------------------+
 *	| _outPins index | _inPins index | real pin |
 *	|        0       |       9       |    S1    |
 *	|        1       |      10       |    S2    |
 *	|        2       |      11       |    S3    |
 *	|        3       |      12       |    S4    |
 *	|        4       |      13       |    C0    |
 *	|        5       |      16       |    C2    |
 *	|        6       |      17       |    C3    |
 *	|        7       |      18       |    C4    |
 *      +-------------------------------------------+
 * 
**/

Component_4008::Component_4008()
	: _inPins(19)
	, _outPins(8)
{
	for (auto &i : _outPins)
		i = nts::UNDEFINED;
	_inPins[9] = std::make_tuple(&(_outPins[0]), nullptr);
	_inPins[10] = std::make_tuple(&(_outPins[1]), nullptr);
	_inPins[11] = std::make_tuple(&(_outPins[2]), nullptr);
	_inPins[12] = std::make_tuple(&(_outPins[3]), nullptr);
	_inPins[13] = std::make_tuple(&(_outPins[4]), nullptr);
	_inPins[16] = std::make_tuple(&(_outPins[5]), nullptr);
	_inPins[17] = std::make_tuple(&(_outPins[6]), nullptr);
	_inPins[18] = std::make_tuple(&(_outPins[7]), nullptr);
	_prohibedPins = {8, 16};
	_computablePins = {10, 11, 12, 13};
	_pair[9] = {6, 7, 9};
	_pair[10] = {4, 5, 17};
	_pair[11] = {2, 3, 18};
	_pair[12] = {15, 1, 19};
}

nts::Tristate Component_4008::compute(std::size_t pin)
{
	if (std::find(_computablePins.begin(), _computablePins.end(), pin) ==
		_computablePins.end())
		throw std::out_of_range("pin not computable");
	if (!&getPin(_pair[pin-1][0]) || !&getPin(_pair[pin-1][1]) ||
		!&getPin(_pair[pin-1][2]))
		return nts::UNDEFINED;
	auto res =  Logic::sum_(
		getPin(_pair[pin-1][0]),
		getPin(_pair[pin-1][1]),
		getPin(_pair[pin-1][2]),
		getPin(pin),
		getPin(14)
	);
	if (pin != 13)
		*std::get<0>(_inPins[pin + 6]) = getPin(14);
	return res;
}

nts::Tristate &Component_4008::getPin(std::size_t pin)
{
	if (std::find(_prohibedPins.begin(), _prohibedPins.end(), pin) !=
		_prohibedPins.end())
		throw std::out_of_range("pin out of authorized range");
	return *(std::get<0>(_inPins[pin - 1]));
}

void Component_4008::setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin)
{
	if (std::find(_computablePins.begin(), _computablePins.end(), pin) !=
		_computablePins.end())
		throw std::out_of_range("computable pins are read-only");
	else if (std::find(_prohibedPins.begin(), _prohibedPins.end(), pin) !=
		_prohibedPins.end())
		throw std::out_of_range("pin out of authorized range");
	_inPins[pin - 1] = std::make_tuple(&(other.getPin(otherPin)), &other);
	dependencies.push_back(&other);
}