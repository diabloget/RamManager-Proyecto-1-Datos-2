//
// Created by diabloget on 5/9/21.
//

#ifndef IDE_RAMCLIENT_H
#define IDE_RAMCLIENT_H


#include <arpa/inet.h>
#include "Memory.h"

class RamClient {

private:
    static RamClient* instance;
    char buffer[1024];
    struct sockaddr_in addressSender;
    struct sockaddr_in addressinit;
    struct sockaddr_in addressReader;

    int opt = 1;
    int addrlen = sizeof(addressSender);
    int sender,reader,init;
    char* ok = "xx";
    Memory* x;
    void createSender();
    void createReader();
    Memory * mem;
    std::string JsontoSend;

public:
    RamClient();
    void initReader();
    static RamClient *GetInstance();
};


#endif //IDE_RAMCLIENT_H