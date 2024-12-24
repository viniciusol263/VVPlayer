from conan import ConanFile
from conan.tools.cmake import CMakeDeps, CMakeToolchain
from conan.tools.cmake.layout import cmake_layout

class VVPlayerConanFile(ConanFile):
    name = "VVPlayer"
    version = "1.0"
    settings = "os","arch","compiler","build_type"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("sfml/2.6.2")
        self.requires("zlib/1.3.1", force=True)

    def configure(self):
        self.options["sfml/*"].audio = True
        self.options["sfml/*"].shared = False
        self.options["sfml/*"].window = True
        self.options["sfml/*"].network = True
        self.options["sfml/*"].graphics = True

    def layout(self):
        cmake_layout(self)