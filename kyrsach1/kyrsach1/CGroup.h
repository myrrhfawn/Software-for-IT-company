#pragma once
//CGroup.h
#include "CProject.h"
#include "CWorkers.h"
#include <iostream>
#include <stdlib.h>
#include <string>

class CGroup
{
public:
	CGroup();
	CGroup(int NumberOfWorkers, CProject gid);
	CGroup(const CGroup& other);
	void AddWorkerToGroup(int w_id);
	int GetWId(int id);
	int GetPId();
	void DeleteWorkerFromGroup(int wid);
	CGroup& operator= (CGroup& other);
	~CGroup();

private:
	bool isFull = false;
	int WorkersInGroup;
	int DoneWorker;
	int* WIdList;
	CProject g_project;
};