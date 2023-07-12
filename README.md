# num2wrd

> Number to Words convertor

A CLI app to convert a number into words using Indian numbering system.

## Motivation

This programme was developed during my college days in 2006 using **Turbo C++** as a module of my final year project. The motivation behind this project is to create plugable utility tool for another project.

## Build

You can build this program as an executable file or a WebAssembly binary (WASI). Since WASI binary is cross-platform, so we'll go with that.

To build this program as a WASI (WebAssembly System Interface), you need to have the WASI SDK installed on your system. The WASI SDK is a collection of tools and libraries that enable you to compile and run WebAssembly programs on different platforms. You can follow the instructions from [wasi-sdk-setup](https://github.com/isurfer21/wasi-sdk-setup) to set up the WASI SDK.

To compile the source code file `num2wrd.cpp` into a WebAssembly binary file `num2wrd.wasm`, open a terminal or command prompt and run the following command:

```shell
wasi clang++ num2wrd.cpp -o num2wrd.wasm
```

This will create a file named `num2wrd.wasm` in the same directory as the source code file.

## Usage

To execute this program as a WASI, you need to have [wasmtime](https://wasmtime.dev/) installed on your system. You can download it from [here](https://wasmtime.dev/).

To run the WebAssembly binary file `num2wrd.wasm`, open a terminal or command prompt and run the following command:

```cmd
wasmtime num2wrd.wasm
```

It will ask you to enter a number. Then it converts the number into words and show the result on the screen. Enjoy! 😊

## License

This program is free and open source and licensed under [GNU General Public License](.\LICENSE). You can use it for any purpose, but please give credit to the original author.