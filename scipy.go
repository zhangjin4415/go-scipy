package scipy

// #cgo LDFLAGS: -lgoscipy
// #include "c/scipy.h"
import "C"

// Initialize ...
func Initialize() {
	C.initialize()
}

// Finalize ...
func Finalize() {
	C.finalize()
}
