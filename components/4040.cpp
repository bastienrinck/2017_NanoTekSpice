/*
** EPITECH PROJECT, 2021
** cpp_nanotekspice
** File description:
** Created by rectoria
*/

#include <algorithm>
#include "4040.hpp"

Component_4040::Component_4040() : _inPins(16), _outPins(12), _tempOutPins(12)
{
	for (auto &i : _outPins)
		i = nts::Tristate::UNDEFINED;
	_inPins[0] = std::make_tuple(&(_outPins[11]), nullptr, -1);
	_inPins[1] = std::make_tuple(&(_outPins[5]), nullptr, -1);
	_inPins[2] = std::make_tuple(&(_outPins[4]), nullptr, -1);
	_inPins[3] = std::make_tuple(&(_outPins[6]), nullptr, -1);
	_inPins[4] = std::make_tuple(&(_outPins[3]), nullptr, -1);
	_inPins[5] = std::make_tuple(&(_outPins[2]), nullptr, -1);
	_inPins[6] = std::make_tuple(&(_outPins[1]), nullptr, -1);
	_inPins[8] = std::make_tuple(&(_outPins[0]), nullptr, -1);
	_inPins[11] = std::make_tuple(&(_outPins[8]), nullptr, -1);
	_inPins[12] = std::make_tuple(&(_outPins[7]), nullptr, -1);
	_inPins[13] = std::make_tuple(&(_outPins[9]), nullptr, -1);
	_inPins[14] = std::make_tuple(&(_outPins[10]), nullptr, -1);
	_prohibedPins = {8, 16};
	_computablePins = {1, 2, 3, 4, 5, 6, 7, 9, 12, 13, 14, 15};
}

nts::Tristate Component_4040::compute(std::size_t pin)
{
	if (std::find(_computablePins.begin(), _computablePins.end(), pin) ==
		_computablePins.end()) {
		throw std::out_of_range("pin not computable");
	}
	for (auto i : {10, 11}) {
		getPin(i);
		std::get<1>(_inPins[i-1])->compute(std::get<2>(_inPins[i-1]));
	}
	if (!getPin(10) && _prev_clock == nts::Tristate::TRUE) {
		size_t ret = 0;
		_tempOutPins[11] += 1;
		for (int i = 11; i >= 0; --i) {
			if (ret) {
				_tempOutPins[i] += ret;
				ret = 0;
			}
			if (_tempOutPins[i] >= 2) {
				_tempOutPins[i] = 0;
				ret = 1;
			}
		}
	}
	for (int i = 0; i < 12; ++i) {
		_outPins[i] = (getPin(11) == nts::Tristate::TRUE) ?
			nts::Tristate::FALSE :
			static_cast<nts::Tristate>(_tempOutPins[i]);
	}
	_prev_clock = getPin(10) == nts::Tristate::TRUE ? nts::Tristate::TRUE :
		nts::Tristate::FALSE;
	return *std::get<0>(_inPins[pin - 1]);
}

void Component_4040::setLink(std::size_t pin, nts::IComponent &other,
	std::size_t otherPin
)
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

nts::Tristate &Component_4040::getPin(std::size_t pin)
{
	if (std::find(_prohibedPins.begin(), _prohibedPins.end(), pin) !=
		_prohibedPins.end())
		throw std::out_of_range("pin out of authorized range");
	else if (std::get<0>(_inPins[pin - 1]) == nullptr)
		throw std::runtime_error("pin not linked");
	return *(std::get<0>(_inPins[pin - 1]));
}

void Component_4040::dump() const
{
	std::cout << std::endl << "=== 4040 ===" << std::endl;

	for (size_t i = 0; i < _inPins.size(); ++i) {
		nts::Tristate *t = std::get<0>(_inPins[i]);
		std::cout << "Pin " << i + 1 << ": " << (t ? *t : -1)
			<< std::endl;
	}
	std::cout << "============" << std::endl;
}
