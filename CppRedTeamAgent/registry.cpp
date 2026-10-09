#include "registry.h"

int UpdateRegistry(HKEY HKey, char* Key, char* ValueName, char* Data, DWORD Len, DWORD Type, bool CreateNew)
{
	LSTATUS ret = 0;
	HKEY OpenKey = NULL;
	if (!CreateNew)ret = (int)RegOpenKeyEx(HKey, Key, 0, KEY_ALL_ACCESS, &OpenKey);
	else ret = (int)RegCreateKey(HKey, Key, &OpenKey);

	if (ret != 0)
		return ret;

	ret = RegSetValueEx(OpenKey, ValueName, NULL, Type, (BYTE*)Data, Len);

	if (ret != 0)
		return ret;
}
