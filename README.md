# Pong game with SDL2

## Prerequisite

- CMake (version 3.1 or higher)
- vcpkg

## Build

```sh
# Build CMake files.
$ cmake -B cmake-build-debug -S . -DVCPKG_TARGET=x64-mingw-dynamic -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake -G "MinGW Makefiles"

# Compile and run.
$ cmake --build cmake-build-debug && bin\Ponging.exe
```

