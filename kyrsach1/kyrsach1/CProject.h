#pragma once
//CProject.h
#include <string>
#include<stdlib.h>

using namespace std;

class CProject
{
public:
	CProject();
	CProject(string pname, int id);
	CProject(const CProject& other);
	CProject& operator=(CProject& other);
	string GetPName();
	int GetId();
	void SetId(int id);
	friend ostream& operator<<(ostream& output, CProject& project);
	~CProject();

private:
	string p_name;
	int p_id;
};