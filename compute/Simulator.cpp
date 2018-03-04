/*
** EPITECH PROJECT, 2021
** cpp_nanotekspice
** File description:
** Created by rectoria
*/

#include <iostream>
#include <vector>
#include <csignal>
#include <functional>
#include <regex>
#include "Simulator.hpp"
#include "../parser/Parser.hpp"
#include "../TekSpice.hpp"

std::atomic_bool Simulator::simLoop(false);

Simulator::Simulator()
{
}

Simulator::~Simulator()
{
}

void Simulator::parseFile(std::string &filename)
{
	Parser p;

	components = p.parse_file(filename);
}

bool Simulator::parseArgs(int ac, char **av)
{
	std::vector<std::string> args(ac);

	for (int i = 0; i < ac; ++i)
		args[i] = std::string(av[i]);
	if (ac < 2)
		return false;
	parseFile(args[1]);
	std::regex re("[a-zA-Z0-9]+=[01]");
	std::smatch m;
	for (int j = 2; j < ac; ++j) {
		if (!std::regex_match(args[j], m, re))
			return false;
		std::regex reg("[a-zA-Z0-9]+");
		auto first = std::sregex_iterator(args[j].begin(),
			args[j].end(), reg);
		std::string name = first->str();
		int val = std::stoi((++first)->str());
		if (components.count(name) &&
			components[name]->getType() == nts::C_INPUT)
			components[name]->getPin(1) = nts::Tristate(val);
		else if (components.count(name) &&
			components[name]->getType() == nts::C_CLOCK)
			components[name]->getPin(1) = nts::Tristate(
				val ? val - 1 : val + 1);
	}
	return true;
}

void Simulator::exit()
{
	stop = true;
}

void Simulator::display()
{
	typedef std::pair<std::string, nts::IComponent *> CustomPair;
	std::vector<CustomPair> arr;

	for (auto &i : components)
		if (i.second->getType() == nts::C_OUTPUT)
			arr.emplace_back(i.first, i.second.get());
	std::sort(arr.begin(), arr.end(),
		[](CustomPair first, CustomPair second) {
			return strcmp(std::get<0>(first).c_str(),
				std::get<0>(second).c_str()) < 0;
		});
	for (auto &i : arr)
		if (std::get<1>(i)->getPin(1) != -1)
			std::cout << std::get<0>(i) + "="
				<< std::get<1>(i)->getPin(1) << std::endl;
		else
			std::cout << std::get<0>(i) + "=U" << std::endl;
}

void Simulator::inputValue(std::string line)
{
	std::string str;
	int pin;
	unsigned long i = 0;

	for (unsigned long iter = line.find('=', i); iter > i; i++)
		str += line[i];
	pin = std::stoi(line.substr(i + 1, i + 2));

	if (components.count(str))
		components[str]->getPin(1) = nts::Tristate(pin);
}

void Simulator::simulate()
{

	for (auto &i : components)
		if (i.second->getType() == nts::C_OUTPUT)
			i.second->compute();
}

void Simulator::my_handler(int s)
{
	(void)s;
	simLoop = false;
}

void Simulator::loop()
{
	simLoop = true;

	signal(SIGINT, &Simulator::my_handler);
	while (simLoop)
		simulate();
}

void Simulator::dump()
{
	for (auto &i : components)
		i.second->dump();
}

bool Simulator::chipsetsAreSet()
{
	for (auto &c : components) {
		if ((c.second->getType() == nts::C_INPUT ||
			c.second->getType() == nts::C_CLOCK) &&
			c.second->getPin(1) == nts::UNDEFINED)
			return false;
	}
	return true;
}

bool Simulator::start(int ac, char **av)
{
	if (!parseArgs(ac, av)) {
		std::cout << "Bad arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	if (!chipsetsAreSet()) {
		std::cout << "Inputs undefined" << std::endl;
		return (EXIT_FAILURE);
	}
	simulate();
	display();
	getCommand();
	return (EXIT_SUCCESS);
}

void Simulator::getCommand()
{
	static const std::vector<std::string> cmd = {"exit", "display",
		"simulate", "loop", "dump"};
	static void (Simulator::*fptr[])() = {&Simulator::exit,
		&Simulator::display, &Simulator::simulate, &Simulator::loop,
		&Simulator::dump};
	std::string line;
	std::smatch m;

	do {
		std::cout << "> ";
		std::cin >> line;
		if (std::regex_match(line, m, std::regex("[a-zA-Z0-9]+=[01]")))
			inputValue(line);
		else if (!std::cin.eof())
			for (unsigned i = 0; i < cmd.size(); i++) {
				if (line == cmd[i]) {
					(this->*fptr[i])();
					break;
				}
			}
	} while (!stop && !std::cin.eof());
}
