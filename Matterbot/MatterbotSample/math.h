#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct MathCommand : ICommand {
		std::wstring get_name() override {
			return L"math";
		}

		std::wstring get_help() override {
			return L"`math [CMD]`:\n`add`: Add 2 numbers\n`subtract`: Subtract 2 numbers\n`multiply`: Multiply 2 numbers\n`divide': Divide 2 numbers";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			if (command_text == L"add")
			{
				return ;
			}
			else if (command_text == L"subtract")
			{

			}
			else if (command_text == L"multiply")
			{

			}
			else if (command_text == L"divide")
			{

			}
			else
			{
				return L"Not a good choice";
			}
		}
	};
}

