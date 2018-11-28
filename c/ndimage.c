#include <stdio.h>

#include "Python.h"

// including `nd_image.h` before `numpy/ndarrayobject.h` is crucial.
// refer to https://docs.scipy.org/doc/numpy/reference/c-api.array.html?highlight=import_array#c.PY_ARRAY_UNIQUE_SYMBOL
#include "nd_image.h"
#include "numpy/ndarrayobject.h"

#include "ni_support.h"
#include "ni_interpolation.h"

// resize3d proxy `scipy.ndimage.zoom`
// doc: https://docs.scipy.org/doc/scipy-1.1.0/reference/generated/scipy.ndimage.zoom.html#scipy.ndimage.zoom
// python source: https://github.com/scipy/scipy/blob/maintenance/1.1.x/scipy/ndimage/interpolation.py#L515
// which essentially uses the C method at https://github.com/scipy/scipy/blob/maintenance/1.1.x/scipy/ndimage/src/ni_interpolation.c#L573
void resize3d(double *in, int d_in, int h_in, int w_in, int mode, int d_out, int h_out, int w_out, long long *out) {
    Py_Initialize();
    _import_array();

    // spline filter the input image for order 3 by default
    // refer to https://github.com/scipy/scipy/blob/maintenance/1.1.x/scipy/ndimage/interpolation.py#L570
    npy_intp dims[3] = {d_in, w_in, h_in};
    PyArrayObject *pyin = (PyArrayObject *)PyArray_SimpleNewFromData(3, dims, NPY_DOUBLE, in);
    for (int d = 0; d < 3; d++) {
        NI_SplineFilter1D(pyin, 3, d, pyin);
    }

    // zoom array is calculated in such way.
    // refer to https://github.com/scipy/scipy/blob/maintenance/1.1.x/scipy/ndimage/interpolation.py#L588
    double zoom[3] = {
        (d_in - 1.0) / (d_out - 1.0),
        (w_in - 1.0) / (w_out - 1.0),
        (h_in - 1.0) / (h_out - 1.0), 
    };

    npy_intp zoom_dims[1] = {3};
    PyArrayObject *zoom_arr = (PyArrayObject *)PyArray_SimpleNewFromData(1, zoom_dims, NPY_DOUBLE, zoom);

    npy_intp out_dims[3] = {d_out, w_out, h_out};
    PyArrayObject *pyout = (PyArrayObject *)PyArray_SimpleNewFromData(3, out_dims, NPY_LONGLONG, out);

    NI_ZoomShift(pyin, zoom_arr, NULL, pyout, 3, mode, 0);
    Py_Finalize();
}
