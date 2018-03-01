/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#pragma once

#include <vector>
#include <map>
#include "../IComponent.hpp"
#include "../Logic.hpp"

class Component_Output : public nts::IComponent {
	public:
		Component_Output();
		~Component_Output() = default;

		nts::Tristate compute(std::size_t = 1) final;
		void setLink(std::size_t, nts::IComponent &, std::size_t) final;
		nts::Tristate &getPin(std::size_t) final;
		void dump() const final;
		nts::C_TYPE getType() { return nts::C_OUTPUT; }
	protected:
	private:
		std::tuple<nts::Tristate *, IComponent *, size_t> _inPin;
};
