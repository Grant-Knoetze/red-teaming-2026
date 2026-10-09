#include <windows.h>
#include <stdio.h> 
#include <wininet.h>
#include <winternl.h>

//Registry
int UpdateRegistry(HKEY HKey, char* Key, char* ValueName, char* Data, DWORD Len, DWORD Type, bool CreateNew);
