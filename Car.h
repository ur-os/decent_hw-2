//
// Created by ur0s on 11/6/20.
//

#ifndef DECENT_HW_2_CAR_H
#define DECENT_HW_2_CAR_H

#include <cryptopp/eccrypto.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/osrng.h>
#include <cryptopp/oids.h>
using namespace CryptoPP;

#include "Utils.h"

class Car: Utils {
    std::string serial_n;
    AutoSeededRandomPool prng;
    ECDSA<ECP, SHA256>::PrivateKey k1;
    ECDSA<ECP, SHA256>::PublicKey publicKey;

public:
    explicit Car(std::string serial_number);
    void send_command(std::string cmd);
    bool receive_command(const Data& data_channel);
};


#endif //DECENT_HW_2_CAR_H
