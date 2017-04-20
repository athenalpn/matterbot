#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct StringCommand : ICommand {
		std::wstring get_name() override {
			return L"string";
		}

		std::wstring get_help() override {
			return L"`string [CMD]`:\n`1`: counts string characters\n`2`: splits string on whitespace\n`3`: turns all uppercase\n";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {
			
				std::wstring newString = command_text;
				std::wstring option = command_text.substr(0, 1);

			if (option == L"1")
			{
				return L"Your string count is: " + std::to_wstring(newString.length() - 2);
			}
			else if (option == L"2")
			{
				std::wstring ignore = newString.substr(1, newString.find(' '));
				newString = newString.substr(newString.find(' ') + 1);
				auto first = newString.find(' ');
				std::wstring firstWord = newString.substr(0, first);
				std::size_t pos = newString.find(' ');
				auto rest = newString.substr(pos);
				
				return L"First Part is: " + firstWord + L" & Second Part is: "  + rest;
			}
			else if (option == L"3")
			{
			 transform(newString.begin(), newString.end(), newString.begin(), ::toupper);

			 auto selection = newString.find(' ');
			 std::wstring firstWord = newString.substr(1, selection);
			 std::size_t pos = newString.find(' ');
			 auto upperString = newString.substr(pos);
			 
			 return upperString;
					
			}

			else {
				return L"You broke it";
			}
			
			return  command_text;
		}
	};
}