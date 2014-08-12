from setuptools import setup, Extension

setup(
    name="Handystats",
    author="noxiouz",
    license="GPL2",
    author_email="noxiouz@yandex.ru",
    ext_modules=[Extension("_handystats",
                 ["src/handystats.cpp"],
                 extra_compile_args=["-std=c++0x"],
                 libraries=['handystats'])],
)
