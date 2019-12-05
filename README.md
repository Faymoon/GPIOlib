# GPIOlib

A c++ lib to interact with Raspberry Pi GPIOs.

## Compile

Symply execute
```bash
$ git clone https://github.com/Faymoon/GPIOlib
$ cd GPIOlib
$ premake5 [the way you want to compile]
```
To chose the premake action see the doc or `premake5 --help`.

I recommand you to use the gmake action and then compile like this on your Raspberry Pi. That :
```bash
$ premake5 gmake
$ cd build
$ make
```
should work.
