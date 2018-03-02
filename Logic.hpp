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
		Logic() = delete;
		~Logic() = delete;

		static nts::Tristate or_(const nts::Tristate &,
					const nts::Tristate &,
					nts::Tristate &);
		static nts::Tristate nor_(const nts::Tristate &,
					const nts::Tristate &,
					nts::Tristate &);
		static nts::Tristate xor_(const nts::Tristate &,
					const nts::Tristate &,
					nts::Tristate &);
		static nts::Tristate and_(const nts::Tristate &,
					const nts::Tristate &,
					nts::Tristate &);
		static nts::Tristate nand_(const nts::Tristate &,
					const nts::Tristate &,
					nts::Tristate &);
		static nts::Tristate not_(const nts::Tristate &,
					nts::Tristate &);
		static nts::Tristate sum_(const nts::Tristate &,
					const nts::Tristate &,
					const nts::Tristate &,
					nts::Tristate &,
					nts::Tristate &);
		
	protected:
	private:
};