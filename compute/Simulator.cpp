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

void Simulator::exit()
{
	stop = true;
}

void Simulator::display()
{
	for (auto i : components)
		std::cout << i.first << " : " << typeid(*i.second).name()
			<< std::endl;
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
