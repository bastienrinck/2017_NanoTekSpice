/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** nanotekspice
*/

#include "Logic.hpp"

nts::Tristate Logic::or_(const nts::Tristate &first,
		const nts::Tristate &second,
		nts::Tristate &res)
{
	if (first == nts::UNDEFINED || second == nts::UNDEFINED)
		res = nts::UNDEFINED;
	else if (first == nts::TRUE || second == nts::TRUE)
		res = nts::TRUE;
	else
		res = nts::FALSE;
	return res;
}

nts::Tristate Logic::nor_(const nts::Tristate &first,
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

nts::Tristate Logic::xor_(const nts::Tristate &first,
		const nts::Tristate &second,
		nts::Tristate &res)
{
	if (first == nts::UNDEFINED || second == nts::UNDEFINED)
		res = nts::UNDEFINED;
	else if (first == second)
		res = nts::FALSE;
	else
		res = nts::TRUE;
	return res;
}

nts::Tristate Logic::and_(const nts::Tristate &first,
		const nts::Tristate &second,
		nts::Tristate &res)
{
	if (first == nts::UNDEFINED || second == nts::UNDEFINED)
		res = nts::UNDEFINED;
	else if (first == nts::TRUE && second == nts::TRUE)
		res = nts::TRUE;
	else
		res = nts::FALSE;
	return res;
}

nts::Tristate Logic::nand_(const nts::Tristate &first,
		const nts::Tristate &second,
		nts::Tristate &res)
{
	if (first == nts::UNDEFINED || second == nts::UNDEFINED)
		res = nts::UNDEFINED;
	else if (first == nts::TRUE && second == nts::TRUE)
		res = nts::FALSE;
	else
		res = nts::TRUE;
	return res;
}

nts::Tristate Logic::not_(const nts::Tristate &first,
		nts::Tristate &res)
{
	if (first == nts::UNDEFINED)
		res = nts::UNDEFINED;
	else
		res = static_cast<nts::Tristate>(first == nts::FALSE);
	return res;
}

nts::Tristate Logic::sum_(const nts::Tristate &first,
		const nts::Tristate &second,
		const nts::Tristate &ret,
		nts::Tristate &res,
		nts::Tristate &ret_res)
{
	if (first == nts::UNDEFINED || second == nts::UNDEFINED ||
		ret == nts::UNDEFINED) {
		res = nts::UNDEFINED;
		ret_res = nts::UNDEFINED;
	} else {
		int calc = first + second + ret;
		ret_res = (calc >= 2) ? nts::TRUE : nts::FALSE;
		calc -= ret_res * 2;
		res = (calc >= 1) ? nts::TRUE : nts::FALSE;
	}
	return res;
}