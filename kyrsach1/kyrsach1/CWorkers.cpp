//CWorkers.cpp
#include "CWorkers.h"
#include <iostream>


using namespace std;

CWorkers::CWorkers() {
	w_profession = "None";
	CProject p_null("None", -1);
	w_project = p_null;
	w_id = -1;

}

CWorkers::CWorkers(string proffesion, int id) {
	w_profession = proffesion;
	CProject p_null("None", -1);
	w_project = p_null;
	w_id = id;

}

CWorkers::CWorkers(const CWorkers& other) {
	if (this != &other) {
		w_profession = other.w_profession;
		CProject P = other.w_project;
		w_project = P;
		w_id = other.w_id;
	}
}


ostream& operator<<(ostream& output, CWorkers& worker)
{
	output << worker.w_id << ": " << worker.w_profession;
	if (worker.w_project.GetPName() != "None") {
		output << ", working on -> " << worker.w_project << endl;
	}
	else {
		output << endl;
	}
	return output;
}

int CWorkers::GetId() {
	return w_id;
}

string CWorkers::GetProfession() {
	return w_profession;
}


void CWorkers::SetId(int id) {
	w_id = id;
}

void CWorkers::SetProject(CProject project) {
	w_project = project;
}



CWorkers& CWorkers::operator=(CWorkers& other) {
	if (this != &other) {
		w_profession = other.w_profession;
		w_project = other.w_project;
		w_id = other.w_id;
	}
	return *this;
}


CWorkers::~CWorkers() {

}

