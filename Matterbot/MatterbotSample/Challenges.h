#pragma once
#include "Matterbot.h"
#include "Md5Utilities.h"
#include "Header.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


namespace lospi {
	struct ChallengeCommand : ICommand {
		explicit ChallengeCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"challenges"; }

		std::wstring get_help() override { return L"`challenges[CMD]`: `challenges` gives the hashes\n'scraps' takes scraps."; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {


			std::string newhashes = wstring_to_string(command_text);
			auto length = newhashes.size();
			std::vector<std::string>hashVector;
			std::vector<std::string>passwordhashVector;
			std::vector<std::string>passwordVector;
			
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

			if(hashPassMap.empty())
			{
				for (passLength = 0; passLength <= 13; passLength++)
				{
					Combinator salt(alpha, passLength);
					while (salt.has_next())
					{
						auto combo = salt.next();
						std::string pass{ combo.begin(), combo.end() };
						pass.append("hjhs8q");
						auto size = pass.length();
						auto hash = pass.c_str();
						auto newHash = compute_md5(hash, size);
						std::wstring wkey = get_str_from_md5(newHash);
						std::string key = wstring_to_string(wkey);
						hashPassMap.emplace(key, pass);
					}
				}
			}
			
			std::wstring returnValue;

			for (int i = 0; i < hashVector.size(); i++)
			{
				auto elem = hashPassMap.find(hashVector[i]);
				if (elem != hashPassMap.end())
				{
					auto value = elem->second;
					std::wstring returnPass = string_to_wstring(value);
					returnValue += L" " + returnPass;
				}
			
			}
			bot->post_message(L"rivestment try" + returnValue);
			_sleep(2000);
			return L"rivestment challenge 150";


		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}