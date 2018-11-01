#include <iostream>
#include <Windows.h>
#include <map>
#include <string>
#include <conio.h>

void translate(std::map <std::string, std::string> &some_map);
void add_word(std::map <std::string, std::string> &some_map, std::string input_first);

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::map<std::string, std::string> dict = { {"sugar", "сахар"},
													 {"cat", "кот"},
													 {"bridge", "мост"},
													 {"hello", "привет"} };

	while (1) {
		translate(dict);
	}

	_getch();
	return 0;
}

void translate( std::map <std::string, std::string> &some_map) {
	std::cout << ">";
	std::string input_first;
	std::cin >> input_first;

	if (some_map.find(input_first) != some_map.end()) {
		std::cout << some_map.find(input_first)->second;
	}else {
		std::cout << "ƒанного слова нет в словаре. ¬ведите перевод или 0 дл€ отказа: " << std::endl;
		add_word(some_map, input_first);
	}
	std::cout << std::endl;
}

void add_word(std::map <std::string, std::string> &some_map, std::string input_first) {
	std::cout << ">";
	std::string input_scd;

	std::cin >> input_scd;
	if(input_scd != "0"){
		some_map.insert({ input_first, input_scd });
		std::cout << "OK";
	}
}