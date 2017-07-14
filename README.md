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
emcc hello.c -s WASM=1 -o target/hello.html
```

#### To run it simply serve the folder
You can use
```
emrun --no_browser --port 8080 .
```