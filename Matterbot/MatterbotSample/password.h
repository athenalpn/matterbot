#pragma once
#include "Matterbot.h"
#include "Header.h"

namespace lospi
{
	struct passwordCommand : ICommand {
		std::wstring get_name() override {
			return L"password";
		}

		std::wstring get_help() override {
			return L"`password [MESSAGE]`: `password` will respond with whatever message you give it.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {
			std::wstring wpassword = command_text;
			std::string password = wstring_to_string(wpassword);
			
			return L"password saved";

		}
	};
}