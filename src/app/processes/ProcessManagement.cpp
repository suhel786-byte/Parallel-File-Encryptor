#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

#include "ProcessManagement.hpp"
#include <iostream>
#include <string>
#include "../encryptDecrypt/Cryption.hpp"
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/wait.h>   
#endif
using namespace std;
ProcessManagement::ProcessManagement(){}

bool ProcessManagement::submitToQueue(std::unique_ptr<Task> task){
    taskQueue.push(move(task));
    #ifdef _WIN32
        STARTUPINFO si = { sizeof(STARTUPINFO) };
        PROCESS_INFORMATION pi;
        ZeroMemory(&si, sizeof(si));
        ZeroMemory(&pi, sizeof(pi));
    
        if (CreateProcess(NULL,   // No module name (use command line)
                          L"child_process", // Command line
                          NULL,   // Process handle not inheritable
                          NULL,   // Thread handle not inheritable
                          FALSE,  // Set handle inheritance to FALSE
                          0,      // No creation flags
                          NULL,   // Use parent's environment block
                          NULL,   // Use parent's starting directory 
                          &si,    // Pointer to STARTUPINFO structure
                          &pi)    // Pointer to PROCESS_INFORMATION structure
        ) {
            cout << "Enter the child process " << endl;
            executeTasks();
            cout << "Exiting child process " << endl;
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        } else {
            cout << "Failed to create child process" << endl;
        }
    #else
        int pid = fork(); 
        if(pid < 0){
            cout << "Enter the parent process " << endl;
        }
        else{
            cout << "Enter the child process " << endl;
            executeTasks();
            cout << "Exiting child process " << endl;
        }
    #endif
    return true;
}

void ProcessManagement::executeTasks(){
    while(!taskQueue.empty()){
        unique_ptr<Task> tasktoExecute = move(taskQueue.front()); 
        taskQueue.pop();
        cout<<"Executing task: " << tasktoExecute->toString() <<endl;
        executeCryption(tasktoExecute->toString());
    }
}