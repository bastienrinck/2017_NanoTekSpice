/*
** EPITECH PROJECT, 2018
** IComponent
** File description:
** oui
*/

#pragma once

#include <string>

namespace nts
{
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	enum C_TYPE {
		C_INPUT,
		C_OUTPUT,
		C_4001,
		C_4008,
		C_4011,
		C_4030,
		C_4069,
		C_4071,
		C_4081,
	};

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
