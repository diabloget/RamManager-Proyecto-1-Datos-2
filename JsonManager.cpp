/**
 * @file JsonManager.cpp
 * @authors Diabloget, Jjvv21
 */


#include <iostream>
#include <QJsonObject>
#include <QJsonDocument>
#include "JsonManager.h"


/**
 * @class JsonManager
 * @brief Manager de Jsons
 * @details JsonManager permite descomponer los Json entrantes y de salida.
 */

/**
 * @brief Creador del JsonManager
 * @details Permite instanciar al JsonManager para llamar a los metodos de descomposicion y composicion de Jsons
 */
JsonManager::JsonManager(){

}

/**
 * @brief Descompone Json en Instruccion
 * @param string Json
 * @return Instruction
 * @details Descompone un Json en un Objecto Instruccion para almacenar los detalles de cada instruccion recibida del cliente.
 */
Instruction JsonManager::JsonDecomposer(std::string Json){
    //QJsonValue val(QString::fromStdString(Json));
    //QJsonObject qjson = val.toObject();
    QByteArray byteArray(Json.c_str(), Json.length());
    QJsonDocument doc(QJsonDocument::fromJson(byteArray));
    QJsonObject qjson = doc.object();

    std::string identifier = qjson.value("identifier").toString().toStdString();
    int line = qjson.value("line").toString().toInt();
    std::string oper = qjson.value("oper").toString().toStdString();
    std::string oper1 = qjson.value("oper1").toString().toStdString();
    std::string oper2 = qjson.value("oper2").toString().toStdString();
    int scope = qjson.value("scope").toString().toInt();
    std::string type = qjson.value("type").toString().toStdString();

    Instruction instruction = Instruction(type, oper1, oper, oper2, identifier, scope, line);
    /*
    std::cout << identifier << "\n";
    std::cout << line << "\n";
    std::cout << oper1 << "\n";
    std::cout << oper << "\n";
    std::cout << oper2 << "\n";
    std::cout << scope << "\n";
    std::cout << type << "\n";
     */
    return instruction;
}

/**
 * @brief Composer de Jsons
 * @param memOb
 * @param value
 * @return string Json
 * @details Genera a partir de un MemoryObject y el valor en memoria, un json con los datos para que el cliente genere su propio MemoryObject (Usado en el LiveRamViewer).
 */
std::string JsonManager::JsonComposer(MemoryObject memOb, std::string value){
    QJsonObject QJson = QJsonObject();
    QJson.insert("mdirec",memOb.memDirect);
    QJson.insert("value",QString::fromStdString(value));
    QJson.insert("name",QString::fromStdString(memOb.name));
    QJson.insert("scope", memOb.scope);

    QJsonDocument doc(QJson);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    std::cout << strJson.toStdString();
    return strJson.toStdString();
}