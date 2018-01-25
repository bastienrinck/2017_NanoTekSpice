/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#ifndef TEKSPICE_HPP
	#define TEKSPICE_HPP

#include <memory>
#include <string>
#include <map>
#include "IComponent.hpp"
#include "components/4001.hpp"

class TekSpice {
	public:
		std::unique_ptr <nts::IComponent> createComponent(const std::string &, const std::string &);

		TekSpice();
		~TekSpice();
	protected:
	private:
		std::map<std::string, std::unique_ptr<nts::IComponent>(*)(const std::string &)> _fcts = {
			{"4001", [](const std::string &){return std::unique_ptr<nts::IComponent>(new Component_4001);}}
		};
};

#endif
