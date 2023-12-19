# OpenGL programmet - kompilation instrukser


## Linux

Installere følgende pakker vha din package manager

- glfw3
- libgl-dev
- mesa
- libx11 / libx11-dev
- make
- git

Kør følgende kommandoer

```
git clone https://github.com/RockRottenSalad/SOP-kode
cd ./SOP-kode/giant-gml-demo
make release build run
```


## Windows

### MSYS2 metoden

Download terminalen MSYS2

https://www.msys2.org/

Sørg for at køre x86_64 bit versionen(lilla ikon, ikke urct)

Kør følgende kommandoer

```
pacman -Syu

pacman -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-glfw git

git clone https://github.com/RockRottenSalad/SOP-kode

cd ./SOP-kode/giant-gml-demo

make release windows_build run

```

### CMAKE metoden

Download GLFW kilde kode

https://www.glfw.org/download.html

Følg denne guide - til og med "Linking" afsnittet

https://learnopengl.com/Getting-started/Creating-a-window
