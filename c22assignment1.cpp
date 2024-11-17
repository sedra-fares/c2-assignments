#include <iostream>
#include<string.h>

void readName(char**p,int x);
void sortName(char** p, int x);
void displayName(char** p, int x);
void sortLength(char**p, int x);
void search(char** p,char* z,int x );
void capitalizeNames(char**p, int x);
void longestName(char** p, int x);
void shortestName(char** p, int x);
void largestNumOf(char** p, int x);
void deleteNames(char** p, int x);
void choices();

using namespace std;

int main() {

	char** names = NULL;
	int count=0;
	cout << endl<<"enter the number of names: ";
	cin >> count;
	names = new char* [count];
	for (int i = 0; i < count; i++) {
		names[i] = new char[100];
	
	}
	readName(names, count);
	choices();
	for (int i = 0;i<10; i++) {
		
		int choice=0;
		cin >> choice;
		if (choice == 1 && names != nullptr) {
			sortName(names, count);
			displayName(names, count);
		}
		else if (choice == 2 && names != nullptr) {
			sortLength(names, count);
			displayName(names, count);
		}
		else if (choice == 3 && names != nullptr) {
			largestNumOf(names, count);
		}
		else if (choice == 4 && names != nullptr) {
			char key[100];
			cout << endl << "enter the name you want to search about it: ";
			cin >> key;
			search(names, key, count);
		}
		else if (choice == 5&& names != nullptr) {
			capitalizeNames(names, count);
			cout << endl << "the capitalaised names: ";
			displayName(names, count);
		}
		else if (choice == 6 && names != nullptr) {
			longestName(names, count);
		}
		else if (choice == 7 && names != nullptr) {
			shortestName(names, count);
		}
		else if (choice == 8 && names != nullptr) {
			deleteNames(names, count);
			names = nullptr;
		}
		else if (choice == 9) {
			
			break;
		}
		else cout <<endl<< "worng input,or there is no data! try again";
	}
}
void readName(char**p, int x) {
	for (int i = 0; i < x; i++) {
		cout << endl << "enter the student name:";
		cin >> p[i];
	}
}
void sortName(char** p, int x) {
	for (int i = 0; i < x; i++) {
		for (int j = i+1; j < x; j++) {
			if (_stricmp(p[i], p[j]) > 0) {
				char t[100];
				strcpy(t, p[i]);
				strcpy(p[i],p[j]);
				strcpy(p[j],t);
			}
		}
	}
	cout << endl << "sorting the array ascending:" ;
}
void displayName(char** p, int x) {
	for (int i = 0; i < x; i++) {
		cout << endl << p[i];
	}
}
void sortLength(char**p, int x) {
	cout << endl << "sorting the array ascending by the length:";
	for (int i = 0; i < x; i++) {
		for (int j = i + 1; j < x; j++) {
			if (strlen(p[i])> strlen(p[j])){
				char t[100];
				strcpy(t, p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], t);
			}
		}
	}
	
}
void search(char** p, char* z,int x) {
	bool t=false;
	for (int i = 0; i < x; i++) {
		if (_stricmp(p[i], z) == 0)t = true;
			
	 }
	if(t)cout << endl << " name " << z << " is found" << endl;
	else cout << endl << " name " << z << " is not found" << endl;
}
void capitalizeNames(char**p, int x) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; p[i][j] != '\0'; j++) { 
			if (p[i][j] >= 'a' && p[i][j] <= 'z') {
				p[i][j] -= 32;
			}
			
		}
	}
}
void longestName(char** p, int x) {
	char* longN = p[0];
	for (int i = 0; i < x; i++) {
		if (strlen(p[i]) > strlen(longN)) {
			longN = p[i];
		}
	}
	cout << endl << "the longest name is: " << longN ;
}
void shortestName(char** p, int x) {
	char* shortN = p[0];
	for (int i = 0; i < x; i++) {
		if (strlen(p[i]) <strlen(shortN)) {
			shortN = p[i];
		}
	}
	cout << endl << "the shortest name is: " << shortN ;
}
void largestNumOf(char** p, int x) {
	int countLetter = 0;
	int* store=new int [x] ;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j<100; j++) {
			if (p[i][j] == 'a' || p[i][j] == 'A' && p[i][j] != NULL)countLetter += 1;
			
		}
		store[i] = countLetter;
		countLetter = 0;
		
	}
	int maxName = store[0];
	int maxIndex = -1;
	int i;
	for ( i = 0; i < x; i++) {
		if (store[i] >= maxName) {
			maxName = store[i];
			maxIndex = i;
		}
		
	}
	if (maxIndex != -1) {
		cout << endl<<"Name with the most 'a's: " << p[maxIndex] << " (" << maxName << " 'a's)" << endl;
	}
	else {
		cout << endl << "No names found with the letter 'a'." << endl;
	}

	delete[] store;
}


void deleteNames(char** p, int x) {
	for (int i = 0; i < x; i++) {
		delete[]p[i];
	}
	delete[]p;
	p = nullptr;
}
void choices() {

	cout << endl << "what is the operation you want to do on the names?";
	cout << endl << " 1. sort the array in ascending order display on screen.";
	cout << endl << "2. sort the array in ascending order according to the length of names and then display.";
	cout << endl << "3. find the name with the largest number of  'a' in it.";
	cout << endl << "4. search for a given name, provided by the user.,";
	cout << endl << "5. Capitalized all names and show on screen.";
	cout << endl << " 6. find the longest  name.";
	cout << endl << " 7. find the shortest name.";
	cout << endl << " 8. delete the array names";
	cout << endl << "9. exit the program.";
}