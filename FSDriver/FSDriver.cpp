/*
 * FSDriver.cpp
 *
 *  Created on: Jul 27, 2011
 *      Author: user
 */

#include "FSDriver.h"


FSDriver* FSDriver::_pInstance = NULL;

void  FSDriver::Create(const char* DiskConfigFile)
{
	_pInstance = new FSDriver(DiskConfigFile);
}

FSDriver* FSDriver::Instance()
{
	if(NULL == _pInstance)
	{
		Create(DEFAULT_DISK_CONF_FILE);
	}
	return _pInstance;
}

void FSDriver::InitFSDriver()
{
	_areaCount = 0;

}

void FSDriver::InitConfigFile(const char* DiskConfigFile)
{
	FILE* configFile = fopen(DiskConfigFile, "r");
	fscanf(configFile, "%d\n", &_areaCount);
	for (int i = 0; i < _areaCount; i++)
	{
		char diskPath[1024];
		fscanf(configFile, "%s\n",(char*)diskPath);
		printf("%s\n", diskPath);
		FSArea * area = new FSArea(diskPath);
		_areaList.push_back(area);
	}
}

FSDriver::FSDriver(const char* DiskConfigFile)
{
	InitFSDriver();
	InitConfigFile(DiskConfigFile);
}

void FSDriver::Destroy()
{
	delete _pInstance;
}

FSDriver::~FSDriver()
{
	for (int i = 0; i < _areaCount; i++)
	{
		delete _areaList[i];
	}
}

int FSDriver::GetBlock(int fsId, int blockNum, BlockData* container)
{
	return _areaList[fsId]->GetBlock(blockNum,container);
}

int FSDriver::SetBlock(int fsId, int blockNum, BlockData value)
{
	return _areaList[fsId]->SetBlock(blockNum,value);
}

