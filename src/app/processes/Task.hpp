#ifndef TASK_HPP
#define TASK_HPP
#include <string>
#include <iostream>
#include <fstream>
#include "../fileHandling/IO.hpp"
#include <sstream>

using namespace std;

enum class Action {
    ENCRYPT,
    DECRYPT
};

struct Task
{
    string file_path;
    fstream f_stream;
    Action action;

    Task(fstream &&stream, Action act, string file_path) : f_stream(move(stream)), action(act), file_path(file_path) {}

    string toString(){
        stringstream oss;
        oss<<file_path<<","<<(action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");
        return oss.str();
    }
    
    static Task fromString(string &taskData){//serialization
        stringstream iss(taskData);
        string file_path;
        string actionstr;
      
        if(getline(iss, file_path , ',') && getline(iss, actionstr) ){
            Action action = actionstr == "ENCRYPT"  ? Action::ENCRYPT : Action::DECRYPT;
            IO io(file_path);
            fstream f_stream = move(io.getFileStream());
            if(f_stream.is_open()){
                return Task(move(f_stream), action, file_path);
            }else{
                throw runtime_error("Failed to open file"+ file_path);
            }
        }else{
                throw runtime_error("Invalid Task data format");
        }
    } 
};



#endif