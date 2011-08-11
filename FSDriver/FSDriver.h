/*
 * FSDriver.h
 *
 *  Created on: Jul 29, 2011
 *      Author: user
 */

#ifndef FSDRIVER_H_
#define FSDRIVER_H_


#define DEFAULT_DISK_CONF_FILE "/home/user/workspace/cpp/DiskCache/.disk.conf"

#include "FSArea.h"
#include <iostream>
#include <vector>
using namespace std;

#define DllExport   __declspec( dllexport )

class DllExport FSDriver  //reload virtual class FSDriver
{
private:
	int _areaCount;
	vector<FSArea *> _areaList;
	static FSDriver* _pInstance;
	FSDriver (const char* DiskConfigFile);
	void InitFSDriver();
	void InitConfigFile(const char* DiskConfigFile);
	~FSDriver();
public:
	static void Destroy();
	static void Create(const char* DiskConfigFile);
	static FSDriver* Instance();
	int GetBlock(int fsId, int blockNum, BlockData* container);
	int SetBlock(int fsId, int blockNum, BlockData value);
};

#endif /* FSDRIVER_H_ */
