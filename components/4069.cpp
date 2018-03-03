/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#include <algorithm>
#include "4069.hpp"

Component_4069::Component_4069()
	: _inPins(14)
	, _outPins(6)
{
	for (auto &i : _outPins)
		i = nts::UNDEFINED;
	_inPins[1] = std::make_tuple(&(_outPins[0]), nullptr, -1);
	_inPins[3] = std::make_tuple(&(_outPins[1]), nullptr, -1);
	_inPins[5] = std::make_tuple(&(_outPins[2]), nullptr, -1);
	_inPins[7] = std::make_tuple(&(_outPins[3]), nullptr, -1);
	_inPins[9] = std::make_tuple(&(_outPins[4]), nullptr, -1);
	_inPins[11] = std::make_tuple(&(_outPins[5]), nullptr, -1);
	_prohibedPins = {7, 14};
	_computablePins = {2, 4, 6, 8, 10, 12};
	_pair[1] = {1};
	_pair[3] = {3};
	_pair[5] = {5};
	_pair[7] = {9};
	_pair[9] = {11};
	_pair[11] = {13};
}

nts::Tristate Component_4069::compute(std::size_t pin)
{
	if (std::find(_computablePins.begin(), _computablePins.end(), pin) ==
		_computablePins.end())
		throw std::out_of_range("pin not computable");
	getPin(_pair[pin-1][0]);
	std::get<1>(_inPins[_pair[pin-1][0] - 1])
		->compute(std::get<2>(_inPins[_pair[pin-1][0] - 1]));
	return Logic::not_(
		getPin(_pair[pin-1][0]),
		*(std::get<0>(_inPins[pin-1]))
	);
}

nts::Tristate &Component_4069::getPin(std::size_t pin)
{
	if (std::find(_prohibedPins.begin(), _prohibedPins.end(), pin) !=
		_prohibedPins.end())
		throw std::out_of_range("pin out of authorized range");
	else if (std::get<0>(_inPins[pin - 1]) == nullptr)
		throw std::runtime_error("pin not linked");
	return *(std::get<0>(_inPins[pin - 1]));
}

void Component_4069::setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin)
{
	if (std::find(_computablePins.begin(), _computablePins.end(), pin) !=
		_computablePins.end())
		throw std::out_of_range("computable pins are read-only");
	else if (std::find(_prohibedPins.begin(), _prohibedPins.end(), pin) !=
		_prohibedPins.end())
		throw std::out_of_range("pin out of authorized range");
	_inPins[pin - 1] = std::make_tuple(&(other.getPin(otherPin)), &other,
						otherPin);
}

void Component_4069::dump() const
{
	std::cout << std::endl << "=== 4069 ===" << std::endl;
	
	for (size_t i = 0 ; i < _inPins.size() ; ++i) {
		nts::Tristate *t = std::get<0>(_inPins[i]);
		std::cout << "Pin "
			<< i + 1
			<< ": "
			<< (t ? *t : -1)
			<< std::endl;
	}
	std::cout << "============" << std::endl;
}

