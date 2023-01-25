//main.cpp
#include <iostream>
#include<iomanip>
#include "CCompany.h"
void ConsoleClear(string name);
void ShowMainMenu(CCompany C);
void ShowWorkersMenu(CCompany C);
void WManagmentMenu(CCompany C);
void AddPToWorker(CCompany C);
void PManagmentMenu(CCompany C);
void GManagmentMenu(CCompany C);
void CreateWGroup(CCompany C);
void HireMenu(CCompany C);
void AddPMenu(CCompany C);
void DismissMenu(CCompany C);
void AcceptPMenu(CCompany C);
void ShowWList(CCompany C);
void ShowPList(CCompany C);
void ShowProjectsMenu(CCompany C);

using namespace std;

int main()
{
	/*cout << "======ADD/DELETE WORKERS=======" << endl;
	CCompany C("GEREGA_CORPORATION");
	C.ShowWorkersList();
	cout << "========ADD 3 WORKERS==========" << endl;
	C.AddWorker("gameDev");
	C.AddWorker("ProgramDev");
	C.AddWorker("WebDev");
	C.ShowWorkersList();
	cout << "=======DELETE 1 WORKER========" << endl;
	C.DeleteWorker(1);
	C.ShowWorkersList();
	cout << "======RETURNING 1 WORKER========" << endl;
	C.AddWorker("gameDev");
	C.ShowWorkersList();
	cout << "=====ADD/DELETE PROJECTS=======" << endl;
	cout << "========ADD 3 PROJECTS=========" << endl;
	C.AddProject("Site");
	C.AddProject("game");
	C.AddProject("program");
	C.ShowProjectsList();
	cout << "=======DELETE 1 PROJECT========" << endl;
	C.DeleteProject(0);
	C.ShowProjectsList();
	cout << "====ADD PROJECT TO WORKER=====" << endl;
	int pid, wid;
	cout << "Enter Project id: ";
	cin >> pid;
	cout << "Enter Worker id: ";
	cin >> wid;
	C.AddProjectToWorker(pid, wid);
	C.ShowWorkersList();
	cout << "========CREATING GROUP=========" << endl;
	C.CreateWorkerGroup(2, 0);
	C.ShowGroup(0);*/
	CCompany C("GEREGA_CORPORATION");
	C.AddProject("WebSite");
	C.AddWorker("WebDeveloper");
	ShowMainMenu(C);
}


void ConsoleClear(string name) {
	system("cls");
	cout << setw(5) << "\"" << name << "\"" << endl;
	cout << "==============================" << endl;
}

void ShowMainMenu(CCompany C) {
	bool isWork = true;
	while (isWork) {
		ConsoleClear(C.ShowCName());
		int choice = 0;
		cout << "Personal - 1" << endl
			<< "Services - 2" << endl
			<< "Exit - 3" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if (choice == 1) {
			ShowWorkersMenu(C);
		}
		else if (choice == 2) {
			ShowProjectsMenu(C);
		}
		else if (choice == 3) {
			system("cls");
			cout << "Good bye!";
			isWork = false;
		}
		else {
			ConsoleClear(C.ShowCName());
			cout << "There is no such option" << endl;
			continue;
		}
	}
}

void ShowWorkersMenu(CCompany C) {
	bool isWork = true;
	while (isWork) {
		ConsoleClear(C.ShowCName());
		int choice = 0;
		cout << "Workers management - 1" << endl
			<< "Show workers list - 2" << endl
			<< "Back - 3" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if (choice == 1) {
			WManagmentMenu(C);
		}
		else if (choice == 2) {
			ShowWList(C);
		}
		else if (choice == 3) {
			ShowMainMenu(C);
		}
		else {
			ConsoleClear(C.ShowCName());
			cout << "There is no such option" << endl;
			system("pause");
			continue;
		}
	}
}

void WManagmentMenu(CCompany C) {
	bool isWork = true;
	while (isWork) {
		ConsoleClear(C.ShowCName());
		int choice = 0;
		cout << "Hire an employee - 1" << endl
			<< "Dismiss the employee - 2" << endl
			<< "Add a project to an employee - 3" << endl
			<< "Management of groups of workers - 4" << endl
			<< "Back - 5" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if (choice == 1) {
			HireMenu(C);
		}
		else if (choice == 2) {
			DismissMenu(C);
		}
		else if (choice == 3) {
			AddPToWorker(C);
		}
		else if (choice == 4) {
			GManagmentMenu(C);
		}
		else if (choice == 5) {
			ShowWorkersMenu(C);
		}
		else {
			ConsoleClear(C.ShowCName());
			cout << "There is no such option" << endl;
			system("pause");
			continue;
		}
	}
}

