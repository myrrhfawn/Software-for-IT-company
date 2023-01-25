//CWorkers.h
#pragma once
#include <string>
#include <stdlib.h>
#include "CProject.h"

using namespace std;

class CWorkers
{
public:
	CWorkers();
	CWorkers(string proffesion, int id);
	CWorkers(const CWorkers& other);
	CWorkers& operator=(CWorkers& other);
	int GetId();
	string GetProfession();
	void SetId(int id);
	void SetProject(CProject project);
	friend ostream& operator<<(ostream& output, CWorkers& worker);
	~CWorkers();
private:
	string w_profession;
	CProject w_project;
	int w_id;

};