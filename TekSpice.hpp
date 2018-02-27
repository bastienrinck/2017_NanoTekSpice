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
#include "components/4008.hpp"
#include "components/4011.hpp"
#include "components/4030.hpp"
#include "components/4069.hpp"
#include "components/4071.hpp"
#include "components/4081.hpp"
#include "components/Input.hpp"
#include "components/Output.hpp"

class TekSpice {
	public:
		std::unique_ptr <nts::IComponent> createComponent(const std::string &, const std::string &);

		TekSpice();
		~TekSpice();
	protected:
	private:
		std::map<std::string, std::unique_ptr<nts::IComponent>(*)(const std::string &)> _fcts = {
			{"input", [](const std::string &){return std::unique_ptr<nts::IComponent>(new Component_Input);}},
			{"output", [](const std::string &){return std::unique_ptr<nts::IComponent>(new Component_Output);}},
			{"4001", [](const std::string &){return std::unique_ptr<nts::IComponent>(new Component_4001);}},
			{"4008", [](const std::string &){return std::unique_ptr<nts::IComponent>(new Component_4008);}},
			{"4011", [](const std::string &){return std::unique_ptr<nts::IComponent>(new Component_4011);}},
			{"4030", [](const std::string &){return std::unique_ptr<nts::IComponent>(new Component_4030);}},
			{"4069", [](const std::string &){return std::unique_ptr<nts::IComponent>(new Component_4069);}},
			{"4071", [](const std::string &){return std::unique_ptr<nts::IComponent>(new Component_4071);}},
			{"4081", [](const std::string &){return std::unique_ptr<nts::IComponent>(new Component_4081);}}
		};
};

#endif
