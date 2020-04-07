#include "../getv_our.cpp"

int main(){
	uint32_t positives = 0, negatives = 0;
	volatile uint32_t res1[2];
	res1[1] = 0xFFFFFFFF;
	volatile uint32_t *res1Ptr = &res1[0];
	for(uint32_t i = 0; i < 1000; ++i){
		for(uint32_t a = 0; a < 0xFFFFFF; ++a){
			uint32_t b = a | 0x80000000;
			res1Ptr[0] = getv_our6((uint8_t *) res1Ptr);
		}
	}
	return 0;
}
