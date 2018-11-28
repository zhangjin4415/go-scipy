#include "Python.h"

// including `nd_image.h` before `numpy/ndarrayobject.h` is crucial.
// refer to https://docs.scipy.org/doc/numpy/reference/c-api.array.html?highlight=import_array#c.PY_ARRAY_UNIQUE_SYMBOL
#include "nd_image.h"
#include "numpy/ndarrayobject.h"

void initialize(void) {
    Py_Initialize();
    _import_array();
}

void finalize(void) {
    Py_Finalize();
}