/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#include <algorithm>
#include "4081.hpp"

Component_4081::Component_4081()
	: _inPins(14)
	, _outPins(4)
{
	for (auto &i : _outPins)
		i = nts::UNDEFINED;
	_inPins[2] = std::make_tuple(&(_outPins[0]), nullptr, -1);
	_inPins[3] = std::make_tuple(&(_outPins[1]), nullptr, -1);
	_inPins[9] = std::make_tuple(&(_outPins[2]), nullptr, -1);
	_inPins[10] = std::make_tuple(&(_outPins[3]), nullptr, -1);
	_computablePins = {3, 4, 10, 11};
	_prohibedPins = {7, 14};
	_pair[2] = {1, 2};
	_pair[3] = {5, 6};
	_pair[9] = {8, 9};
	_pair[10] = {12, 13};
}

nts::Tristate Component_4081::compute(std::size_t pin)
{
	if (std::find(_computablePins.begin(), _computablePins.end(), pin) ==
		_computablePins.end())
		throw std::out_of_range("pin not computable");
	if (!&getPin(_pair[pin-1][0]) || !&getPin(_pair[pin-1][1]))
		return nts::UNDEFINED;
	std::get<1>(_inPins[_pair[pin-1][0] - 1])
		->compute(std::get<2>(_inPins[_pair[pin-1][0] - 1]));
	std::get<1>(_inPins[_pair[pin-1][1] - 1])
		->compute(std::get<2>(_inPins[_pair[pin-1][1] - 1]));
	return Logic::and_(
		getPin(_pair[pin-1][0]),
		getPin(_pair[pin-1][1]),
		*(std::get<0>(_inPins[pin-1]))
	);
}

nts::Tristate &Component_4081::getPin(std::size_t pin)
{
	return *(std::get<0>(_inPins[pin - 1]));
}

void Component_4081::setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin)
{
	if (std::find(_computablePins.begin(), _computablePins.end(), pin) !=
		_computablePins.end())
		throw std::out_of_range("computable pins are read-only");
	_inPins[pin - 1] = std::make_tuple(&(other.getPin(otherPin)), &other,
						otherPin);
}

void Component_4081::dump() const
{
	std::cout << std::endl << "=== 4081 ===" << std::endl;
	
	for (int i = 0 ; i < _inPins.size() ; ++i) {
		nts::Tristate *t = std::get<0>(_inPins[i]);
		std::cout << "Pin "
			<< i + 1
			<< ": "
			<< (t ? *t : -1)
			<< std::endl;
	}
	std::cout << "============" << std::endl;
}
