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

	for (int i = 0 ; i < ac ; ++i) {
		args[i] = std::string(av[i]);
	}
	if (ac < 2)
		return false;
	parseFile(args[1]);
	if (ac > 2) {
		std::regex re("[a-zA-Z0-9]+=([01]|-1)");
		std::smatch m;
		for (int j = 2 ; j < ac ; ++j) {
			if (!std::regex_match(args[j], m, re))
				return false;
		}
	}
	return true;
}

void Simulator::exit()
{
	stop = true;
}

void Simulator::display()
{
	for (auto i : components)
		if (i.second->getType() == nts::C_OUTPUT)
			std::cout << i.first + "=" <<i.second->getPin(1) << std::endl;
}

void Simulator::inputValue()
{
}

void Simulator::simulate()
{

	for(auto i : components)
		if (i.second->getType() == nts::C_OUTPUT)
			i.second->compute();
}

void Simulator::my_handler(int s) {
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
	for (auto i : components)
		i.second->dump();
}

void Simulator::getCommand()
{
	static const std::vector<std::string> cmd = {"exit", "display",
		"input=value", "simulate", "loop", "dump"};
	static void (Simulator::*fptr[])() = {&Simulator::exit,
		&Simulator::display, &Simulator::inputValue,
		&Simulator::simulate, &Simulator::loop, &Simulator::dump};
	std::string line;

	do {
		std::cout << ">";
		std::cin >> line;
		for (unsigned i = 0; i < cmd.size(); i++) {
			if (line == cmd[i]) {
				(this->*fptr[i])();
				break;
			}
		}
	} while (!stop);
}
