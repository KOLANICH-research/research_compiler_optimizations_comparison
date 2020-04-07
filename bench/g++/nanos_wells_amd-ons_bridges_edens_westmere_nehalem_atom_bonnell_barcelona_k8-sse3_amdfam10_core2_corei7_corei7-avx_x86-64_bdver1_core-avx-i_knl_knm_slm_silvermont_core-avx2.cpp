#include <stdbool.h>
#include <stdint.h>

int64_t main(void) {
	int32_t v6;
	int64_t i = &v6;
	int64_t v5 = __readfsqword(40);
	while (true) {
		int32_t j = 0xffffff;
		int32_t res;
		int32_t outer_res = res;
		int32_t res;
		while (true) {
			unsigned char first_el = (char)outer_res;
			int32_t small_part = outer_res & 0x7F;
			int32_t v;
			if (first_el >= 0) {
				int64_t ptr = 0;
				unsigned char ce;
				int32_t v_copy = (ce & 0x7F) | (small_part << 7);
				v = v_copy;
				while (ce >= 0) {
					ptr++;
					v_copy = (ce & 0x7F) | (v_copy << 7);
					v = v_copy;
				}
			} else {
				v = small_part;
			}
			res = v ^ (first_el == 0);
			int32_t j_new = j - 1;
			if (j_new == 0) {
				break;
			}
			j = j_new;
			outer_res = res;
		}
		uint32_t i_new = i - 1;
		i = i_new;
		if (i_new == 0) {
			break;
		}
		res = res;
	}
	if ((__readfsqword(40) ^ v5) != 0) {
		return some_shit();
	}
	return 0;
}

int64_t getv_our6(int64_t a1) {
	char first_el = a1;
	int64_t mask = first_el == 0 ? 0xffffffff : 0;
	int32_t small_part = a1 & 0x7F;
	if (first_el < 0) {
		return (int64_t)small_part ^ mask;
	}
	unsigned char ce = a1;
	int32_t v = (ce & 0x7F) | (small_part << 7);
	while (ce >= 0) {
		a1++;
		v = (ce & 0x7F) | (v << 7);
	}
	return (int64_t)v ^ mask;
}
