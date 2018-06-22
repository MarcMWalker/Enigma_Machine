#include "stdafx.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	const string alphabet{ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };
	string rotor_1{ "JNFTxIgRpakuXcbSBCmArYWZMhfDGlwizPKvyVjUtnQqLoeOHEds" };
	string rotor_2{ "tOsyZMHdiVRbpKolkFNqnzEWQwJjYcagLABSXmDuUPGxvIrhCTfe" };
	string rotor_3{ "UYexJSkKDIfXhjZOruHsaEcTCviPWGyFdMbQgRtwmNLlnBAoVqpz" };
	char letter{};
	int rotor_pos_1{ 0 };
	int rotor_pos_2{ 0 };
	int rotor_pos_3{ 0 };
	bool quit{ false };
	string the_message{ "" };
	string deciphered{};

	while (quit != true) {
		cout << "====================================================================================" << endl;
		if (the_message.length() > 0) {
			cout << "Your current message: " << endl;
			cout << the_message << endl;
			cout << "Length of Message: " << the_message.length() << endl;
		}
		else {
			cout << "Your current message: " << "[ Please enter a message ]" << endl;
			cout << endl;
			cout << "Length of Message: " << the_message.length() << endl;
		}
		cout << "====================================================================================" << endl;
		cout << endl;
		cout << "Welcome to the Enigma Machine, please select an option from the list below" << endl;
		cout << endl;
		cout << "Current rotor code: " << "[ " << rotor_pos_1 << " " << rotor_pos_2 << " " << rotor_pos_3 << " ]" << endl;
		cout << "C = Create new message" << endl;
		cout << "X = Delete current message" << endl;
		cout << "D = Decipher message ** MAKE SURE YOU HAVE THE RIGHT ROTOR CODE **" << endl;
		cout << "S = Change position of rotors" << endl;
		cout << "Q = Quit the Enigma program" << endl;
		cout << endl;
		cin >> letter;
		cout << endl;
		cout << "Option: " << letter;
		cout << endl;

		switch (letter) {
		case 'c':
		case 'C':
		{
			cin.ignore();
			cout << endl;
			cout << "Input message then press Enter on the keyboard:    ";
			getline(cin, the_message);
			cout << endl;
			break;
		}
		case 'd':
		case 'D':
		{
			for (char letter : the_message) {
				size_t position = alphabet.find(letter);
				if (position != string::npos && rotor_pos_1 < 52 && rotor_pos_2 < 52 && rotor_pos_3 < 52) {
					char new_char{ rotor_1.at(position) };
					char copy = rotor_1.at(0);
					new_char = rotor_1.at(position);
					for (char for_rotor_2 : alphabet) {
						size_t position_2 = rotor_1.find(for_rotor_2);
						new_char = rotor_2.at(position_2);
					}
					for (char for_rotor_3 : rotor_1) {
						size_t position_3 = rotor_2.find(for_rotor_3);
						new_char = rotor_3.at(position_3);
					}
					rotor_1.push_back(copy);
					rotor_1.erase(0, 1);
					rotor_pos_1++;
					deciphered += new_char;
				}
				else if (position != string::npos && rotor_pos_1 == 52 && rotor_pos_2 <= 52 && rotor_pos_3 <= 52) {
					char new_char = rotor_2.at(position);
					char copy = rotor_2.at(0);
					rotor_2.push_back(copy);
					rotor_2.erase(0, 1);
					rotor_pos_2++;
					deciphered += new_char;
					rotor_pos_1 = 0;
				}
				else if (position != string::npos && rotor_pos_1 == 52 && rotor_pos_2 == 52 && rotor_pos_3 < 52) {
					char new_char = rotor_3.at(position);
					char copy = rotor_3.at(0);
					rotor_3.push_back(copy);
					rotor_3.erase(0, 1);
					rotor_pos_3++;
					deciphered += new_char;
					rotor_pos_1 = 0;
					rotor_pos_2 = 0;
				}
				else if (position != string::npos && rotor_pos_1 == 52 && rotor_pos_2 == 52 && rotor_pos_3 == 52) {
					rotor_pos_1 = 0;
					rotor_pos_2 = 0;
					rotor_pos_3 = 0;
				}
				else {
					deciphered += letter;
				}
			}
			the_message = deciphered;
			break;
		}
		case 'x':
		case 'X':
		{
			if (the_message.length() > 0) {
				the_message = "";
				deciphered = "";
				cout << endl;
				cout << " " << "+++++++++++++++++++++++++++++++++++" << endl;
				cout << " " << "+      ***MESSAGE DELETED***" << "      +" << endl;
				cout << " " << "+++++++++++++++++++++++++++++++++++" << endl;
			}
			else {
				cout << endl;
			}
			break;
		}
		case 's':
		case 'S':
		{
			cout << "Enter combination for Enigma Machine: " << endl;
			cout << "Rotor 1: ";
			bool correct_num{ false };
			while (correct_num != true) {
				cin >> rotor_pos_1;
				if (rotor_pos_1 < 1 || rotor_pos_1 > 52)
					cout << "Please select a number between 1 and 52" << endl;
				else
					correct_num = true;
				int i{ 0 };
				while (i < rotor_pos_1) {
					char copy = rotor_1.at(0);
					rotor_1.push_back(copy);
					rotor_1.erase(0, 1);
					cout << rotor_1 << endl;
					i++;
				}
			}
			cout << "Rotor 2: ";
			correct_num = false;
			while (correct_num != true) {
				cin >> rotor_pos_2;
				if (rotor_pos_2 < 1 || rotor_pos_2 > 52)
					cout << "Please select a number between 1 and 52" << endl;
				else
					correct_num = true;
			}
			cout << "Rotor 3: ";
			correct_num = false;
			while (correct_num != true) {
				cin >> rotor_pos_3;
				if (rotor_pos_3 < 1 || rotor_pos_3 > 52)
					cout << "Please select a number between 1 and 52" << endl;
				else
					correct_num = true;
			}
			cout << "New combination: " << rotor_pos_1 << " " << rotor_pos_2 << " " << rotor_pos_3 << endl;
			break;
		}
		case 'q':
		case 'Q':
		{
			cout << endl;
			cout << " " << "+++++++++++++++++++++++++++++++++++" << endl;
			cout << " " << "+         ***GOODBYE***" << "           +" << endl;
			cout << " " << "+++++++++++++++++++++++++++++++++++" << endl;
			quit = true;
			break;
		}
		default:
			cout << "Enter one of the valid letters please" << endl;
		}
		cout << endl;
	}
	return 0;
}