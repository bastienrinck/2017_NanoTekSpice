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
	std::unordered_map<std::string,
	std::unique_ptr<nts::IComponent>> parse_file(
		std::string const &
	);

private:
	void get_chipset(std::unordered_map<std::string,
		std::unique_ptr<nts::IComponent>> &,
		std::ifstream &
	);

	void get_links(
		std::unordered_map<std::string,
		std::unique_ptr<nts::IComponent>> &,
		std::ifstream &
	);

	void get_links2(std::string &line,
		std::unordered_map<std::string,
		std::unique_ptr<nts::IComponent>> &components
	);
};

#endif
