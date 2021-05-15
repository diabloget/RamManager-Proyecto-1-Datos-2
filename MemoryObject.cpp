/**
 * @file MemoryObject.cpp
 * @authors Diabloget, Jjvv21
 */

#include "MemoryObject.h"

/**
 * @class MemoryObject
 * @brief Objeto MemoryObject.
 * @details Permite almacenar el nombre, valor con bytes, el scope y la direccion de memoria de una instruccion.
 */

/**
 * @brief Constructor del MemoryObject
 * @param type
 * @param name
 * @param scope
 * @param memDirect
 * @details Permite generar MemoryObjects para almacenar de forma ordenada la informacion en memoria como objetos. Se utiliza a la hora de enviar los MemoryObjects como Jsons al cliente (LiveRamViewer).
 */
MemoryObject::MemoryObject(std::string type, std::string name, int scope, int memDirect){
    this->type = type;
    this->name = name;
    this->scope = scope;
    this->memDirect = memDirect;
}