This codebase provides some C-APIs utilizing `scipy` methods. `scipy` versuib `v1.1.0` is used.

To use the package, firstly run

```
make
```

which will download scipy source code, and then compile a `libndimage.so` shared libary in the current directory.

Then, move the library to somewhere the linker can find, e.g.

```
sudo ln libndimage.so /usr/local/lib/libndimage.so
```
