#ifndef NDIMAGE_H
#define NDIMAGE_H

// resize3d proxy `scipy.ndimage.zoom`
// for scipy doc refer to: https://docs.scipy.org/doc/scipy-1.1.0/reference/generated/scipy.ndimage.zoom.html#scipy.ndimage.zoom
// `mode`:
//      nearest: 0
//      wrap: 1
//      reflect: 2
//      mirror: 3
//      constant: 4
// refer to https://github.com/scipy/scipy/blob/maintenance/1.1.x/scipy/ndimage/src/ni_support.h#L53
void resize3d(double *in, int d_in, int h_in, int w_in, int mode, int d_out, int h_out, int w_out, long long *out);

#endif
