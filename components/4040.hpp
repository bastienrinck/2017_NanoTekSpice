/*
** EPITECH PROJECT, 2021
** cpp_nanotekspice
** File description:
** Created by rectoria
*/

#pragma once

#include <vector>
#include <map>
#include <tuple>
#include "../IComponent.hpp"
#include "../Logic.hpp"

class Component_4040 : public nts::IComponent {
public:
	Component_4040();
	~Component_4040() final = default;

	nts::Tristate compute(std::size_t = 1) final;
	void setLink(std::size_t, nts::IComponent &, std::size_t) final;
	nts::Tristate &getPin(std::size_t) final;
	void dump() const final;
	nts::C_TYPE getType() {return nts ::C_4040;}
protected:
private:
	void proceed_4040();

	std::vector<std::tuple<nts::Tristate *, IComponent *, size_t>> _inPins;
	std::vector<nts::Tristate> _outPins;
	std::vector<int> _tempOutPins;
	std::vector<int> _prohibedPins;
	std::vector<int> _computablePins;
	std::map<int, std::vector<int>> _pair;
	nts::Tristate _prev_clock = nts::Tristate::FALSE;
};
