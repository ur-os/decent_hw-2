//
// Created by ur0s on 11/6/20.
//

#include "Car.h"

bool Car::receive_command(const Data& data_channel) {
    std::cout << "\nCAR\n";

    std::string message = data_channel.cmd;
    std::string signature = data_channel.signature;
    ECDSA<ECP, SHA256>::Verifier verifier(data_channel.publicKey);

    bool result = verifier.VerifyMessage( (const byte*)&message[0],
                                          message.size(),
                                          (const byte*)&signature[0],
                                          signature.size()
    );

    Data data = {"", ""};
    if( !result ) {
        std::cout << "FUCKUP" << std::endl;
        return false;
    } else {
        std::cout << "\nPASS!" << std::endl;
    }

    std::cout << "content: " << message << "\nsignature: " << signature;
    return true;
}

Car::Car(std::string serial_number) {
    serial_n = std::move(serial_number);
    k1.Initialize( prng, ASN1::secp256r1() );
    k1.MakePublicKey(publicKey);
}
