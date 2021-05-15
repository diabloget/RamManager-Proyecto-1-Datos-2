/**
 * @file Memory.cpp
 * @authors Diabloget, Jjvv21
 */

#include "Memory.h"


/**
 * @brief Singleton para retornar la misma instancia de Memory
 * @return Instance
 * @details Se aplica un Singleton para evitar recrear una nueva instancia de Memory, ya que se alocaria la memoria multiples veces.
 */
Memory *Memory::getInstance(){
    if (instance == nullptr){
        instance = new Memory();
    }
    //std::cout << "antes de asignada memoria\n";
    return instance;
}
Memory* Memory::instance = nullptr;

/**
 * @brief Constructor de Memory
 * @details Instancia la memoria dentrode un buffer, llenandola de 0s en cada digito.
 */
Memory::Memory(){
    index = 0;
    vector = std::vector<MemoryObject>();
    buffer = (char*) malloc(100000);
    memset(buffer, '0', 100000);
}

/**
 * @brief Agrega la instruccion a la memoria.
 * @param string type
 * @param string oper1
 * @param string oper
 * @param string oper2
 * @param string adress
 * @details Agrega cada instruccion segun tipo a la memoria, asignandole la cantidad de bits especifica segun el tipo.
 */
void Memory::setMemValue(std::string type, std::string oper1, std::string oper, std::string oper2, int adress){
    int offset = 0;
    std::string temp = "";
    if(type == "int"){
        offset = 4;
    }else if(type == "long"){
        offset = 8;
    }else if(type == "char"){
        offset = 1;
    }else if(type == "float"){
        offset = 4;
    }else if(type == "double"){
        offset = 8;
    }
    std::string value = "";
    if(type == "char"){
        try{
            for(int i = 0; i<vector.size(); i++){
                MemoryObject temp = vector.at(i);
                if(temp.name == oper1){
                    if(temp.type == "char"){
                        value = GetMemValue(temp);
                        break;
                    }
                }
            }
        } catch (std::invalid_argument) {
            if(oper1.length()>=2){
                value = oper[2];
            } else{
                std::cout << "Error on Char assign, probably a void reference or grammar error\n";
            }
        }
        char t = value[0];

        std::cout << temp << "\n";
        buffer[adress] = t;
        return;
    }
    //std::cout << "No debi\n";
    if(!oper2.empty() and !oper.empty()){
        int a = 0;
        int b = 0;
        try {
            a = std::stoi(oper1);
        } catch (std::invalid_argument){
            for(int i = 0; i<vector.size(); i++){
                MemoryObject temp = vector.at(i);
                if(temp.name == oper1){
                    a = std::stoi(GetMemValue(temp));
                    break;
                }
            }
        }
        try {
            b = std::stoi(oper2);
        } catch (std::invalid_argument){
            for(int i = 0; i<vector.size(); i++){
                MemoryObject temp = vector.at(i);
                if(temp.name == oper2){
                    b = std::stoi(GetMemValue(temp));
                    std::cout <<a <<" este es el valor\n";
                    break;
                }
            }
        }

        if(oper == "+"){
            value = std::to_string(a+b);
        }else if(oper == "-"){
            value = std::to_string(a-b);
        }else if(oper == "*"){
            value = std::to_string(a*b);
        }else if(oper == "/"){
            if(b==0){
                b=1;
            }
            int temp = a/b;
            value = std::to_string(temp);
        }
    }else {
        int a = 0;
        try {
            a = std::stoi(oper1);
        } catch (std::invalid_argument){
            for(int i = 0; i<vector.size(); i++){
                MemoryObject temp = vector.at(i);
                if(temp.name == oper1){
                    a = std::stoi(GetMemValue(temp));
                    break;
                }
            }
        }
        value = std::to_string(a);
    }


    for(int i = offset; i>value.length();i--){
        temp.push_back('0');
    }
    temp.append(value);
    std::cout << temp << "\n";
    for(int i = adress; i<adress+offset;i++){
        buffer[i] = temp[i-adress];
    }
    //index+=offset;
    //std::cout << "despues buffer\n";
};

/**
 * @brief Genera MemoryObjects
 * @param Instruction ins
 * @return string Json
 * @details Genera un MemoryObject con la instruccion ingresada y lo agrega al vector, retorna un Json string con los datos del MemoryObject y el valor.
 */
std::string Memory::addValue(Instruction ins){
    if(vector.size()!=0){
        for(int i = 0; i<vector.size(); i++){
            MemoryObject temp = vector.at(i);
            if(temp.name == ins.identifier and temp.scope == ins.scope) {

                //std::cout << "dentro del for\n";
                setMemValue(ins.type, ins.oper1, ins.oper, ins.oper2, temp.memDirect);
                //return GetMemValue(temp);
                return JsonManager().JsonComposer(temp, GetMemValue(temp));
            }

        }
    }

    if(vector.size()>1){
        if(ins.scope<vector[vector.size()-1].scope){
            garbageCollector(vector[vector.size()-1].scope);
        }
    }

    MemoryObject memOb = MemoryObject(ins.type, ins.identifier, ins.scope, index);
    setMemValue(ins.type, ins.oper1, ins.oper, ins.oper2, index);
    vector.push_back(memOb);

    if(ins.type == "int"){
        index+= 4;
    }else if(ins.type == "long"){
        index+= 8;
    }else if(ins.type == "char"){
        index+= 1;
    }else if(ins.type == "float"){
        index+= 4;
    }else if(ins.type == "double"){
        index+= 8;
    }

    return JsonManager().JsonComposer(memOb, GetMemValue(memOb));

}

/**
 * @brief Recicla la memoria fuera de uso.
 * @param int scope
 * @details Si la variable nueva tiene un scope menor a la ultima ingresada al vector, se crea un nuevo vector con todas las variables que tenga un scope menor o igual al nuevo ingresado.
 * ademas, se actualiza el index para que se sobreescriba la memoria desocupada al eliminar las varibles de scopes pasados.
 */
void Memory::garbageCollector(int scope){
    //index
    std::vector<MemoryObject> temp = std::vector<MemoryObject>();
    for(int i = 0; i<vector.size(); i++){
        if(vector[i].scope==scope){
            index = vector[i].memDirect;
            break;
        }
    }
    for(int i = 0; i<vector.size(); i++){
        if(vector[i].scope<scope){
            temp.push_back(vector[i]);
        }
    }
}

/**
 * @brief Retorna el valor de un MemoryObject.
 * @param MemoryObject target
 * @return string value
 * @details obtiene el valor de una instruccion a partir de un MemoryObject.
 */
std::string Memory::GetMemValue(MemoryObject target){
    int offset = 0;
    if(target.type == "int"){
        offset = 4;
    }else if(target.type == "long"){
       offset = 8;
    }else if(target.type == "char"){
        offset = 1;
    }else if(target.type == "float"){
        offset = 4;
    }else if(target.type == "double"){
        offset = 8;
    }
    std::string value = "";
    for(int i = target.memDirect; i<target.memDirect+offset;i++){
        value.push_back(buffer[i]);
    }
    return value;
}