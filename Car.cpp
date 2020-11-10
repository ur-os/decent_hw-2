//
// Created by ur0s on 11/6/20.
//

#include "Car.h"

Car::Car() {
    c_privateKey.Initialize(prng, ASN1::secp256r1());
    c_privateKey.MakePublicKey(c_publicKey);
    std::cout << "\nCar:\ngenerate self keys" << std::endl;
}

bool Car::verify(const Data& channel) {
    std::string message = channel.cmd;
    std::string signature = channel.signature;
    ECDSA<ECP, SHA256>::Verifier verifier(t_publicKey);

    bool result = verifier.VerifyMessage( (const byte*)&message[0],
                                          message.size(),
                                          (const byte*)&signature[0],
                                          signature.size()
    );
    result ? std::cout << "\nCar:\nauthenticated successful\n" : std::cout << "\nCar:\nauthenticated failed\n";
    return result;
}

bool Car::receive(const Data& channel) {
    std::cout << "\nCar:\n" << "receive:\ncommand: \"" << channel.cmd << "\"\nwith: \""<< channel.signature << "\"\n";
    if(channel.signature == MAGIC_NUMB) {
        t_publicKey = channel.publicKey;
        std::cout << "\nCar:\n" << "trinket pubKey was setup" << std::endl;
        return true;
    }
    if(verify(channel)) {
        execute(channel.cmd);
        return true;
    }
    return false;
}

void Car::execute(const std::string& cmd) {
    std::cout << "\nCar:\nexecute command: \"" << cmd << "\"\n";
}

Data Car::sign(Data data) {
    ECDSA<ECP, SHA256>::Signer signer(c_privateKey);
    std::string message = data.cmd;

    size_t siglen = signer.MaxSignatureLength();
    std::string signature(siglen, 0x00);
    siglen = signer.SignMessage( prng, (const byte*)&message[0],
                                 message.size(),
                                 (byte*)&signature[0]
    );
    signature.resize(siglen);

    data.cmd = message;
    data.signature = signature;
    std::cout << "\nCar:\nsing " << data.cmd << std::endl << "with: " << data.signature << std::endl;
    return data;
}

Data Car::emmit(Data data) {
    std::cout << "\nCar:\nemmit data" << std::endl;
    return data;
}

Data Car::share_pubKey() {
    std::cout << "\nCar:\nemmit pubkey" << std::endl;
    return Data({"", MAGIC_NUMB, c_publicKey});
}


