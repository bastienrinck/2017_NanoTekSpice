/*
** EPITECH PROJECT, 2018
** TekSpice
** File description:
** oui
*/

#include "TekSpice.hpp"

TekSpice::TekSpice()
{}

TekSpice::~TekSpice()
{}

std::shared_ptr <nts::IComponent> TekSpice::createComponent(const std::string &type, const std::string &value)
{
	if (_fcts[type])
		return _fcts[type](value);
	else
		throw std::out_of_range("type not implemented");
}
