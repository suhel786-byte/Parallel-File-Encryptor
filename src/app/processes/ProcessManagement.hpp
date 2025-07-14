#ifndef Process_Management_HPP
#define Process_management_HPP

#include "Task.hpp"
#include <queue>
#include <memory>

class ProcessManagement{
    public:
        ProcessManagement();
        bool submitToQueue(std::unique_ptr<Task> task);
        void executeTasks();
    private:
        queue<unique_ptr<Task>> taskQueue;  
       
};

#endif