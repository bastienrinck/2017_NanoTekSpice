/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#include <algorithm>
#include "4514.hpp"

Component_4514::Component_4514()
	: _inPins(24)
	, _outPins(16)
{
	for (auto &i : _outPins)
		i = nts::UNDEFINED;
	_init_inPins();
	_prohibedPins = {12, 24};
	_computablePins = {4, 5, 6, 7, 8, 9, 10, 11,
		13, 14, 15, 16, 17, 18, 19, 20};
	_init_pair();
}

void Component_4514::_init_inPins()
{
	_inPins[3] = std::make_tuple(&(_outPins[0]), nullptr, -1);
	_inPins[4] = std::make_tuple(&(_outPins[1]), nullptr, -1);
	_inPins[5] = std::make_tuple(&(_outPins[2]), nullptr, -1);
	_inPins[6] = std::make_tuple(&(_outPins[3]), nullptr, -1);
	_inPins[7] = std::make_tuple(&(_outPins[4]), nullptr, -1);
	_inPins[8] = std::make_tuple(&(_outPins[5]), nullptr, -1);
	_inPins[9] = std::make_tuple(&(_outPins[6]), nullptr, -1);
	_inPins[10] = std::make_tuple(&(_outPins[7]), nullptr, -1);
	_inPins[12] = std::make_tuple(&(_outPins[8]), nullptr, -1);
	_inPins[13] = std::make_tuple(&(_outPins[9]), nullptr, -1);
	_inPins[14] = std::make_tuple(&(_outPins[10]), nullptr, -1);
	_inPins[15] = std::make_tuple(&(_outPins[11]), nullptr, -1);
	_inPins[16] = std::make_tuple(&(_outPins[12]), nullptr, -1);
	_inPins[17] = std::make_tuple(&(_outPins[13]), nullptr, -1);
	_inPins[18] = std::make_tuple(&(_outPins[14]), nullptr, -1);
	_inPins[19] = std::make_tuple(&(_outPins[15]), nullptr, -1);
}

void Component_4514::_init_pair()
{
	_pair[3] = {1, 1, 1, 0};
	_pair[4] = {0, 1, 1, 0};
	_pair[5] = {1, 0, 1, 0};
	_pair[6] = {0, 0, 1, 0};
	_pair[7] = {1, 1, 0, 0};
	_pair[8] = {1, 0, 0, 0};
	_pair[9] = {0, 1, 0, 0};
	_pair[10] = {0, 0, 0, 0};
	_pair[12] = {1, 0, 1, 1};
	_pair[13] = {0, 0, 1, 1};
	_pair[14] = {1, 1, 1, 1};
	_pair[15] = {0, 1, 1, 1};
	_pair[16] = {1, 0, 0, 1};
	_pair[17] = {0, 0, 0, 1};
	_pair[18] = {1, 1, 0, 1};
	_pair[19] = {0, 1, 0, 1};
}

nts::Tristate Component_4514::compute(std::size_t pin)
{
	if (std::find(_computablePins.begin(), _computablePins.end(), pin) ==
		_computablePins.end())
		throw std::out_of_range("pin not computable");
	if (getPin(1) != nts::Tristate::TRUE)
		return nts::Tristate::UNDEFINED;
	else if (getPin(23) == nts::Tristate::TRUE)
		return nts::Tristate::FALSE;
	for (auto i : {1, 2, 3, 21, 22, 23}) {
		getPin(i);
		std::get<1>(_inPins[i-1])
			->compute(std::get<2>(_inPins[i-1]));
	}
	if (_pair[pin-1][0] == getPin(2) && _pair[pin-1][1] == getPin(3) &&
		_pair[pin-1][2] == getPin(21) && _pair[pin-1][3] == getPin(22)) {
		for (auto &i : _outPins)
			i = nts::FALSE;
		getPin(pin) = nts::Tristate::TRUE;
	}
	return *std::get<0>(_inPins[pin-1]);
}

nts::Tristate &Component_4514::getPin(std::size_t pin)
{
	if (std::find(_prohibedPins.begin(), _prohibedPins.end(), pin) !=
		_prohibedPins.end())
		throw std::out_of_range("pin out of authorized range");
	else if (std::get<0>(_inPins[pin - 1]) == nullptr)
		throw std::runtime_error("pin not linked");
	return *(std::get<0>(_inPins[pin - 1]));
}

void Component_4514::setLink(std::size_t pin, nts::IComponent &other,
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

void Component_4514::dump() const
{
	std::cout << std::endl << "=== 4514 ===" << std::endl;
	
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
