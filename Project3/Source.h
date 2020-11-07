#pragma once
#include <iostream>
#include <map>

#define cale_fisier "Gramatica_3.txt"
#define input S
#define stop_derivari 60
#define sep_key_prod ','
#define sep_data_prod '\n'

using namespace std;

void Work();
void fisiere(string cale, ifstream &myFile, string &N, string &T, string &S, multimap <string, string> &M);
string deriveaza(string &s, int aux, string c, multimap <string, string> &M);
string derivareExtremStanga(string &s, string &N, multimap <string, string> &M);
string derivareExtremDreapta(string &s, string &N, multimap <string, string> &M);
void iaLinie(ifstream &myFile, string &dest, int &nr_linii, string text, bool b = false);
void teste(multimap <string, string> &M);