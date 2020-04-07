#include <stdint.h>

int main(int argc, char ** argv) {
	for (int32_t i = 0; i < 1000; i++) {
		int64_t rdx;
		int64_t outer_res = rdx;
		int64_t res;
		for (int32_t j = 0; j < 0xffffff; j++) {
			unsigned char first_el = (char)outer_res;
			int64_t small_part = outer_res & -129;
			int64_t v;
			if (first_el >= 0) {
				int64_t v7; // bp-7
				int64_t ptr = &v7;
				unsigned char ce;
				int64_t v_copy = (int64_t)(ce & 0x7F) | (small_part << 7) & 0xffffff80;
				v = v_copy;
				while (ce >= 0) {
					ptr++;
					v_copy = (int64_t)(ce & 0x7F) | (v_copy << 7) & 0xffffff80;
					v = v_copy;
				}
			} else {
				v = small_part;
			}
			res = v & 0xffffffff ^ (first_el == 0 ? 0xffffffff : 0);
			outer_res = res;
		}
		rdx = res;
	}
	return 0;
}
