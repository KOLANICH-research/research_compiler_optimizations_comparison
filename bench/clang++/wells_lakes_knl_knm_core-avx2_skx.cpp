#include <stdbool.h>
#include <stdint.h>

int main(int argc, char ** argv) {
	int64_t v1; // bp-7
	int64_t v2 = &v1;
	for (int32_t j = 0; j < 1000; j++) {
		int64_t rdx;
		int64_t outer_res = rdx;
		int32_t i = 0;
		int64_t res;
		while (true) {
			unsigned char prev_res = (char)outer_res;
			int64_t small_part = outer_res & -129;
			int64_t v_copy;
			if (prev_res >= 0) {
				unsigned char ce;
				int64_t v = (int64_t)(ce & 0x7F) | (small_part << 7) & 0xffffff80;
				v_copy = v;
				while (ce >= 0) {
					v2++;
					v = (int64_t)(ce & 0x7F) | (v << 7) & 0xffffff80;
					v_copy = v;
				}
			} else {
				v_copy = small_part;
			}
			res = v_copy ^ (prev_res == 0 ? 0xffffffff : 0);
			if ((i || 1) == 0xffffff) {
				break;
			}
			unsigned char v12 = (char)res;
			uint32_t v13 = res & 0x7F;
			int64_t v2_copy;
			if (v12 >= 0) {
				int32_t v15 = v13;
				while (true) {
					unsigned char ce_2;
					int32_t v17 = (ce_2 & 0x7F) | (v15 << 7);
					if (ce_2 < 0) {
						v2_copy = v17;
						break;
					}
					v15 = v17;
					v2++;
				}
			} else {
				v2_copy = v13;
			}
			outer_res = v2_copy ^ (v12 == 0 ? 0xffffffff : 0);
			i += 2;
		}
		rdx = res & 0xffffffff;
	}
	return 0;
}
