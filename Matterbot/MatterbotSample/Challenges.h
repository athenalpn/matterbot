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


			auto length = command_text.size();
			std::vector<Md5Digest>hashVector;
			std::wstring returnPass;
			std::wstring returnValue;

		
			//takes the hashes given by rivestment and stores them in a vector for comparison later
			for (auto i = 0; i < length;)
			{
				auto hash = command_text.substr(i, 32);
				hashVector.emplace_back(get_md5_from_str(hash));
				i += 33;
			}

			
			//compares the values in rivestment vector with the keys in map, than gives back the password for the matching hashes
			for (int i = 0; i < hashVector.size(); i++)
			{
				auto elem = hashPassMap.find(hashVector[i]);
				if (elem != hashPassMap.end())
				{
					auto value = elem->second;
					returnPass = string_to_wstring(value);
					returnValue += L" " + returnPass;
				}
			
			}
			bot->post_message(L"rivestment try" + returnValue);

			//loops every second to get more challenges
			_sleep(1500);
			return L"rivestment challenge 50";


		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}