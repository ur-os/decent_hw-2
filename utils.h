//
// Created by ur0s on 11/7/20.
//

#ifndef DECENT_HW_2_UTILS_H
#define DECENT_HW_2_UTILS_H

#include <iostream>
#include <cryptopp/eccrypto.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/osrng.h>
#include <cryptopp/oids.h>

const std::string MAGIC_NUMB = "478276944582684";

struct Data{
    std::string cmd;
    std::string signature;
    CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::PublicKey publicKey;
};


#endif //DECENT_HW_2_UTILS_H
