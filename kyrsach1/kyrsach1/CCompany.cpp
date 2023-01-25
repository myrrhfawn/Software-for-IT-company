//CCompany.cpp
#include "CCompany.h"
#include <iostream>

using namespace std;

CCompany::CCompany() {
	c_name = "None";
	WorkersList = new CWorkers[number_of_workers];
	CWorkers W1("ADMIN", 0);
	WorkersList[0] = W1;
}

CCompany::CCompany(string cname) {
	c_name = cname;
	WorkersList = new CWorkers[number_of_workers];
	CWorkers W0("ADMIN", 0);
	WorkersList[0] = W0;
}

CCompany::CCompany(const CCompany& other)
{
	if (this != &other) {
		c_name = other.c_name;
		number_of_workers = other.number_of_workers;
		number_of_project = other.number_of_project;
		WorkersList = new CWorkers[number_of_workers];
		WorkersList = other.WorkersList;
		ProjectsList = new CProject[number_of_project];
		ProjectsList = other.ProjectsList;
	}
}



string CCompany::ShowCName() {
	return c_name;
}

void CCompany::AddWorker(string profession ){
	CWorkers* WorkersListTmp = new CWorkers[number_of_workers];
	WorkersListTmp = WorkersList;
	number_of_workers++;
	WorkersList = new CWorkers[number_of_workers];
	for (int i = 0; i < number_of_workers; i++) {
		if (i != number_of_workers - 1) {
			WorkersList[i] = WorkersListTmp[i];
		}
		else {
			
			CWorkers W(profession, i);
			WorkersList[i] = W;
			
		}
	}
	delete[] WorkersListTmp;
}

void CCompany::DeleteWorker(int id) {
	CWorkers* WorkersListTmp = new CWorkers[number_of_workers];
	WorkersListTmp = WorkersList;
	number_of_workers--;
	WorkersList = new CWorkers[number_of_workers];
	for (int i = 0; i < number_of_workers; i++) {
		if (i < id) {
			WorkersList[i] = WorkersListTmp[i];
		}
		else if (i >= id) {
			WorkersList[i] = WorkersListTmp[i + 1];
			WorkersList[i].SetId(i);
		}

	}
	delete[] WorkersListTmp;
}

void CCompany::AddProject(string pname) {
	if(number_of_project != 0 ) {
		CProject* ProjectsListTmp = new CProject[number_of_project];
		ProjectsListTmp = ProjectsList;
		number_of_project++;
		ProjectsList = new CProject[number_of_project];
		for (int i = 0; i < number_of_project; i++) {
			if (i != number_of_project - 1) {
				ProjectsList[i] = ProjectsListTmp[i];
			}
			else {

				CProject P(pname, i);
				ProjectsList[i] = P;

			}
		}
		delete[] ProjectsListTmp;
	}
	else {
		number_of_project++;
		ProjectsList = new CProject[1];
		CProject P(pname, 0);
		ProjectsList[0] = P;
	}
	
}

void CCompany::DeleteProject(int id) {
	if (number_of_project != 0) {
		CProject* ProjectsListTmp = new CProject[number_of_workers];
		ProjectsListTmp = ProjectsList;
		number_of_project--;
		ProjectsList = new CProject[number_of_project];
		for (int i = 0; i < number_of_project; i++) {
			if (i < id) {
				ProjectsList[i] = ProjectsListTmp[i];
			}
			else if (i >= id) {
				ProjectsList[i] = ProjectsListTmp[i + 1];
				ProjectsList[i].SetId(i);
			}

		}
		delete[] ProjectsListTmp;
	}
	else {
		cout << "Company hasnt have project" << endl;
	}
}

void CCompany::ShowWorkersList() {
	for(int i = 0; i < number_of_workers; i++) {
		cout << WorkersList[i];
	}
}

void CCompany::ShowProjectsList() {
	for (int i = 0; i < number_of_project; i++) {
		cout << ProjectsList[i] << endl;
	}
}

void CCompany::AddProjectToWorker(int pid, int wid) {
	WorkersList[wid].SetProject(ProjectsList[pid]);
}

void CCompany::CreateWorkerGroup(int nworker) {
	int p_id, w_id;
	cout << "=========Projects List========" << endl;
	ShowProjectsList();
	cout << "==============================" << endl;
	cout << "Please choice the project for group: ";
	cin >> p_id;

	CGroup G(nworker, ProjectsList[p_id]);

	cout << "Please add workers to group: " << endl;
	cout << "=========Workers List=========" << endl;
	ShowWorkersList();
	cout << "==============================" << endl;
	bool choice = true;
	int tmp = 0;
	for(int i =0; i< nworker; i++){
		cout << "Enter worker id: ";
		cin >> w_id;
		G.AddWorkerToGroup(w_id);
	}
	for(int i = 0; i < number_of_workers; i++) {
		for (int j = 0; j < nworker; j++) {
			if (WorkersList[i].GetId() == G.GetWId(j)) {
				AddProjectToWorker(G.GetPId(), WorkersList[i].GetId());
			}
		}
	}
}



CCompany::~CCompany() {
	
}