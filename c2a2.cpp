#include <iostream>
#include<string.h>
using namespace std;
#pragma warning(disable : 4996)
struct personalinfo
{
	char *name;
	int id;
	int age;
};
struct paymentinfo
{
	int hPerWeek;
	int payH;
	float tax;
};
struct salinfo
{
	int grossSal;
	float netSal;
};
struct employee
{
	personalinfo * personal;
	paymentinfo * payment;
	salinfo * salary;
};
void readData(employee *e,int x);
void displayEmp(employee* e, int x);
void largesGross(employee* e, int x);
void smallestGross(employee* e, int x);
void sortGross(employee* e, int x);
void search(employee* e, int x);
int main() {
	int empNom;
	cout << "enter the number of employees:" << endl;
	cin >> empNom;
	employee *e = NULL;
	e = new employee[empNom];
	
	readData(e,empNom);
	int choice = 0;
  for (int i = 0; i<100; i++){

	  cout << "what you want to do on youre data(pick a number)?"<<endl;
	  cout << "1. display a list of employees." << endl;
	  cout << "2. display an employee with largest gross salary." << endl;
	  cout << "3. display an employee with smallest gross salary." << endl;
	  cout << "4. sort the employees according to their gross salary." << endl;
	  cout << "5. search for a given employee with a given name." << endl;
	  cout << "6.exit" << endl;

	  cin >> choice;
	
	  if (choice == 1) {
		  cout << endl << "displaying the employees data..." << endl;
		  displayEmp(e, empNom);
	  }
	  else if (choice == 2) {
		  cout << endl << "the employee with the higest gross salary..." << endl;
		  largesGross(e, empNom);
	  }
	  else if (choice == 3) {
		  cout << endl << "the employee with the lowest gross salary..." << endl;
		  smallestGross(e, empNom);
	  }
	  else if (choice == 4) {
		  cout << endl << "the sorted data decinding according to the gross salary..." << endl;
		  sortGross(e, empNom);
		  displayEmp(e, empNom);
	  }
	  else if (choice == 5) {
		  search(e, empNom);
	  }
	  else if (choice == 6) { cout << "closing the program..."; break; }
   }
  delete[]e;
}
void readData(employee* e, int x) {
	
	char* p = new char[1000];
	
	for (int i = 0; i < x; i++) {

		e->personal = new personalinfo;
		e->payment = new paymentinfo;
		e->salary = new salinfo ;
		cout << "enter the employee name" << endl;
		cin >> p;
		e->personal->name = new char[strlen(p)+1];
		strcpy(e->personal->name, p);
		cout << "enter the employee id" << endl;
		cin >> e->personal->id;
		cout << "enter the employee age" << endl;
		cin >> e->personal->age;
		cout << "enter the employee hours worked per week:" << endl;
		cin >> e->payment->hPerWeek;
		cout << "enter the employee payment per hour:" << endl;
		cin >> e->payment->payH;
		cout << "enter the employee tax(.05,.10,.15,...):" << endl;
		cin >> e->payment->tax;
		e->salary->grossSal = e->payment->hPerWeek * e->payment->payH;
		e->salary->netSal = e->salary->grossSal- e->salary->grossSal * e->payment->tax;
		e++;
	}
	delete[]p;
}
void displayEmp(employee* e, int x) {
	cout << endl ;
	for (int i = 0; i < x; i++) {
		cout <<"employee number "<<i+1<< " name: " << e->personal->name << endl;
		cout<< " age: " << e->personal->age << endl;
		cout<<" id: " << e->personal->id << endl;
		cout << " gross salary " << e->salary->grossSal<< endl;
		cout << " net salary " << e->salary->netSal << endl;
		e++;
	}
}
void largesGross(employee* e, int x) {
	int largest = 0;
	int index = -1;
	for (int i = 0; i < x; i++) {
		if (e[i].salary->grossSal >= largest) {
			largest = e[i].salary->grossSal;
			index = i;
		}
	
	}
	if (index != -1) {
		cout <<  endl;
		cout << "name:" << e[index].personal->name << endl;
		cout << " age: " << e[index].personal->age << endl;
		cout << " id: " << e[index].personal->id << endl;
		cout << " gross salary " << e[index].salary->grossSal << endl;
		cout << " net salary " << e[index].salary->netSal << endl;
	}
	else {
		cout << "No employees found." << endl;
	}
}
void smallestGross(employee* e, int x) {
	int smallest = e[0].salary->grossSal;
	int index = -1;
	for (int i = 0; i < x; i++) {
		if (e[i].salary->grossSal <= smallest) {
			smallest = e[i].salary->grossSal;
			index = i;
		}

	}
	if (index != -1) {
		cout << endl ;
		cout << "name:"<<e[index].personal->name << endl;
		cout << " age: " << e[index].personal->age << endl;
		cout << " id: " << e[index].personal->id << endl;
		cout << " gross salary " << e[index].salary->grossSal << endl;
		cout << " net salary " << e[index].salary->netSal << endl;
	}
	else {
		cout << "No employees found." << endl;
	}

}
void sortGross(employee* e, int x) {
	if (x < 2)return;
	
	for (int j = 0; j < x ; j++) {
		for (int i = j+1; i < x ; i++) {
			if (e[j].salary->grossSal < e[i].salary->grossSal) {
				employee temp = e[j];
				e[j] = e[i];
				e[i] = temp;
			}
		}
	}
	
}
void search(employee* e, int x) {
	char* searchName = new char[100];
	cout << endl << "enter the name you want to search for:" << endl;
	cin >> searchName;
	bool found = false;
	for (int i = 0; i < x; i++) {
		if (stricmp(searchName, e[i].personal->name) == 0) {
			found = true;
			cout << endl <<"the information for the employee " << searchName<<endl;
			cout<< "name:"<<e[i].personal->name << endl;
			cout << " age: " << e[i].personal->age << endl;
			cout << " id: " << e[i].personal->id << endl;
			cout << " gross salary " << e[i].salary->grossSal << endl;
			cout << " net salary " << e[i].salary->netSal << endl;
		}
	}
	if (found == false) {
		cout << endl << "there's no matching name"<<endl;
	}
	delete[]searchName;
}