#include <Windows.h>
#include <stdio.h>


int main(){
    
    HANDLE hFile = INVALID_HANDLE_VALUE;
    LPCWSTR filePath = L".\\hello.txt";
    hFile = CreateFileW(filePath, GENERIC_ALL, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE){
        printf("[-] CreateFileW API Function Failed With Error: %d\n", GetLastError());
    }

    return 0;
}