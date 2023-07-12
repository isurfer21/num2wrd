# num2wrd

> Number to Words convertor

A CLI app to convert a number into words using Indian numbering system.

## Motivation

This programme was developed during my college days in 2006 using **Turbo C++** as a module of my final year project. The motivation behind this project is to create plugable utility tool for another project.

## Install

This program was developed using Turbo C++ compiler on Windows XP. To run it on modern systems, you may need to use a DOS emulator like DOSBox. You can download Turbo C++ from [here](https://developerinsider.co/download-turbo-c-for-windows-7-8-8-1-and-windows-10-32-64-bit-full-screen/) and DOSBox from [here](https://www.dosbox.com/download.php?main=1).

## Build

To compile a program using Turbo C++, you can use the command line utility `tcc`. For example, if your program is named `num2wrd.cpp`, you can type `tcc num2wrd.cpp` in the command prompt to compile it. 

You may need to set up some environment variables to find header files and libraries. You can also use the Turbo C++ editor and press **Alt-F9** or go to the **Compile** tab and select **Compile** or **Build All**. 

If the compilation is successful, you will find an executable file with the same name as your program, such as `num2wrd.exe`. You can run it using a DOS emulator like DOSBox or directly from the Turbo C++ editor by pressing **Ctrl-F9** or going to the **Run** tab and selecting **Run**.

## Usage

It expects you to create `input.txt` file with a number, e.g.,

```
987654321
```

Execute the program via running this command.

```cmd
.\num2wrd.exe
```

The word equivalent of the given number is saved in `output.txt` file. Enjoy! 😊

## License

This program is free and open source and licensed under [GNU General Public License](.\LICENSE). You can use it for any purpose, but please give credit to the original author.