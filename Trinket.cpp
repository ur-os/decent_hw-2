//
// Created by ur0s on 11/6/20.
//

#include "Trinket.h"


Trinket::Trinket() {
    t_privateKey.Initialize(prng, ASN1::secp256r1());
    t_privateKey.MakePublicKey(t_publicKey);
    std::cout << "\nTrinket:\ngenerate self keys" << std::endl;

}

bool Trinket::receive(Data channel) {
    std::cout << "\nTrinket:\n" << "receive:\ncommand: \"" << channel.cmd << "\"\nwith: \""<< channel.signature << "\"\n";
    if(channel.signature == MAGIC_NUMB) {
        t_publicKey = channel.publicKey;
        std::cout << "\nTrinket:\n" << "trinket pubKey was setup" << std::endl;
        return true;
    }
    if(verify(channel)) {
        execute(channel.cmd);
        return true;
    }

    return false;
}

Data Trinket::share_pubKey() {
    std::cout << "\nTrinket:\nemmit pubkey" << std::endl;
    return Data({"", MAGIC_NUMB, t_publicKey});
}

void Trinket::execute(const std::string& cmd) {
    std::cout << "\nTrinket:\nexecute command:\n" << cmd << std::endl;
}

bool Trinket::verify(Data channel) {
    std::string message = channel.cmd;
    std::string signature = channel.signature;
    ECDSA<ECP, SHA256>::Verifier verifier(c_publicKey);

    bool result = verifier.VerifyMessage( (const byte*)&message[0],
                                          message.size(),
                                          (const byte*)&signature[0],
                                          signature.size()
    );

    result ? std::cout << "\nTrinket:\nauthenticated successful\n" : std::cout << "\nTrinket:\nauthenticated failed\n";
    return result;
}

Data Trinket::emmit(Data data) {
    std::cout << "\nTrinket:\nemmit data" << std::endl;
    return data;
}

Data Trinket::sign(Data data) {
    ECDSA<ECP, SHA256>::Signer signer(t_privateKey);
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
    std::cout << "\nTrinket:\nsing: \"" << data.cmd << "\"\nwith: \"" << data.signature << "\"\n";
    return data;
}
