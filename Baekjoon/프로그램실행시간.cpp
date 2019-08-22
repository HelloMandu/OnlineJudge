#include <cstdio>
#include <windows.h>
DWORD start;
int main() {
	start = GetTickCount(); 
	// Process
	printf("%.3lf\n",(GetTickCount()-start)/1000.0); 
	return 0;
}