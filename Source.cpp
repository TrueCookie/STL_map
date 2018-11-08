#include <iostream>
#include <Windows.h>
#include <map>
#include <string>
#include <conio.h>
#include <limits.h>
#include <fstream>

void translate(std::map <std::string, std::string> &some_map);
void add_word(std::map <std::string, std::string> &some_map, std::string input_first);
bool add_word_input(std::string &str);
void fromFile(std::map <std::string, std::string> &some_map);
void inFile(std::map <std::string, std::string> some_map);
void outlet(std::map <std::string, std::string> some_map);

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::map<std::string, std::string> dict;

	fromFile(dict);

	while (1) {
		translate(dict);
	}

	_getch();
	return 0;
}

void translate( std::map <std::string, std::string> &some_map) {
	std::cout << ">";
	std::string input_first;
	std::getline(std::cin, input_first, '\n');	//std::cin >> input_first;

	if (input_first == "...") {
		outlet(some_map);
	}

	if (some_map.find(input_first) != some_map.end()) {
		std::cout << some_map.find(input_first)->second;
	}else {
		std::cout << "Данного слова нет в словаре. Введите перевод или 0 для отказа: " << std::endl;
		add_word(some_map, input_first);
	}
	std::cout << std::endl;
}

void add_word(std::map <std::string, std::string> &some_map, std::string input_first) {
	std::cout << ">";
	std::string input_scd;

	//std::cin >> input_scd;
	if(add_word_input(input_scd) == 1){
		some_map.insert({ input_first, input_scd });
		std::cout << "Слово занесено в словарь";
	}
}

bool add_word_input(std::string &str){
	char frst = 'x';
	//std::cin.ignore(1);
		frst = getchar();
	if (frst != '0') {
		std::string str2;
		str = frst;
		std::getline(std::cin, str2, '\n');	//std::cin >> str2;
		str = str + str2;
		return 1;
	}else if(frst == '0'){
		std::cout << "Ввод пропущен";
		return 0;
	}
}

void fromFile(std::map <std::string, std::string> &some_map) {
	std::fstream in;
	in.open("Dictionary.txt");
	
	if (!in) {
		std::cout << "ERROR: no such file or directory " << std::endl;
	}
	std::string input_first;
	std::string input_scd;

	while (in >> input_first >> input_scd) {
		some_map.insert({ input_first, input_scd });
	}
	in.close();
}

void inFile(std::map <std::string, std::string> some_map) {
	std::ofstream out;
		out.open("Dictionary.txt", std::ios::out);

	if (!out) {
		std::cout << "ERROR: no such file or directory" << std::endl;
	}

	for (auto it = some_map.begin(); it != some_map.end(); ++it){		//уролесан в капсулах
		out << (*it).first << " " << (*it).second << std::endl;
	}
	
	out.close();
}

void outlet(std::map <std::string, std::string> some_map){
	std::string save;
	std::cout << "Хотите сохранить изменения в файле? ( y-да / n-нет ): ";
	std::cin >> save;
	if (save == "y") {
		inFile(some_map);
	}
	TerminateProcess(GetCurrentProcess(), 0);
}