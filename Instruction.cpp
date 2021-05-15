/**
 * @file Instruction.cpp
 * @authors Diabloget, Jjvv21
 */


#include "Instruction.h"

/**
 * @brief Constructor de Instruccion.
 * @param string type
 * @param string oper1
 * @param string oper
 * @param string oper2
 * @param string identifier
 * @param int scope
 * @param int line
 * @details Constructor del objeto Instruccion con multiples operandos.
 */
Instruction::Instruction(std::string type, std::string oper1, std::string oper, std::string oper2, std::string identifier, int scope, int line){
    this->type = type;
    this->oper1 = oper1;
    this->oper = oper;
    this->oper2 = oper2;
    this->identifier = identifier;
    this->scope = scope;
    this->line = line;
}
Instruction::Instruction(std::string type, std::string oper1, std::string identifier, int scope, int line){
    this->type = type;
    this->oper1 = oper1;
    this->identifier = identifier;
    this->scope = scope;
    this->line = line;
}
Instruction::Instruction(std::string type, int scope){
    this->type = type;
    this->scope = scope;\
}