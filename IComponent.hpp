/*
** EPITECH PROJECT, 2018
** IComponent
** File description:
** oui
*/

#pragma once

#include <string>
#include "TekSpice.hpp"

namespace nts
{
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	enum C_TYPE;

	class IComponent
	{
		public:
			virtual ~IComponent() = default;

			virtual nts::Tristate compute(std::size_t = 1) = 0;
			virtual void setLink(std::size_t, nts::IComponent &,
						std::size_t) = 0;
			virtual Tristate &getPin(std::size_t) = 0;
			virtual void dump() const = 0;

			virtual C_TYPE getType() = 0;
	};
}
