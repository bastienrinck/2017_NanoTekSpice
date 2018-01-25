/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** pool
*/

#pragma once

#include "IComponent.hpp"

class Logic {
	public:
		static nts::Tristate nor(const nts::Tristate &first,
				const nts::Tristate &second,
				nts::Tristate &res)
		{
			if (first == nts::UNDEFINED || second == nts::UNDEFINED)
				res = nts::UNDEFINED;
			else if (first == nts::FALSE && second == nts::FALSE)
				res = nts::TRUE;
			else
				res = nts::FALSE;
			return res;
		}
	protected:
	private:
		Logic();
		~Logic();
};