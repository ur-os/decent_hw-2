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
    Data channel;

      // initialize by manufacturer in secure
    Trinket trinket;
    Car car;

    channel = trinket.share_pubKey();
    car.receive(channel);
    channel = car.share_pubKey();
    trinket.receive(channel);
    channel = {"", ""};

      // in common use with open channel
    channel = trinket.emmit(trinket.sign({"unlock"}));

      // hacker Retr0 try edit command in case "man in middle"
    //channel.cmd = "blow up";

    std::cout << car.receive(channel);
    std::cout << car.receive(channel);
    return 0;
}



