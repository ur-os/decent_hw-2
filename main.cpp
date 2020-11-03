//
// Created by ur0s on 10/13/20.
//



#include <iostream>
#include <cryptopp/integer.h>
using namespace std;


typedef struct pair {
    int serial_key_trinket;
    int serial_key_car;
} pair_serial_keys;

int main(int argc, char **argv) {
    pair_serial_keys pair;

    // to_produce_car_with_trinket(&) {
        // var serial_key_trinket = gen_random(0, INT_MAX);
        // var serial_key_car = serial_key_trinket;
    //}
    // establish_session() {
        //gen_pub_sec_keys
        // var t_pub
        // var t_sec

        //gen_pub_sec_keys
        // var c_pub
        // var c_sec

        // text channel;
        // channel = encrypt_ecdh(t_pub, t_sec)

        //
    // }



    CryptoPP::Integer m("4294967295"), n("0x1000000000000000000000000000000"), j;
    j = 1999;

    cout << "n+m: " << std::hex << n + m << endl;
    cout << "n-m: " << std::hex << n - m << endl;
    cout << "n*m: " << std::hex << n * m << endl;
    cout << "n%m: " << std::hex << n % m << endl;

    cout << "(n*m)%j:" << std::hex << a_times_b_mod_c(n,m,j) << endl;
    cout << "(n^m)%j:" << std::hex << a_exp_b_mod_c(n,m,j) << endl;






//    a.Encode();
    return 0;
}