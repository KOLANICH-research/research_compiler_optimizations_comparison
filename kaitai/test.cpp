#include <stdint.h>
#include <iostream>
#include <sstream>
#include "metakit4_vlq_base128_be.h"

#include "../getv_our.cpp"

int main(){
	std::stringstream ss;
	uint32_t b = 0xDEADBEEF;
	uint32_t * c = &b;
	ss.rdbuf()->pubsetbuf((char *)c, sizeof(b));
	for(uint32_t i = 0;i < 6; ++i){
		for(uint32_t a = 0;a < 0xFFFFFF; ++a){
			ss.seekg(0);
			b = a | 0x80000000;
			kaitai::kstream s((std::istream *) &ss);
			metakit4_vlq_base128_be_t parsed(&s);
			auto etalon = getv_our6((uint8_t *) c);
			if(parsed.value() != etalon){
				std::cout << std::hex << etalon << " " << parsed.value() << std::endl;
				return 1;
			}
		}
	}
	std::cout << "OK" << std::endl;
	return 0;
}
