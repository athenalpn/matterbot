#pragma once
#include "Matterbot.h"
#include "MD5.h"
#include "Md5Utilities.h"


namespace lospi
{
	struct MD5Command : ICommand {
		std::wstring get_name() override {
			return L"md5";
		}

		std::wstring get_help() override {
			return L"`md5 [MD5]`: `md5` will respond with whatever message you give it.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			std::wstring MD5 = command_text;
			auto string = wstring_to_string(MD5);
			auto size = string.length();
			auto hash = string.c_str(); //this string pointer is actually 7 long because of null pointer
			//auto newHash = compute_md5(hash, size);
			
			return get_str_from_md5(hash);//newHash actually
		}
	};
}