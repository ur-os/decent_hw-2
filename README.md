# decent_hw-2

### Crypto++ 8.3.0
### Сборка библиотеки: 
```
git clone https://github.com/weidai11/cryptopp.git
cd cryptopp
wget -O CMakeLists.txt https://raw.githubusercontent.com/noloader/cryptopp-cmake/master/CMakeLists.txt
wget -O cryptopp-config.cmake https://raw.githubusercontent.com/noloader/cryptopp-cmake/master/cryptopp-config.cmake
mkdir build
cd build
cmake ..
make -j4
cryptest.exe v
```
Если все тесты пройдены успешно, то у вас будут 2 библиотеки:
```
libcryptopp.a
libcryptopp.so
```
Добавьте  ``` libcryptopp.so ``` в кэш библиотек, например 
```sudo cp libcryptopp.so /usr/local/lib/```

Обновите кэш библиотек ```sudo ldconfig```

Убедитесь, что бибиотека успешно добавилась: ```sudo ldconfig -p | grep libcryptopp```

