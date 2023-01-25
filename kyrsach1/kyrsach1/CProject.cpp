//CProject.cpp
#include "CProject.h"
#include <iostream>


using namespace std;

CProject::CProject() {
	p_name = "None";
	p_id = -1;
}

CProject::CProject(string pname, int id) {
	p_name = pname;
	p_id = id;
}

CProject::CProject(const CProject& other) {
	if (this != &other) {
		p_name = other.p_name;
		p_id = other.p_id;
	}
}


ostream& operator<<(ostream& output, CProject& project)
{
	output << "{" << project.p_id << ": " << project.p_name << "}";
	return output;
}

int CProject::GetId() {
	return p_id;
}

void CProject::SetId(int id) {
	p_id = id;
}

string CProject::GetPName() {
	return p_name;
}


CProject& CProject::operator=(CProject& other) {
	if (this != &other) {
		p_name = other.p_name;
		p_id = other.p_id;
	}
	return *this;
}


CProject::~CProject() {

}
