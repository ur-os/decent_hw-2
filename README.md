## Домашнее задание №2

#### Сборка с помощью cmake:
```console
$ git clone git@github.com:ur-os/decent_hw-2.git
$ cd hw-2_ur0s && mkdir build && cd build
$ cmake ./
$ make
```

#### Использование:
```console
$ ./hw-2_ur0s
```

#### Краткое описание:
  Основная мысль протокола состоит в том, что первый обмен 
  публичными ключами произойдёт до того, как злоумышленник 
  смог вы вмешаться в работу. Далее все действия происходят 
  с ЭЦП. 
  Протокол использует алгоритм цифровой подписи на 
  эллиптической кривой ```secp256r1```. 
  
  Два устройства инициализируются на заводе, и обмениваются публичными ключами,
  после чего передаваемые сообщения преобретают стойкость к подделыванию.
  
  Формат передаваемых даных описан в Utils, и имеет 3 используемых поля:
   - command (текст передаваемой команды)
   - signature (собственно ЭЦП подпись)
   - publicKey (опциональное поле для передачи ключа в формате библиотеки Crypto++)
  
#### Тестовый пример:
  **1. Процесс инициализации, и обмена ключами на заводе:**
  
  ![Image alt](https://sun9-48.userapi.com/aVxe8p9z1icpGHDjxFxfwYk9vqhhxyQx-mPgHA/w7uT6IjnuRg.jpg)
  
  **2. Легальный процесс выполнения команды разблокировки:**
  
  ![Image alt](https://sun9-41.userapi.com/ZpLdiYyiZVCDo1YjoPD474HBoxJyfJdZdzm1xQ/0n9M2mnjI78.jpg)
  
  **3. Попытка хакера взорвать машину, подменив команду в сообщении:**
  
  ![Image alt](https://sun9-16.userapi.com/W7otmGfvBVaDsX1X_QTXbNJbLLDvfEHV10XjCg/YPItzQbQIoY.jpg)

#### Crypto++ 8.3.0
#### Сборка библиотеки: 
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

