#include "Source.h"
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
multimap <pair<int, char>, string> myMap1;

void Work() {
	myMap1.insert(pair <pair<int, char>, string>(pair<int, char>(0, 'a'), "d5"));
	auto rez = myMap1.find(pair<int, char>(0, 'a'));
	for(auto rez : myMap1) {
		cout  << rez.second;
	}
	ifstream myFile;
	int stop = 0;
	string N, T, S;
	multimap <string, string> M;

	fisiere(cale_fisier, myFile, N, T, S, M);
	cout << input << endl;
	while (input.find_first_of(N) != string::npos && stop < stop_derivari) {
		 //cout << derivareExtremDreapta(input, N, M) << endl;
		 cout << derivareExtremStanga(input, N, M) << endl;
		 stop++;
	}
	if (stop == stop_derivari) {
		cout << "\nProgramul a depasit numarul maxim de derivari: " << stop_derivari << endl;
	}
}

void fisiere(string cale, ifstream &myFile, string &N, string &T, string &S, multimap <string, string> &M) {
	string aux1, aux2;
	int nr_linii = 0;

	myFile.open(cale);
	nr_linii = count(istreambuf_iterator<char>(myFile), istreambuf_iterator<char>(), '\n') + 1;
	myFile.close();

	myFile.open(cale);
	iaLinie(myFile, N, nr_linii, "Neterminale: ");
	iaLinie(myFile, T, nr_linii, "Terminale: ");
	iaLinie(myFile, S, nr_linii, "Simbol Start: ");
	iaLinie(myFile, to_string(nr_linii), nr_linii, "Linii Ramase: ", true);
	cout << endl;

	while (nr_linii > 0) {
		getline(myFile, aux1, sep_key_prod);
		getline(myFile, aux2, sep_data_prod);
		M.insert(pair<string, string>(aux1, aux2));
		nr_linii--;
	}
	myFile.close();

	//Afisare productiile din multimap
	cout << "Productii: " << endl;
	for (auto elem : M) {
		cout << elem.first << " -> " << elem.second << endl;
	}
	cout << endl;
}
void iaLinie(ifstream &myFile, string &dest, int &nr_linii, string text, bool b) {
	if (!b) {
		getline(myFile, dest);
		nr_linii--;
	}
	cout << text << dest << endl;
}
string derivareExtremStanga(string &s, string &N, multimap <string, string> &M) {
	int poz = s.find_first_of(N);
	string conv = s.substr(poz, 1);
	deriveaza(s, poz, conv, M);
	return s;
}

string derivareExtremDreapta(string &s, string &N, multimap <string, string> &M) {
	int poz = s.find_last_of(N);
	string conv = s.substr(poz, 1);
	deriveaza(s, poz, conv, M);
	return s;
}

string deriveaza(string &s, int aux, string c, multimap <string, string> &M) {
	string temp_prod[10];
	int i = 0, contor = 0;
	auto ret = M.equal_range(c);
	for (auto it = ret.first; it != ret.second; ++it) {
		temp_prod[i++] = it->second;
		contor++;
	}
	int var = rand() % contor;
	cout <<"rand() = " << var << ": " << c << " -> " << temp_prod[var] << endl;

	&s.erase(aux,1);
	if (temp_prod[var] != "00") {
		&s.insert(aux, temp_prod[var]);
	}
	return s;
}

void teste(multimap <string, string> &M)
{
	//pair <multimap<string, string>::iterator, multimap<string, string>::iterator> ret;
	auto ret = M.equal_range("A");
	cout << "Productii pt A: ";
	for (multimap<string, string>::iterator it = ret.first; it != ret.second; ++it) {
		cout << it->second << " ";
	}
	cout << endl;
	ret = M.equal_range("B");
	cout << "Productii pt B: ";
	for (multimap<string, string>::iterator it = ret.first; it != ret.second; ++it) {
		cout << it->second << " ";
	}
	cout << endl;
	cout << endl;
}