//
// Created by diabloget on 5/9/21.
//

#ifndef RAMMANAGER_INSTRUCTION_H
#define RAMMANAGER_INSTRUCTION_H
#include <iostream>

class Instruction {
public:
    std::string type;
    std::string oper1;
    std::string oper;
    std::string oper2;
    std::string identifier;
    int scope;
    int line;

    Instruction(std::string type, std::string oper1, std::string oper, std::string oper2, std::string identifier, int scope, int line);
    Instruction(std::string type, std::string oper1, std::string identifier, int scope, int line);
    Instruction(std::string type, int scope);
};


#endif //RAMMANAGER_INSTRUCTION_H
