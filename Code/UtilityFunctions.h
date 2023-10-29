#ifndef PROJETO_AED_UTILITYFUNCTIONS_H
#define PROJETO_AED_UTILITYFUNCTIONS_H

#include <cctype>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

char removeAccents(char c);
string ToLower(const string& input);
string floatToHours(float hours);
bool checkIfUCCodeEqual(string a, string b);
bool checkIfClassCodeEqual(string a, string b);
bool checkIfYearEqual(string a, string b);
void sortByCode(vector<pair<string, int>>& result, bool ascending);
void sortByOccupation(vector<pair<string, int>>& result, bool ascending);




#endif //PROJETO_AED_UTILITYFUNCTIONS_H
