//CGroup.cpp
#include "CGroup.h"
#include <string>

using namespace std;

CGroup::CGroup() {
	CProject p_null("None", -1);
	g_project = p_null;
}

CGroup::CGroup(int NumberOfWorkers, CProject gid) {
	WorkersInGroup = NumberOfWorkers;
	WIdList = new int[WorkersInGroup];
	CProject P = gid;
	g_project = P;
}

CGroup::CGroup(const CGroup& other) {
	isFull = other.isFull;
	WorkersInGroup = other.WorkersInGroup;
	DoneWorker = other.DoneWorker;
	WIdList = new int[WorkersInGroup];
	WIdList = other.WIdList;
	CProject P = other.g_project;
	g_project = P;
}

CGroup& CGroup::operator= (CGroup& other) {
	isFull = other.isFull;
	WorkersInGroup = other.WorkersInGroup;
	DoneWorker = other.DoneWorker;
	WIdList = new int[WorkersInGroup];
	WIdList = other.WIdList;
	CProject P = other.g_project;
	g_project = P;
	return *this;

}

void CGroup::AddWorkerToGroup(int w_id) {
	if (isFull == false) {
		WIdList[DoneWorker] = w_id;
		DoneWorker++;
		if (DoneWorker == WorkersInGroup) {
			isFull = true;
		}
	}
	else {
		cout << "Group is full" << endl;
	}
}

void CGroup::DeleteWorkerFromGroup(int wid) {
	int WorkerNumber;
	for (int i = 0; i < DoneWorker; i++) {
		if (WIdList[i] == wid) {
			WorkerNumber = i;
		}
	}
	int* GroupTmp = new int[WorkersInGroup];
	GroupTmp = WIdList;
	WIdList = new int[WorkersInGroup];
	for (int i = 0; i < WorkersInGroup; i++) {
		if (i < WorkerNumber) {
			WIdList[i] = GroupTmp[i];
		}
		if (i >= WorkerNumber) {
			WIdList[i] = GroupTmp[i];
		}
	}
	delete[] GroupTmp;
}

int CGroup::GetWId(int id) {
	if (id < WorkersInGroup) {
		return WIdList[id];
	}
	else {
		return -1;
	}
}

int CGroup::GetPId() {
	return g_project.GetId();
}


CGroup::~CGroup() {
	
}