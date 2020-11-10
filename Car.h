//
// Created by ur0s on 11/6/20.
//

#ifndef DECENT_HW_2_CAR_H
#define DECENT_HW_2_CAR_H

#include "utils.h"
using namespace CryptoPP;


class Car {
    AutoSeededRandomPool prng;
    ECDSA<ECP, SHA256>::PrivateKey c_privateKey;
    ECDSA<ECP, SHA256>::PublicKey c_publicKey;

    ECDSA<ECP, SHA256>::PublicKey t_publicKey;


public:
    explicit Car();

    Data sign(Data);
    static Data emmit(Data);
    bool receive(const Data&);
    bool verify(const Data&);
    static void execute(const std::string&);
    Data share_pubKey();


};


#endif //DECENT_HW_2_CAR_H
