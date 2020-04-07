#include <stdint.h>


int32_t getv_our6(uint8_t *ptr_) {
	uint8_t ce = *ptr_;
	int32_t mask =  ce ? 0 : ~0;

	int32_t v = (ce & 0x7F);
	while (! (ce & 0x80)){
		++ptr_;
		ce = *ptr_;
		v = (v << 7) | (ce & 0x7F);
	}

	return v ^ mask;
}
