//
// Created by ur0s on 11/6/20.
//

#ifndef DECENT_HW_2_TRINKET_H
#define DECENT_HW_2_TRINKET_H

#include <iostream>

#include <cryptopp/eccrypto.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/osrng.h>
#include <cryptopp/oids.h>
using namespace CryptoPP;

#include "Utils.h"

class Trinket: Utils {
    std::string serial_n;
    AutoSeededRandomPool prng;
    ECDSA<ECP, SHA256>::PrivateKey t_privateKey;
    ECDSA<ECP, SHA256>::PublicKey t_publicKey;

    ECDSA<ECP, SHA256>::PrivateKey c_privateKey;
    ECDSA<ECP, SHA256>::PublicKey c_publicKey;


public:
    explicit Trinket(std::string serial_number);

    Data to_sign(std::string cmd);
    Data receive_command(Data data_channel);
    static Data send_data(const Data& data);
    Data send_pubKey();
};


#endif //DECENT_HW_2_TRINKET_H
