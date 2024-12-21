![badge](https://github.com/viniciusol263/VVPlayer/actions/workflows/cmake-single-platform.yml/badge.svg)

# VVPlayer
VVPlayer(Vini Video Player) is a high-performance and high-compability C++23 video player.

## Dependencies
* C++23 MVSC Compiler
* Conan 2

## How to Build
```bash
    cd VVPlayer
    conan install . -pr=conanprofile

    cmake -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DCMAKE_TOOLCHAIN_FILE=generators/conan_toolchain.cmake -SD:/Projects/VVPlayer -BD:/Projects/VVPlayer/build -G "Visual Studio 17 2022"
    cmake --build D:/Projects/VVPlayer/build --config Release --target VVPlayer --
```