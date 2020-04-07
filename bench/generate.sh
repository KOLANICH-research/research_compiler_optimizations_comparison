set -e
for compiler in g++ clang++;do
	for a in knl corei7-avx athlon-fx bdver4 nano-x4 core2 icelake-server nocona nano-3000 core-avx-i bdver3 skylake-avx512 haswell cooperlake eden-x2 silvermont native goldmont k8 skylake k8-sse3 icelake-client slm btver2 core-avx2 nano-2000 tremont znver1 nano-x2 bdver2 x86-64 athlon64-sse3 btver1 westmere nano eden-x4 bonnell sandybridge bdver1 atom ivybridge opteron barcelona amdfam10 znver2 cannonlake skx tigerlake knm goldmont-plus nehalem corei7 nano-1000 broadwell penryn cascadelake opteron-sse3 athlon64; do
		echo $compiler $a;
		if $compiler -std=gnu++2a -ggdb -o ./bench -O3 -mtune=$a -march=$a ./bench.cpp; then
			python3 ./retdec/bin/retdec-decompiler.py --no-memory-limit --backend-aggressive-opts ./bench -o ./$compiler/$a.cpp;
			/usr/bin/time --format="time: $a $compiler %U" ./test;
			rm ./test;
		fi;
	done;
done;
