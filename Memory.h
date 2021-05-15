//
// Created by diabloget on 5/9/21.
//

#ifndef RAMMANAGER_MEMORY_H
#define RAMMANAGER_MEMORY_H
#include <vector>
#include "iostream"
#include "MemoryObject.h"
#include "Instruction.h"
#include <cstring>
#include "Instruction.h"
#include "JsonManager.h"

class Memory {
    int index;
    char *buffer;
    std::vector<MemoryObject> vector;
    static Memory* instance;
public:
    Memory * getInstance();
    void setMemValue(std::string type, std::string oper1, std::string oper, std::string oper2, int adress);
    Memory();
    std::string addValue(Instruction ins);
    std::string GetMemValue(MemoryObject target);
    void garbageCollector(int scope);
};


#endif //RAMMANAGER_MEMORY_H
