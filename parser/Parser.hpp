/*
** EPITECH PROJECT, 2021
** cpp_nanotekspice
** File description:
** Created by rectoria
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include <memory>
#include <unordered_map>
#include "../IComponent.hpp"

class Parser {
public:
	Parser();

	~Parser();

public:
	std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> parse_file(
		std::string const &
	);

private:
	std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &get_chipset(
		std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &,
		std::ifstream &
	);

	std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &get_links(
		std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &components,
		std::ifstream &file
	);
};

#endif
