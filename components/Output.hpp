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
	protected:
	private:
		std::vector<nts::Tristate *> _inPins;
		std::vector<nts::IComponent *> dependencies;
};
