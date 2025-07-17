#include <Windows.h>
#include <stdio.h>

int main(){
    PVOID pAddress = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 100);

    char *cString = "MalDevAcademy Is the Best";
    memcpy(pAddress, cString, strlen(cString));

    printf("[+] Base Address Of Allocated Memory: 0x%p \n", pAddress);

    HeapFree(GetProcessHeap(), 0, pAddress);

    return 0;
}