# Description

This codebase provides some C-APIs utilizing `scipy` methods. `scipy` versuib `v1.1.0` is used.

# Install

To use the package, firstly run

```
make
```

which will download scipy source code, and then compile a `libgoscipy.so` shared libary in the current directory. Then, move the library to somewhere the linker can find, e.g. link to `/usr/local/lib`.

# Usage

Before using other APIs, `Initialize` must be called once.

After using, `Finalize` must be called once.
