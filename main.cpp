//
// Created by ur0s on 10/13/20.
//



#include <iostream>
//using namespace std;

#include <cryptopp/eccrypto.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/osrng.h>
#include <cryptopp/oids.h>
//using namespace CryptoPP;

#include "Trinket.h"
#include "Car.h"


int main(int argc, char **argv) {
    using namespace CryptoPP;
    AutoSeededRandomPool prng;
    Trinket trinket("ololo");
    Car car("ololo");

    Data channel = trinket.to_sign("unlock");

    std::cout << "\n\n\n\n";
    car.receive_command(channel);




    return 0;
}




//    ECDSA<ECP, SHA256>::PrivateKey k1;
//    k1.Initialize( prng, ASN1::secp256r1() );
//    ECDSA<ECP, SHA256>::PublicKey publicKey;
//    k1.MakePublicKey(publicKey);
//    ECDSA<ECP, SHA256>::Verifier verifier(publicKey);
//    ECDSA<ECP, SHA256>::Signer signer(k1);
//
//    std::string message = "Do or do not. There is no try.";
//
//    size_t siglen = signer.MaxSignatureLength();
//    std::string signature(siglen, 0x00);
//    siglen = signer.SignMessage( prng, (const byte*)&message[0],
//                                 message.size(),
//                                 (byte*)&signature[0]
//                                 );
//    signature.resize(siglen);
//
//
//
//    bool result = verifier.VerifyMessage( (const byte*)&message[0],
//                                          message.size(),
//                                          (const byte*)&signature[0],
//                                          signature.size()
//                                          );

// Verification failure?
//    if( !result ) {
//        std::cout << "Failed to verify signature on message" << std::endl;
//    } else {
//        std::cout << "All good!" << std::endl;
//    }