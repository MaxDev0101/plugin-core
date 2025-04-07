# plugin-core

plugin-core is a collection of helpful algorithms for vst3 plugin development

## Getting Started

To clone and create the project, open a command prompt and proceed as follows:

### Windows

```sh
git clone https://github.com/maxdev0101/plugin-core.git
mkdir build
cd build
cmake ../plugin-core
cmake --build .
```

### macOS

```sh
git clone https://github.com/maxdev0101/plugin-core.git
mkdir build
cd build
cmake -GXcode ../plugin-core
cmake --build .
```

### Linux

```sh
git clone https://github.com/maxdev0101/plugin-core.git
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ../plugin-core
cmake --build .
```

As soon as the project has been successfully built, you will find the google test executable in the build folder: ```Debug/plugin-core-googletest```

## Further Infos
>See also: https://github.com/steinbergmedia/vst3sdk