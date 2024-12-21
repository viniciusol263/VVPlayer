from conan import ConanFile
from conan.tools.cmake import CMakeDeps, CMakeToolchain
from conan.tools.cmake.layout import cmake_layout

class VVPlayerConanFile(ConanFile):
    name = "VVPlayer"
    version = "1.0"
    settings = "os","arch","compiler","build_type"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("sdl/2.30.9")

    def layout(self):
        cmake_layout(self)