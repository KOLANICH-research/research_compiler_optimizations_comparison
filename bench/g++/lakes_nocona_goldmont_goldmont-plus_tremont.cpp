#include <stdbool.h>
#include <stdint.h>

int64_t main(void) {
	int64_t v5 = __readfsqword(40);
	int32_t v6;
	int32_t i = &v6;
	while (true) {
		int32_t j = 0xffffff;
		int32_t outer_res;
		int32_t res_copy_2 = outer_res;
		int32_t res;
		while (true) {
			unsigned char res_copy = (char)res_copy_2;
			int32_t small_part = res_copy_2 & 0x7F;
			int32_t v;
			if (res_copy >= 0) {
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
			res = v ^ (res_copy == 0);
			int32_t j_new = j - 1;
			if (j_new == 0) {
				break;
			}
			j = j_new;
			res_copy_2 = res;
		}
		int32_t i_new = i - 1;
		if (i_new == 0) {
			break;
		}
		outer_res = res;
		i = i_new;
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
	unsigned char ce;
	int32_t v = (ce & 0x7F) | (small_part << 7);
	while (ce >= 0) {
		a1++;
		v = (ce & 0x7F) | (v << 7);
	}
	return (int64_t)v ^ mask;
}
