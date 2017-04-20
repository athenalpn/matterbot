#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct MathCommand : ICommand {
		std::wstring get_name() override { //makes sure commands go to interface(inheritance)
			return L"math";
		}

		std::wstring get_help() override {
			return L"`math [CMD]`:\n `a` : Add two numbers\n `s`: Subtract two numbers\n `m`: Multiply two numbers\n `d`: Divide two numbers\n `r`: Remainder of two numbers\n";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			std::wstring newString = command_text;
			std::wstring option = command_text.substr(0, 1);

			if (option == L"a")
			{
				std::wstring ignore = newString.substr(1, newString.find(' '));
				newString = newString.substr(newString.find(' ') + 1);
				std::wstring firstInt = newString.substr(0, newString.find('+'));
				std::wstring secondInt = newString.substr(newString.find('+') + 1);
				int var1 = std::stoi(firstInt);
				int var2  = std::stoi(secondInt);
				int answer = var1 + var2;
				return L"The answer is: " + std::to_wstring(answer);
			}
			else if (option == L"s")
			{
				std::wstring ignore = newString.substr(1, newString.find(' '));
				newString = newString.substr(newString.find(' ') + 1);
				std::wstring firstInt = newString.substr(0, newString.find('-'));
				std::wstring secondInt = newString.substr(newString.find('-') + 1);
				int var1 = std::stoi(firstInt);
				int var2 = std::stoi(secondInt);
				int answer = var1 - var2;
				return L"The answer is: " + std::to_wstring(answer);
				
			}
			else if (option == L"m")
			{
				std::wstring ignore = newString.substr(1, newString.find(' '));
				newString = newString.substr(newString.find(' ') + 1);
				std::wstring firstInt = newString.substr(0, newString.find('*'));
				std::wstring secondInt = newString.substr(newString.find('*') + 1);
				int var1 = std::stoi(firstInt);
				int var2 = std::stoi(secondInt);
				int answer = var1 * var2;
				return L"The answer is: " + std::to_wstring(answer);
			}
			else if (option == L"d")
			{
				std::wstring ignore = newString.substr(1, newString.find(' '));
				newString = newString.substr(newString.find(' ') + 1);
				std::wstring firstInt = newString.substr(0, newString.find('/'));
				std::wstring secondInt = newString.substr(newString.find('/') + 1);
				int var1 = std::stoi(firstInt);
				int var2 = std::stoi(secondInt);
				if (var2 == 0)
				{
					return L"You cannot divide by zero, duh";
				}
				else
				{
					int answer = var1 / var2;
					return L"The answer is: " + std::to_wstring(answer);
				}
			}
			else if (option == L"r")
			{
				std::wstring ignore = newString.substr(1, newString.find(' '));
				newString = newString.substr(newString.find(' ') + 1);
				std::wstring firstInt = newString.substr(0, newString.find('%'));
				std::wstring secondInt = newString.substr(newString.find('%') + 1);
				int var1 = std::stoi(firstInt);
				int var2 = std::stoi(secondInt);
				int answer = var1 % var2;
				return L"The answer is: " + std::to_wstring(answer);
			}
			else
			{
				return L"YOU BROKE IT!!"; 
			}
		}
	};
}
