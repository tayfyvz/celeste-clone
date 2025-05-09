#!/bin/bash

libs=-luser32
warnings="-Wno-writable-strings -Wno-format-security -Wno-deprecated-declarations -Wno-switch"

clang++ -g src/main.cpp -otadpole.exe $libs $warnings