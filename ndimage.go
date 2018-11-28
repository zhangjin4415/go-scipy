package scipy

// #cgo LDFLAGS: -lndimage
// #include "c/ndimage.h"
import "C"
import "unsafe"

// Mode ...
type Mode int

// ...
const (
	Nearest  Mode = 0
	Wrap          = 1
	Reflect       = 2
	Mirror        = 3
	Constant      = 4
)

// Resize3D ...
func Resize3D(in []int64, inD, inH, inW, outD, outH, outW int, mode Mode) (out []int64, err error) {
	var inDouble []float64
	for _, v := range in {
		inDouble = append(inDouble, float64(v))
	}

	out = make([]int64, outD*outH*outW)

	C.resize3d(
		(*C.double)(unsafe.Pointer(&inDouble[0])),
		C.int(inD),
		C.int(inH),
		C.int(inW),
		C.int(mode),
		C.int(outD),
		C.int(outH),
		C.int(outW),
		(*C.longlong)(unsafe.Pointer(&out[0])),
	)

	return
}
