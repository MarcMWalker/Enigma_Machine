
#include "stdafx.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

string change_rotors(int &rotor_pos_1, int &rotor_pos_2, int &rotor_pos_3, string &rotor_1, string &rotor_2, string &rotor_3, const string &original_rotor_1, const string &original_rotor_2, const string &original_rotor_3);
bool quit_program(bool &quit);
void delete_message(string &the_message);
void main_menu(string &the_message, int &rotor_pos_1, int &rotor_pos_2, int &rotor_pos_3, char letter);
char letter_to_uppercase();
string create_message(string &the_message);
string encrypt_message(string &the_message, string &rotor_1, string &rotor_2, string &rotor_3, int &rotor_pos_1, int &rotor_pos_2, int &rotor_pos_3, const string original_rotor_1, const string original_rotor_2, const string original_rotor_3);
string decrypt_message(string &the_message, string &rotor_1, string &rotor_2, string &rotor_3, int &rotor_pos_1, int &rotor_pos_2, int &rotor_pos_3, const string original_rotor_1, const string original_rotor_2, const string original_rotor_3);

int main()
{
	//76 characters
	const string original_rotor_1{ "CTr9Y+k!_(LlzSn6Bt3DdGf^Js=q1I o0NUj8cE7&g)HiOeRw2WAbQ$pV*h-%xyXF?Z5PMuvma4K" };
	const string original_rotor_2{ "a+?A3uNfQTKnVgD$F6P^yw1kB9Cqs)Hcl!-MRdZ%x5*t8Lp0S7vr=eIJhzjGW_X&i4m 2O(EUboY" };
	const string original_rotor_3{ "EG)sQn&IfRJ +cp%?m(iPdgb!wlqzLHSW-xAK54v3aFBrDyUet9o18kMVYj^Th$*7OXZ=26_0NCu" };
	string rotor_1{ "CTr9Y+k!_(LlzSn6Bt3DdGf^Js=q1I o0NUj8cE7&g)HiOeRw2WAbQ$pV*h-%xyXF?Z5PMuvma4K" };
	string rotor_2{ "a+?A3uNfQTKnVgD$F6P^yw1kB9Cqs)Hcl!-MRdZ%x5*t8Lp0S7vr=eIJhzjGW_X&i4m 2O(EUboY" };
	string rotor_3{ "EG)sQn&IfRJ +cp%?m(iPdgb!wlqzLHSW-xAK54v3aFBrDyUet9o18kMVYj^Th$*7OXZ=26_0NCu" };
	char letter{};
	int rotor_pos_1{ 1 };
	int rotor_pos_2{ 1 };
	int rotor_pos_3{ 1 };
	bool quit{ false };
	string the_message{ "" };

	while (quit != true) {
		cout << rotor_1 << endl;
		cout << rotor_2 << endl;
		cout << rotor_3 << endl;
		main_menu(the_message, rotor_pos_1, rotor_pos_2, rotor_pos_3, letter);
		letter = letter_to_uppercase();

		switch (letter) {
		case 'C':
		{
			create_message(the_message);
			break;
		}
		case 'E':
		{
			encrypt_message(the_message, rotor_1, rotor_2, rotor_3, rotor_pos_1, rotor_pos_2, rotor_pos_3, original_rotor_1, original_rotor_2, original_rotor_3);
			break;
		}
		case 'X':
		{
			delete_message(the_message);
			break;
		}
		case 'S':
		{
			change_rotors(rotor_pos_1, rotor_pos_2, rotor_pos_3, rotor_1, rotor_2, rotor_3, original_rotor_1, original_rotor_2, original_rotor_3);
			break;
		}

		case 'D':
		{
			decrypt_message(the_message, rotor_1, rotor_2, rotor_3, rotor_pos_1, rotor_pos_2, rotor_pos_3, original_rotor_1, original_rotor_2, original_rotor_3);
			break;
		
		}
		case 'Q':
		{
			quit_program(quit);
			break;
		}
		default:
			cout << "Enter one of the valid letters please" << endl;
		}
		cout << endl;
	}
	return 0;
}

char letter_to_uppercase() {
	char letter{};
	cin >> letter;
	return toupper(letter);
}

string create_message(string &the_message) {
	cin.ignore();
	cout << endl;
	cout << "Input message then press Enter on the keyboard:    ";
	getline(cin, the_message);
	cout << endl;
	return the_message;
}

