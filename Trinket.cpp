//
// Created by ur0s on 11/6/20.
//

#include "Trinket.h"

#include <utility>

Trinket::Trinket(std::string serial_number) {
    serial_n = std::move(serial_number);
    t_privateKey.Initialize(prng, ASN1::secp256r1() );
    t_privateKey.MakePublicKey(t_publicKey);
}

Data Trinket::to_sign(std::string cmd) {
    std::cout << "\nTRINKET\n";

    ECDSA<ECP, SHA256>::Verifier verifier(t_publicKey);
    ECDSA<ECP, SHA256>::Signer signer(t_privateKey);

    std::string message = cmd;

    size_t siglen = signer.MaxSignatureLength();
    std::string signature(siglen, 0x00);
    siglen = signer.SignMessage( prng, (const byte*)&message[0],
                                 message.size(),
                                 (byte*)&signature[0]
    );
    signature.resize(siglen);



    bool result = verifier.VerifyMessage( (const byte*)&message[0],
                                          message.size(),
                                          (const byte*)&signature[0],
                                          signature.size()
    );

    Data data = {"", ""};
    if( !result ) {
        std::cout << "Failed to verify signature on message" << std::endl;
    } else {
        std::cout << "All good!\ncontent: " << message << "\nsignature: " << signature << std::endl;
        data = {message, signature, t_publicKey};
    }

    return (data);

}

Data Trinket::receive_command(Data data_channel) {
    std::string message = data_channel.cmd;
    std::string signature = data_channel.signature;
    ECDSA<ECP, SHA256>::Verifier verifier(t_publicKey);
    bool result = verifier.VerifyMessage( (const byte*)&message[0],
                                          message.size(),
                                          (const byte*)&signature[0],
                                          signature.size()
    );

    Data data = {"", ""};
    if( !result ) {
        std::cout << "FUCKUP" << std::endl;
    } else {
        std::cout << "\nPASS!\ncontent: " << message << "\nsignature: " << signature << std::endl;
        data = {message, signature};
    }

    return Data();
}

Data Trinket::send_pubKey() {
    Data d = {"", "", t_publicKey};
    return(d);
}

Data Trinket::send_data(const Data& data) {
    return Data();
}
