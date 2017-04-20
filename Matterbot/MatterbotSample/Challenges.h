#pragma once
#include "Matterbot.h"
#include <algorithm>
#include <vector>

namespace lospi {
	struct ChallengeCommand : ICommand {
		explicit ChallengeCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"challenge"; }

		std::wstring get_help() override { return L"`challenge[CMD]`: `challenge` gives the hashes\n 'try': trys different combos to guess password."; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {

			std::wstring hashes = command_text;
			auto length = hashes.length();
			std::vector<std::wstring>myVector;
			
			//std::wstring hashArray[255] = { 0 };
			//unsigned int i = hashes.find(L' ');
			int i = 0;
			int j = 0;

			for (i = 0; i < length - 1;)
			{
				std::wstring hash = hashes.substr(i, (i + 32));
				i += 32;
				myVector.push_back(hash);
			}
			
		
			//bot->post_message(myVector);
			//auto reversed{ command_text };
			//reverse(reversed.begin(), reversed.end());
			return L"bleh";
		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}