string encrypt_message(string &the_message, string &rotor_1, string &rotor_2, string &rotor_3, int &rotor_pos_1, int &rotor_pos_2, int &rotor_pos_3, const string original_rotor_1, const string original_rotor_2, const string original_rotor_3) {
	
	string encrypt{};
	const string alphabet{ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?$%^&*()_+=- " };
	string copy_rotor_1{};
	string copy_rotor_2{};
	string copy_rotor_3{};

	for (char letter : the_message) {
		size_t position = alphabet.find(letter);
		if (position != string::npos && rotor_pos_1 < 75) {
			char new_char{ rotor_1.at(position) };
			char copy = rotor_1.at(0);
			new_char = rotor_3.at(position);

			/*
			for (char for_rotor_2 : alphabet) {
				size_t position_2 = rotor_1.find(for_rotor_2);
				new_char = rotor_2.at(position_2);
			}
			for (char for_rotor_3 : rotor_1) {
				size_t position_3 = rotor_2.find(for_rotor_3);
				new_char = rotor_3.at(position_3);
			}*/
			rotor_1.push_back(copy);
			rotor_1.erase(0, 1);
			copy_rotor_1 == rotor_1;
			rotor_pos_1++;
			encrypt += new_char;
		}
		else if (position != string::npos && rotor_pos_1 == 75 && rotor_pos_2 < 75) {
			char new_char = rotor_2.at(position);
			char copy = rotor_2.at(0);
			rotor_2.push_back(copy);
			rotor_2.erase(0, 1);
			copy_rotor_1 == rotor_1;
			copy_rotor_2 == rotor_2;
			rotor_pos_2++;
			encrypt += new_char;
			rotor_pos_1 = 1;
		}
		else if (position != string::npos && rotor_pos_2 == 75 && rotor_pos_3 < 75) {
			char new_char = rotor_3.at(position);
			char copy = rotor_3.at(0);
			rotor_3.push_back(copy);
			rotor_3.erase(0, 1);
			copy_rotor_1 == rotor_1;
			copy_rotor_2 == rotor_2;
			copy_rotor_3 == rotor_3;
			rotor_pos_3++;
			encrypt += new_char;
			rotor_pos_1 = 1;
			rotor_pos_2 = 1;
		}
		else if (position != string::npos && rotor_pos_3 == 75) {
			rotor_pos_1 = 1;
			rotor_pos_2 = 1;
			rotor_pos_3 = 1;
			original_rotor_1 == rotor_1;
			original_rotor_2 == rotor_2;
			original_rotor_3 == rotor_3;
		}
		else {
			encrypt += letter;
		}
	}

	rotor_1 == copy_rotor_1;
	rotor_2 == copy_rotor_2;
	rotor_3 == copy_rotor_3;
	the_message = encrypt;
	return the_message, rotor_1, rotor_2, rotor_3;
}

void delete_message(string &the_message) {
	if (the_message.length() > 0) {
		the_message = "";
		cout << endl;
		cout << " " << "+++++++++++++++++++++++++++++++++++" << endl;
		cout << " " << "+      ***MESSAGE DELETED***" << "      +" << endl;
		cout << " " << "+++++++++++++++++++++++++++++++++++" << endl;
	}
	else {
		cout << endl;
		cout << "There is no message to be deleted!" << endl;
	}
}

string change_rotors(int &rotor_pos_1, int &rotor_pos_2, int &rotor_pos_3, string &rotor_1, string &rotor_2, string &rotor_3, const string &original_rotor_1, const string &original_rotor_2, const string &original_rotor_3) {
	rotor_1 = original_rotor_1;
	rotor_2 = original_rotor_2;
	rotor_3 = original_rotor_3;
	int copy_pos{};
	string copy_rotor{};
	cout << "Enter combination for Enigma Machine: " << endl;
	cout << "Rotor 1: ";
	bool correct_num{ false };
	while (correct_num != true) {
		cin >> rotor_pos_1;
		copy_pos = rotor_pos_1;
		cout << rotor_pos_1 << endl;
		if (rotor_pos_1 < 1 || rotor_pos_1 > 75)
			cout << "Please select a number between 1 and 52" << endl;
		else {
			if (rotor_pos_1 = 1) {
				correct_num = true;
				rotor_1 = original_rotor_1;
				copy_rotor = rotor_1;
			}
			else
				correct_num = true;
			int i1{ 0 };
			while (i1 < copy_pos-1) {
				char copy = rotor_1.at(0);
				rotor_1.push_back(copy);
				rotor_1.erase(0, 1);
				i1++;
				cout << rotor_1 << endl;
				copy_rotor = rotor_1;
				cout << copy_rotor << endl;
			}
		}
	}
	rotor_pos_1 = copy_pos;
	rotor_1 == copy_rotor;
	
	cout << "Rotor 2: ";
	correct_num = false;
	while (correct_num != true) {
		cin >> rotor_pos_2;
		copy_pos = rotor_pos_2;
		cout << rotor_pos_2 << endl;
		if (rotor_pos_2 < 1 || rotor_pos_2 > 75)
			cout << "Please select a number between 1 and 52" << endl;
		else {
			if (rotor_pos_2 = 1) {
				correct_num = true;
				rotor_2 = original_rotor_2;
				copy_rotor = rotor_2;
			}
			else
				correct_num = true;
			int i2{ 0 };
			while (i2 < copy_pos-1) {
				char copy = rotor_2.at(0);
				rotor_2.push_back(copy);
				rotor_2.erase(0, 1);
				i2++;
				cout << rotor_2 << endl;
				copy_rotor = rotor_2;
				cout << copy_rotor << endl;
			}
		}
	}
	rotor_pos_2 = copy_pos;
	rotor_2 == copy_rotor;

	cout << "Rotor 3: ";
	correct_num = false;
	while (correct_num != true) {
		cin >> rotor_pos_3;
		copy_pos = rotor_pos_3;
		cout << rotor_pos_3 << endl;
		if (rotor_pos_3 < 1 || rotor_pos_3 > 75)
			cout << "Please select a number between 1 and 52" << endl;
		else {
			if (rotor_pos_3 = 1) {
				correct_num = true;
				rotor_3 = original_rotor_3;
				copy_rotor = rotor_3;
			}
			else
				correct_num = true;
			int i3{ 0 };
			while (i3 < copy_pos-1) {
				char copy = rotor_3.at(0);
				rotor_3.push_back(copy);
				rotor_3.erase(0, 1);
				i3++;
				cout << rotor_3 << endl;
				copy_rotor = rotor_3;
				cout << copy_rotor << endl;
			}
		}
	}
	rotor_pos_3 = copy_pos;
	rotor_3 == copy_rotor;
	cout << "New combination: " << rotor_pos_1 << " " << rotor_pos_2 << " " << rotor_pos_3 << endl;
	return rotor_1, rotor_2, rotor_3;
}

bool quit_program(bool &quit) {
	cout << endl;
	cout << " " << "+++++++++++++++++++++++++++++++++++" << endl;
	cout << " " << "+         ***GOODBYE***" << "           +" << endl;
	cout << " " << "+++++++++++++++++++++++++++++++++++" << endl;
	quit = true;
	return quit;
}

void main_menu(string &the_message, int &rotor_pos_1, int &rotor_pos_2, int &rotor_pos_3, char letter) {
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
	cout << "E = Encrypt message" << endl;
	cout << "S = Change position of rotors" << endl;
	cout << "D = Decrypt message ** MAKE SURE YOU HAVE THE RIGHT ROTOR CODE **" << endl;
	cout << "Q = Quit the Enigma program" << endl;
	cout << endl;
	cout << endl;

}

/*Beta stage, should just be able to go from the location from rotor_3 straight to 
where that is in the alphabet so having no need to go through all the other rotors */
string decrypt_message(string &the_message, string &rotor_1, string &rotor_2, string &rotor_3, int &rotor_pos_1, int &rotor_pos_2, int &rotor_pos_3, const string original_rotor_1, const string original_rotor_2, const string original_rotor_3) {
	string deciphered{};
	const string alphabet{ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?$%^&*()_+=- " };
	string copy_rotor_1{};
	string copy_rotor_2{};
	string copy_rotor_3{};
	for (char letter : the_message) {
		size_t position = rotor_3.find(letter);

		if (position != string::npos && rotor_pos_1 < 75) {
			char new_char{ alphabet.at(position) };
			char copy = rotor_1.at(0);

			/*for (char for_rotor_2 : alphabet) {
				size_t position_2 = rotor_1.find(for_rotor_2);
				new_char = rotor_2.at(position_2);
			}
			for (char for_rotor_3 : rotor_1) {
				size_t position_3 = rotor_2.find(for_rotor_3);
				new_char = rotor_3.at(position_3);
			}*/
			rotor_1.push_back(copy);
			rotor_1.erase(0, 1);
			copy_rotor_1 == rotor_1;
			rotor_pos_1++;
			deciphered += new_char;
		}
		else if (position != string::npos && rotor_pos_1 == 75 && rotor_pos_2 < 75) {
			char new_char = alphabet.at(position);
			char copy = rotor_2.at(0);
			rotor_2.push_back(copy);
			rotor_2.erase(0, 1);
			copy_rotor_1 == rotor_1;
			copy_rotor_2 == rotor_2;
			rotor_pos_2++;
			deciphered += new_char;
			rotor_pos_1 = 1;
		}
		else if (position != string::npos && rotor_pos_2 == 75 && rotor_pos_3 < 75) {
			char new_char = alphabet.at(position);
			char copy = rotor_3.at(0);
			rotor_3.push_back(copy);
			rotor_3.erase(0, 1);
			copy_rotor_1 == rotor_1;
			copy_rotor_2 == rotor_2;
			copy_rotor_3 == rotor_3;
			rotor_pos_3++;
			deciphered += new_char;
			rotor_pos_1 = 1;
			rotor_pos_2 = 1;
		}
		else if (position != string::npos && rotor_pos_3 == 75) {
			rotor_pos_1 = 1;
			rotor_pos_2 = 1;
			rotor_pos_3 = 1;
			copy_rotor_1 == original_rotor_1;
			copy_rotor_2 == original_rotor_2;
			copy_rotor_3 == original_rotor_3;
		}
		else {
			deciphered += letter;
		}
	}
	rotor_1 == copy_rotor_1;
	rotor_2 == copy_rotor_2;
	rotor_3 == copy_rotor_3;
	
	the_message = deciphered;
	return the_message, rotor_1, rotor_2, rotor_3;
}
