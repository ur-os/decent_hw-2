//
// Created by ur0s on 11/6/20.
//

#ifndef DECENT_HW_2_TRINKET_H
#define DECENT_HW_2_TRINKET_H

#include "Utils.h"
using namespace CryptoPP;


class Trinket: Utils {
    AutoSeededRandomPool prng;
    ECDSA<ECP, SHA256>::PrivateKey t_privateKey;
    ECDSA<ECP, SHA256>::PublicKey t_publicKey;

    ECDSA<ECP, SHA256>::PublicKey c_publicKey;
    Data c_last_data;
    Integer nonce;

public:
    explicit Trinket();

    Data sign(Data);
    Data emmit(Data);
    bool receive(Data);
    bool verify(Data);
    static void execute(const std::string& cmd);
    Data share_pubKey();

};


#endif //DECENT_HW_2_TRINKET_H
