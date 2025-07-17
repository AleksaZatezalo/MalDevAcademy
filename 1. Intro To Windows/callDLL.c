#include <windows.h>

// Constructing a new data type that represents HelloWorld's function pointer 
typedef void (WINAPI* HelloWorldFunctionPointer)();

void call() {
    // Attempt to get the handle of the DLL
    HMODULE hModule = GetModuleHandleA("MalDevDLL.dll");

    if (hModule == NULL) {
        // If the DLL is not loaded in memory, use LoadLibrary to load it
        hModule = LoadLibraryA("MalDevDLL.dll");
    }

	// pHelloWorld stores HelloWorld's function address
    PVOID pHelloWorld = GetProcAddress(hModule, "HelloWorld"); 


    // Typecasting pHelloWorld to be of type HelloWorldFunctionPointer
    HelloWorldFunctionPointer HelloWorld = (HelloWorldFunctionPointer)pHelloWorld;

	// Invoke HelloWorld
    HelloWorld();
    
}

int main(){

  call(); // Invoke the call() function

  return 0;
}