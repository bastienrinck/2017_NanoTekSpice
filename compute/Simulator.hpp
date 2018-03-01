/*
** EPITECH PROJECT, 2021
** cpp_nanotekspice
** File description:
** Created by rectoria
*/

#ifndef	SIMULATOR_HPP
#define SIMULATOR_HPP

#include <memory>
#include <unordered_map>
#include <atomic>
#include "../IComponent.hpp"

class Simulator {
	public:
		Simulator();
		~Simulator();

	public:
		void parseFile(std::string &);
		void getCommand();
	private:
		void exit();
		void display();
		void inputValue();
		void simulate();
		void loop();
		void dump();
		static void my_handler(int);
		std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> components;
		static std::atomic_bool simLoop;
		bool stop = false;
};

#endif
