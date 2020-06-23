// assignemnt_01.cpp : Defines the entry point for the console application.
//security Course 
// Author : Ali Abu Saleh
// Copyright © SCEADA Inc.

#include "stdafx.h"
#include<iostream>
#include <ctype.h> 
#include <string>
#include <algorithm>    // std::sort
using namespace std;
// this structure is used to freq analysis 
 struct letter_st {
	float value;
	char letter;
	
};
 char newtext[500];

 // get the position of a character in the array of structre
 int getposition(const letter_st *array, size_t size, char c)
 {
	 for (int i = 0; i < size; i++) {
		 if (array[i].letter == c) {
			 return i;
		 }
	 }
	 return -1;
 }
 // get the position of a character in the array 
 int getposition(const char*array, size_t size, char c)
 {
	 for (int i = 0; i < size; i++) {
		 if (array[i] == c) {
			 return i;
		 }
	 }
	 return -1;
 }

int main()
{
	int choose;
	int No1_type;
	char PlainText[100], ciphertext[100], freqtext[500], ciphere_v2[100];
	int Key_sub;
	while (true) {
		cout << "****\t\t Meun \t\t**** " << endl << "****\t Please Choose a Number to Enter \t****" << endl;
		cout << "\t 1. Simple Substitution Algorithm" << endl
			<< "\t 2. Least-Simple  Substitution Algorithm" << endl;
		cin >> choose; // Simple Substitution Algorithm
		
		if (choose == 1) { 
			// show the sub-menu to user 
			cout << "Please Choose The Oparation "<<endl
				<< "1. Encrypt" <<endl << "2. Decrypt" <<endl <<"3. Crack" <<endl;
			cin >> No1_type; // read the option 
			//encypt option
			if (No1_type == 1) {
				// show info and notes 
				cout << "Please Enter the Plain Text, then press Enter" << endl;
				cout << "Max character is 100, no white space allowed" << endl;
				cin >> PlainText; // get the plain text
				cout << "Please Enter the Key [1,26], then press Enter" << endl;
				cin >> Key_sub; // get the key 
				Key_sub = Key_sub % 26; // mod 26 so if he enter more than 26 it will work
				if (Key_sub == 0) { // no algorithm the statement still as the origin one 
					cout << "The Simple Substitution Algorithm requiers at least 1 as key" << endl;
				}
				else { // we have key 
					//print info to user 
					cout << "Operation : Simple Substitution Algorithm Encypt" << endl;
					cout << "Plain text :" << PlainText << "\t Key :  " << Key_sub << endl;
					cout << "The following steps is for encrypt"<<endl;
					//print the steps for the user
					for (int i = 0; i < strlen(PlainText); i++) {
							int newchar = (int) ((PlainText[i])); // get the char at position i
							newchar = newchar + Key_sub; // add the key to the user
							cout << "Step #" << i << ", " << PlainText[i] << " ---> "; // pritn to user some info
							if (newchar > 90) { // check if it exceds the upper limit 90 which is  > Z
								newchar = ((newchar % 90) + 64);
							}
							if (newchar == 90) { // if it's  Z 
								newchar = 65;
							}
							PlainText[i] = (char)newchar; // update the charaters
							cout << (char)(PlainText[i]) << endl; // print it to user 
						
						
					}
				}
				cout << "The Encrypted Statment is : " << PlainText <<endl << endl; // print the last statement at once

			}
			//decrypt section
			else if (No1_type == 2) { //decrypt
				cout << "Please Enter the Ciphertext, then press Enter" << endl;
				cout << "Max character is 100, no white space allowed" << endl;
				cin >> ciphertext;
				cout << "Please Enter the Key [1,26], then press Enter" << endl;
				cin >> Key_sub;
				Key_sub = Key_sub % 26;
				if (Key_sub == 0) {
					cout << "The Simple Substitution Algorithm requiers at least 1 as key" << endl;
				}
				else {
					cout << "Operation : Simple Substitution Algorithm Decrypt" << endl;
					cout << "Ciphertext :" << ciphertext << "\t Key :  " << Key_sub << endl;
					cout << "The following steps is for Decrypt" << endl;
					cout << "length " << strlen(ciphertext) << endl;
					for (int i = 0; i < strlen(ciphertext); i++) {
							int newchar = (int)((ciphertext[i]));
							newchar = newchar - Key_sub;
							cout << "Step #" << i << ", " << ciphertext[i] << " ---> ";
							if (newchar < 64) {
								newchar = (90 -(65- newchar) );
							}
							else if (newchar == 64) {
								newchar = 90;
							}
							ciphertext[i] = (char)newchar;
							cout << (char)(ciphertext[i]) << endl;
						
						
					}
				}
				cout << "The Encrypted Statment is : " << ciphertext << endl << endl;
			}
			//crack option
			else if (No1_type == 3) {
				cout << "Please Enter the Ciphertext, then press Enter" << endl;
				cout << "Max character is 100, no white space allowed" << endl;
				cin >> ciphere_v2;
				int len = strlen(ciphere_v2);
				for (int ss = 1; ss < 27; ss++) {
					strncpy_s(ciphertext, ciphere_v2, len);
					Key_sub = ss;
						for (int i = 0; i < strlen(ciphertext); i++) {
							int newchar = (int)((ciphertext[i]));
							newchar = newchar - Key_sub;
							
							if (newchar < 64) {
								newchar = (90 - (65 - newchar));
							}
							if (newchar == 64) {
								newchar = 90;
							}
							ciphertext[i] = (char)newchar;
							


						}
					
					cout << "If the Key is : " << ss << " \tThe exprected Statment is " << ciphertext << endl;

				}
			}
			else {
				cout << "Unkown Choose, please Try again" <<endl;
			}
		}
		//Least-Simple  Substitution Algorithm
		else if (choose == 2) {
			int type = 0;
			cout << "Please Choose The Oparation " << endl
				<< "1. Encrypt" << endl << "2. Decrypt *I did it to test my code*" << endl;
			cin >> type;
			// decrypt analysis
			if (type == 2){
				// show info to user 
				cout << "**********\t Least-Simple  Substitution Algorithm Deryption \t********** " << endl << endl;
			cout << "Please Enter the Ciphertext try to find the text using English letter frequency analysis, then press Enter " << endl <<
				"Notes: " << endl << "*Max 500 character is allowed" << endl << "\*No space is allowed*" << endl;
			cin >> freqtext;
			cout << "\t**** Algorithm :Least-Simple  Substitution Algorithm **** \n \t**** using letter frequency analysis ****\n " << endl;
			cout << "Computing the Count for each letter as follows" << endl;
			int count = 0;
			int totalcount = 0;
			int ii;
			int jj = 0;
			letter_st freq[26];
			for (int j = 65; j <= 90; j++) {
				count = 0;
				cout << "Letter " << (char)(j) << " Counts: ";
				for (ii = 0; ii < strlen(freqtext); ii++) {
					if (freqtext[ii] == ((char)j)) {
						count++;
					}
				}
				freq[jj].value = (float)count / strlen(freqtext); // the number of letter occures divided by total number of letters
				freq[jj].letter = (char)(j); // save the latter with it's frequency 
				// print this array to the user
				cout << count << "\t freq =" << freq[jj].value << endl;
				jj++;
			}
			//show info to user
			cout << "using the letter frequency analysis, sort the letters according to the frequecy" << endl;

			//sort the array according to the letters freq. using insertion sort 
			letter_st temp;
			for (int i = 1; i < 26; i++) {
				if (freq[i].value < freq[i - 1].value) {
					for (int k = i; (k >= 1) && (freq[k].value < freq[k - 1].value); k--) {

						temp.value = freq[k - 1].value;
						temp.letter = freq[k - 1].letter;
						freq[k - 1].value = freq[k].value;
						freq[k - 1].letter = freq[k].letter;
						freq[k].value = temp.value;
						freq[k].letter = temp.letter;

					}
				}
			}
			// end of insertion sort 

			// after this step, freq[26] has the most frequent letter and freq [0] has lowest frequent

			// reverse the array 
			int l = 25;  // now l will point to the last element
			int f = 0;   //  and f will be point to the first element
			while (f < l) // point to button and to head and replace these 2 items until you reach the middle 
			{
				temp.value = freq[f].value;
				temp.letter = freq[f].letter;
				freq[f].value = freq[l].value;
				freq[f].letter = freq[l].letter;
				freq[l].value = temp.value;
				freq[l].letter = temp.letter;
				f++;
				l--;
			}
			// after this step freq[0] has most frequent 
			strncpy_s(newtext, freqtext, 500);
			string newstatement = ""; // to concatenate the output and disable it at once
			// this array is sorted in the most frequent letters ( from the given source)
			char mostfreq[26] = { 'E','T','A','I','O','N','S','R','H','D','L','U','C','M','F','Y','W','G','P','B','V','K','X','Q','J','Z' };
			// show the analysis with every step and evey letter it replaced with what.
			for (int i = 0; i < strlen(newtext); i++) {
				char let = newtext[i];
				cout << "Letter is " << let;
				int pos = getposition(freq, 26, let);
				cout << ", position in freq array is " << pos;
				//cout << mostfreq[pos];
				cout << " ,replace with " << mostfreq[pos] << endl;
				newstatement += mostfreq[pos];
			}
			// print the statement at once 
			cout << "The expected Statement is : \n " << newstatement << endl;

		}
			//encrypt analysis
			else if (type == 1) {
				cout << "**********\t Least-Simple  Substitution Algorithm Encryption \t********** " << endl << endl;
				cout << "Please Enter the Plaintext to analyise using English letter frequency analysis, then press Enter " << endl <<
					"Notes: " << endl << "*Max 500 character is allowed" << endl << "\*No space is allowed*" << endl;
				cin >> freqtext;
				char mostfreq[26] = { 'E','T','A','I','O','N','S','R','H','D','L','U','C','M','F','Y','W','G','P','B','V','K','X','Q','J','Z' };
				cout << "The letter frequency analysis is based on the following table" << endl;
				cout << "****************\t******************\t******************" << endl;
				cout << "   Letter : ";
				for (int i = 0; i < 26; i++) {
					cout << (char)mostfreq[i] << "   \t";
				}
				cout << endl<< "Frequency : ";
				float most_value[26] = { 12.02,9.10,8.12,7.68,7.31,6.95,6.28,6.02,5.92,4.32,4.98,2.88,2.71,2.61,2.30,2.11,2.09,2.03,1.82,1.49,1.11,0.69,0.17,0.11,0.10,0.07 };
				for (int i = 0; i < 26; i++) {
					cout << most_value[i] << "\t";
				}
				cout << endl;
				cout << "My algorithm will replace the letter as this (asending) according to Frequency array" << endl;
				char encypt_array[26] = { 'J','I','C','A','X','S','E','Y','V','D','K','W','B','Q','T','Z','R','H','F','M','P','N','U','L','G','O' };
				for (int i = 0; i < 26; i++) {
					cout << encypt_array[i] << "\t";
				}
				cout << endl << " \t \t******** Analysis ********\t t\ " << endl;
				int count = 0;
				int totalcount = 0;
				int ii;
				int jj = 0;
				letter_st freq[26];
				for (int j = 65; j <= 90; j++) {
					count = 0;
					cout << "Letter " << (char)(j) << " Counts: ";
					for (ii = 0; ii < strlen(freqtext); ii++) {
						if (freqtext[ii] == ((char)j)) {
							count++;
						}
					}
					freq[jj].value = (float)count / strlen(freqtext); // the number of letter occures divided by total number of letters
					freq[jj].letter = (char)(j); // save the latter with it's frequency 
												 // print this array to the user
					cout << count << "\t freq =" << freq[jj].value << endl;
					jj++;
				}
				//show info to user
				cout << "using the letter frequency analysis array , sort the letters according to the frequecy" << endl;

				//sort the array according to the letters freq. using insertion sort 
				letter_st temp;
				for (int i = 1; i < 26; i++) {
					if (freq[i].value < freq[i - 1].value) {
						for (int k = i; (k >= 1) && (freq[k].value < freq[k - 1].value); k--) {

							temp.value = freq[k - 1].value;
							temp.letter = freq[k - 1].letter;
							freq[k - 1].value = freq[k].value;
							freq[k - 1].letter = freq[k].letter;
							freq[k].value = temp.value;
							freq[k].letter = temp.letter;

						}
					}
				}
				// end of insertion sort 

				// after this step, freq[26] has the most frequent letter and freq [0] has lowest frequent

				// reverse the array 
				int l = 25;  // now l will point to the last element
				int f = 0;   //  and f will be point to the first element
				while (f < l) // point to button and to head and replace these 2 items until you reach the middle 
				{
					temp.value = freq[f].value;
					temp.letter = freq[f].letter;
					freq[f].value = freq[l].value;
					freq[f].letter = freq[l].letter;
					freq[l].value = temp.value;
					freq[l].letter = temp.letter;
					f++;
					l--;
				}
				cout << "The asending order of frequency is ( High to Low)" << endl;
				for (int i = 0; i < 26; i++) {
					cout << "Letter at position " << i << "is :" << freq[i].letter << endl;
				}
				// after this step freq[0] has most frequent 
				strncpy_s(newtext, freqtext, 500);
				string newstatement = ""; // to concatenate the output and disable it at once
										  // this array is sorted in the most frequent letters ( from the given source)
			//char mostfreq[26] = { 'E','T','A','I','O','N','S','R','H','D','L','U','C','M','F','Y','W','G','P','B','V','K','X','Q','J','Z' };
				// show the analysis with every step and evey letter it replaced with what.
				for (int i = 0; i < strlen(newtext); i++) {
					char let = newtext[i];
					cout << "Letter is " << let;
					int pos = getposition(freq, 26, let);
					cout << ", position in freq array is " << pos;
					//cout << mostfreq[pos];
					cout << " ,replace with " << encypt_array[pos] << endl;
					newstatement += encypt_array[pos];
				}
				// print the statement at once 
				cout << "The Encrypted Statement is : \n " << newstatement << endl;

			}
			else {
				cout << "Unknown Operation, Please try again!" << endl;
			}

			
		} // unkown option
		else {
			cout << "Unknown Algorithm, please try again!";
		}
	}
    return 0;
}


