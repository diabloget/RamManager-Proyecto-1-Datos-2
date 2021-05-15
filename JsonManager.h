//
// Created by diabloget on 5/9/21.
//

#ifndef RAMMANAGER_JSONMANAGER_H
#define RAMMANAGER_JSONMANAGER_H


#include "MemoryObject.h"
#include "Instruction.h"

class JsonManager {
public:
    JsonManager();
    Instruction JsonDecomposer(std::string Json);
    std::string JsonComposer(MemoryObject memOb, std::string value);

};


#endif //RAMMANAGER_JSONMANAGER_H
