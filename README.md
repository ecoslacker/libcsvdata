# libcsvdata

`libcsvdata` is a library to read and write comma separated values (CSV) text files.
This is a common library in the irriapps project (<http://www.irriapps.com>) and some software from this site uses it. 

## Compiling

This project was created in C++ using `cmake`. To compile this project you can use the following instructions:

1. Clone the project from <https://github.com/ecoslacker/libcsvdata.git> ```git clone https://github.com/ecoslacker/libcsvdata.git```

2. Create a build directory, it maybe called whatever you want:

```
mkdir lib && cd lib
```

3. Run cmake, in Unix-like systems:

```
cmake .. -G "Unix Makefiles"
```

On Windows `nmake` is recommended instead of `mingw32-make` because there might be some errors related to the `gcc` compiler.

```
cmake .. -G "NMake Makefiles"
```

4. Compile, on Unix-like systems:

```
make
```

On Windows:

```
nmake
```

For more information about this and other useful software go to:

<http://www.irriapps.com/>

## License

```
libcsvdata
Read and write comma separated values (CSV) text files.

Copyright (C) 2018 Eduardo Jimenez <ecoslacker@irriapps.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