void HireMenu(CCompany C) {
	cout << "==============================" << endl;
	string prof;
	cout << "Enter profession of the employee: ";
	cin >> prof;
	C.AddWorker(prof);
	WManagmentMenu(C);
}

void DismissMenu(CCompany C) {
	int id;
	cout << "=========Workers List=========" << endl;
	C.ShowWorkersList();
	cout << "==============================" << endl;
	cout << "Enter worker id: ";
	cin >> id;
	C.DeleteWorker(id);
	WManagmentMenu(C);
}


void AddPToWorker(CCompany C) {
	bool isWork = true;
	while (isWork) {
		int pid, wid;
		cout << "=========Workers List=========" << endl;
		C.ShowWorkersList();
		cout << "==============================" << endl;
		cout << "Enter worker id: ";
		cin >> wid;
		cout << "=========Projects List========" << endl;
		C.ShowProjectsList();
		cout << "==============================" << endl;
		cout << "Enter project id: ";
		cin >> pid;
		C.AddProjectToWorker(pid, wid);
		WManagmentMenu(C);
	}
}

void GManagmentMenu(CCompany C) {
	bool isWork = true;
	while (isWork) {
		ConsoleClear(C.ShowCName());
		int choice = 0;
		cout << "Create a group of employees - 1" << endl
			<< "Back - 3" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if (choice == 1) {
			CreateWGroup(C);
		}
		else if (choice == 3) {
			ShowProjectsMenu(C);
		}
		else {
			ConsoleClear(C.ShowCName());
			cout << "There is no such option" << endl;
			system("pause");
			continue;
		}
	}
}

void CreateWGroup(CCompany C){
	ConsoleClear(C.ShowCName());
	int n, gid;
	cout << "Enter the number of employees in the group: ";
	cin >> n;
	C.CreateWorkerGroup(n);
}



void ShowWList(CCompany C) {
	bool isWork = true;
	while (isWork) {
		ConsoleClear(C.ShowCName());
		int choice = 0;
		cout << "=========Workers List=========" << endl;
		C.ShowWorkersList();
		cout << "==============================" << endl;
		cout << "Back - 1" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if (choice == 1) {
			ShowWorkersMenu(C);
		}
		else {
			ConsoleClear(C.ShowCName());
			cout << "There is no such option" << endl;
			system("pause");
			continue;
		}
	}
}

void ShowProjectsMenu(CCompany C) {
	bool isWork = true;
	while (isWork) {
		ConsoleClear(C.ShowCName());
		int choice = 0;
		cout << "Service management - 1" << endl
			<< "Show services list - 2" << endl
			<< "Back - 3" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if (choice == 1) {
			PManagmentMenu(C);
		}
		else if (choice == 2) {
			ShowPList(C);
		}
		else if (choice == 3) {
			ShowMainMenu(C);
		}
		else {
			ConsoleClear(C.ShowCName());
			cout << "There is no such option" << endl;
			system("pause");
			continue;
		}
	}
}

void PManagmentMenu(CCompany C) {
	bool isWork = true;
	while (isWork) {
		ConsoleClear(C.ShowCName());
		int choice = 0;
		cout << "Order a project - 1" << endl
			<< "Accept the project - 2" << endl
			<< "Back - 3" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if (choice == 1) {
			AddPMenu(C);
		}
		else if (choice == 2) {
			AcceptPMenu(C);
		}
		else if (choice == 3) {
			ShowProjectsMenu(C);
		}
		else {
			ConsoleClear(C.ShowCName());
			cout << "There is no such option" << endl;
			system("pause");
			continue;
		}
	}
}

void AddPMenu(CCompany C) {
	cout << "==============================" << endl;
	string name;
	cout << "Enter project name: ";
	cin >> name;
	C.AddProject(name);
	PManagmentMenu(C);
}

void AcceptPMenu(CCompany C) {
	int id;
	cout << "=========Projects List========" << endl;
	C.ShowProjectsList();
	cout << "==============================" << endl;
	cout << "Enter project id: ";
	cin >> id;
	C.DeleteProject(id);
	PManagmentMenu(C);
}

void ShowPList(CCompany C) {
	bool isWork = true;
	while (isWork) {
		ConsoleClear(C.ShowCName());
		int choice = 0;
		cout << "=========Projects List========" << endl;
		C.ShowProjectsList();
		cout << "==============================" << endl;
		cout << "Back - 1" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if (choice == 1) {
			ShowProjectsMenu(C);
		}
		else {
			ConsoleClear(C.ShowCName());
			cout << "There is no such option" << endl;
			system("pause");
			continue;
		}
	}
}