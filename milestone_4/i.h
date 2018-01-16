#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"
#include "t.h"


///code missing

class Item {
	string itemDescription, itemSequence, itemRemoverTask, itemName, itemInstallerTask;
public:
	Item(vector<string>);
	void Print();
	void Graph(fstream&);
	std::string& getItemName()  { return itemName; }
	std::string& getItemRemoverTask() { return itemRemoverTask; }
	std::string& getItemInstallerTask() { return itemInstallerTask; }
};

//code missing

class ItemManager {
	vector< Item > itemList;
public:
	ItemManager(vector <vector <string> >& csvData);
	void Print();
	void Graph(string& filename);
	Item* FindItem(std::string& name) {
	for (size_t i = 0; itemList.size(); i++) {
		if (itemList[i].getItemName() == name)
			return &itemList[i];
 }
	return nullptr;
}
	void IntegrityCheck(TaskManager& tm);
};
