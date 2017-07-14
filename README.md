# WebAssembly 101
based on [webassembly.org](http://webassembly.org/getting-started/developers-guide/) guide

## Getting started
#### Pre reqs
1. Install [CMake](cmkage.org) using brew ```brew install cmake```
1. Make sure XCode is unstalled (or any other GCC C++ compiler)
1. Make sure python version 2.7.x is installed

#### Clone EMSCRIPTEN
```
    git clone https://github.com/juj/emsdk.git
    cd emsdk
    ./emsdk install sdk-incoming-64bit binaryen-master-64bit
    ./emsdk activate sdk-incoming-64bit binaryen-master-64bit
```

Once installation is done (might take a while), you should use the following command to enter an Emscripten compiler command prompt
```
source ./emsdk_env.sh
```
* note that it will ovveride the node version that you are using to 4.x

#### Compiling a file
Use the following command

```
mkdir target
emcc hello.c -s WASM=1 -O3 -o target/hello.js
```
By default it will put it in a global variable named Module

To make it a module and change it's name use the following command
```
emcc hello.c -s WASM=1 -O3 -o target/hello.js -s EXPORT_NAME="'TestModule'" -s MODULARIZE=1
```
You will then need to create a new instance of TestModule

#### To run it simply serve the folder
You can use
```
emrun --no_browser --port 8080 .
```

## Soures to check
* [using AMD with WASM](https://stackoverflow.com/questions/29329240/emscripten-with-module-loaders/29332498#29332498)