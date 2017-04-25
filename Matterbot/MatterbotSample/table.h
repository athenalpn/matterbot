#pragma once
#include "Matterbot.h"
#include "Md5Utilities.h"
#include "Challenges.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


namespace lospi {
	struct TableCommand : ICommand {
		explicit TableCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"table"; }

		std::wstring get_help() override { return L"`table[CMD]`: `table` gives the hashes."; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {


			std::string newhashes = wstring_to_string(command_text);
			auto length = newhashes.size();
			std::vector<std::string>hashVector;
			std::vector<std::string>passwordhashVector;
			std::vector<std::string>passwordVector;
			std::map<std::string, std::string>hashPassMap;
			std::wstring returnPass;

			auto i = 0;

			for (i = 0; i < length;)
			{
				auto hash = newhashes.substr(i, 32);
				i += 33;
				hashVector.emplace_back(hash);
			}

			std::string alpha = "hsoj";
			auto passLength = 0;

			for (passLength = 0; passLength <= 10; passLength++)
			{
				Combinator salt(alpha, passLength);
				while (salt.has_next())
				{
					auto combo = salt.next();
					std::string pass{ combo.begin(), combo.end() };
					pass.append("xb2sxp");
					auto size = pass.length();
					auto hash = pass.c_str();
					auto newHash = compute_md5(hash, size);
					std::wstring wkey = get_str_from_md5(newHash);
					std::string key = wstring_to_string(wkey);
					hashPassMap.emplace(key, pass);
				}
			}

			for (int i = 0; i < hashVector.size(); i++)
			{
				auto elem = hashPassMap.find(hashVector[i]);
				auto key = elem->first;
				auto value = elem->second;
				if (hashVector[i] == key)
				{

					returnPass += L" " + string_to_wstring(value);

				}
			}
			bot->post_message(L"rivestment try" + returnPass);
			_sleep(10);
			return L"rivestment challenge";


		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}