#include "Table.h"



void Table::ReadFile(std::string f_name)
{
	std::ifstream fin(f_name);
	if (fin.is_open()) {
		std::string buffer;
		std::string word;
		while (std::getline(fin, buffer)) {
			for (char& c : buffer) {
				if (IsLegal(c)) {
					word.push_back(c);
				}
				else {
					if (word != "") {
						not_sorted_words[word]++;
						count++;
						word.clear();
					}
				}
			}
			if (word != "") {
				not_sorted_words[word]++;
				count++;
				word.clear();
			}
		}
	}
	else {
		std::cout << "Error: can't open input file.";
	}
}

void Table::PrintFile(std::string o_name )
{
	
	std::ofstream myfile;
	myfile.open(o_name);
	std::pair<int, std::string> buf;
	std::list<std::pair<int, std::string>> sorted_words;
	for (const auto& p : not_sorted_words) {
		buf.first = p.second;
		buf.second = p.first;
		sorted_words.push_back(buf);
	}
	sorted_words.sort();
	sorted_words.reverse();
	std::list<std::pair<int, std::string>>::iterator it;
	for (it = sorted_words.begin(); it != sorted_words.end(); ++it) {
		myfile << "\"" << it->second << "\", " << it->first << ", " << it->first*100 / count << "%\n";
	}
	myfile.close();
}
