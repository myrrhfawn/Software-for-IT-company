#pragma once
//CCompany.h
#include "CGroup.h"
#include <string>
#include "CWorkers.h"

class CCompany
{
public:
	
	CCompany();
	CCompany(string cname);
	CCompany(const CCompany& other);
	~CCompany();
	string ShowCName();
	void AddWorker(string profession);
	void DeleteWorker(int id);
	void ShowWorkersList();
	void AddProject(string pname);
	void DeleteProject(int id);
	void ShowProjectsList();
	void AddProjectToWorker(int pid, int wid);
	void CreateWorkerGroup(int nworker);


private:
	string c_name;
	int number_of_workers = 1;
	CWorkers* WorkersList;
	int number_of_project = 0;
	CProject* ProjectsList;
	
};