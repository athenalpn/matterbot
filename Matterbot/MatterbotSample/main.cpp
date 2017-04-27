#include "Matterbot.h"
#include <iostream>
#include <sstream>
#include "ConsoleLogger.h"
#include "EchoCommand.h"
#include "ReverseCommand.h"
#include "WeatherCommand.h"
#include "StringPractice.h"
#include "MathCommand.h"
#include "Challenges.h"
#include "Header.h"





#define ERROR_SUCCESS 0
#define ERROR_FAILURE -1

using namespace std;
using namespace lospi;

int main() {
  wstring mattermost_url = L"https://hooks.slack.com",
    incoming_hook_route = L"services/T4Z1QAKSS/B4ZV7GNAF/hIzIxbyq7wyhgrQsajSpHCdp",
    outgoing_hook_route = L"http://127.0.0.1:8123",
    outgoing_hook_token = L"p7VcgLVdDRPXPGrNWIzkyI5E",
    welcome_message = L"bot is running, table is being built, please wait.";

  
  try {
    auto bot = make_shared<Matterbot>(mattermost_url, incoming_hook_route, outgoing_hook_route, outgoing_hook_token);
    bot->set_logger(make_unique<ConsoleLogger>());
    bot->register_command(make_shared<EchoCommand>());
	bot->register_command(make_shared<ChallengeCommand>(bot));
	bot->register_command(make_shared<MathCommand>());
	bot->register_command(make_shared<WeatherCommand>());
	bot->register_command(make_shared<StringCommand>());
    bot->register_command(make_shared<ReverseCommand>(bot));
    bot->post_message(welcome_message);
	
	//builds the table of hashes and passwords to compare
	
	std::string alpha = "hsoj";
	auto passLength = 0;

	if (hashPassMap.empty())
	{
		for (passLength = 0; passLength <= 13; passLength++)
		{
			Combinator salt(alpha, passLength);
			while (salt.has_next())
			{
				auto combo = salt.next();
				std::string pass{ combo.begin(), combo.end() };
				pass.append("nju6tc");
				auto size = pass.length();
				auto hash = pass.c_str();
				Md5Digest newHash = compute_md5(hash, size);
				hashPassMap.emplace(newHash, pass);
			}
		}
	}
	//posts when table is done being built
	bot->post_message(L"Table is complete.");

    wstring console;
    wclog << ">> Type \'quit\' to quit. Any other input will be sent to the bot." << endl;
    while (getline(wcin, console)) {
      if (L"quit" == console) {
        wclog << ">> Quitting." << endl;
        return ERROR_SUCCESS;
      }
      if (L"" != console) { bot->post_message(console); }
    }
  }
  catch (exception e) {
    wcerr << "[-] Unhandled exception:" << e.what() << endl;
    return ERROR_FAILURE;
  }
}
