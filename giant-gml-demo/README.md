# OpenGL programmet - kompilation instrukser


## Linux

Installere følgende pakker vha. din package manager

- glfw3
- libgl-dev
- mesa
- libx11 / libx11-dev
- make
- git
- clang

Kør følgende kommandoer

```
git clone https://github.com/RockRottenSalad/SOP-kode
cd ./SOP-kode/giant-gml-demo
make release build run
```


## Windows

Download terminalen MSYS2

https://www.msys2.org/

Sørg for at køre x86_64 bit versionen(slutter med W64, blå ikon)

Kør følgende kommandoer

```
pacman -Syu

pacman -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-clang mingw-w64-clang-x86_64-mesa mingw-w64-x86_64-glfw git

git clone https://github.com/RockRottenSalad/SOP-kode

cd ./SOP-kode/giant-gml-demo

make release windows_build run

```

