Comparison of compilers optimizations for different microarchitectures
======================================================================

1. A simple benchmark program has been created. The program benchmarks performance of variable-length integer from metakit4 database. The first version walked all the numbers, but the compilers have optimized that loop out because the result were unused, so I had to chain the results to prevent them from being eliminated.
2. Binaries compiled for some microachs have been benchmarked. The data has been collected. The format of the data in the tsv files is as follows: rows are microarchs, columns are compilers, numbers are seconds per full sweeps from 0 to 0xFFFFFFFF (the count of full sweeps iterations has been changed, so we divide the time got by `/usr/bin/time` to count of sweeps).
3. A bash script has been created compiling the program with optimizations to all the x86_64 microarchitectures supported by the compilers with -O3 and then decompilign them with retdec.
4. From the results comments have been removed, identical files has been merged, keeping track what has been merged to what.
5. All the code that is out of scope have been removed, the functions have been renamed. Again, identical files have been merged.

```dot

# clang
atom -> atom_bonnell;
bonnell-> atom_bonnell;

goldmont-plus -> goldmont-plus_silvermont_slm_goldmont_tremont;
goldmont -> goldmont-plus_silvermont_slm_goldmont_tremont;
silvermont -> goldmont-plus_silvermont_slm_goldmont_tremont;
tremont -> goldmont-plus_silvermont_slm_goldmont_tremont;

bdver1 -> bdver1_znver2_bdver2_znver1;
znver2 -> bdver1_znver2_bdver2_znver1;
bdver2 -> bdver1_znver2_bdver2_znver1;
znver1 -> bdver1_znver2_bdver2_znver1;

btver2 -> btver2_nocona;
nocona -> btver2_nocona;

atom_bonnell -> native_amd-ons_bridges_slm_bds_zns_bts_monts_westmere_nehalem_atom_bonnell_barcelona_k8_k8-sse3_amdfam10_core2_corei7_corei7-avx_x86-64_penryn_nocona;
goldmont-plus_silvermont_slm_goldmont_tremont -> native_amd-ons_bridges_slm_bds_zns_bts_monts_westmere_nehalem_atom_bonnell_barcelona_k8_k8-sse3_amdfam10_core2_corei7_corei7-avx_x86-64_penryn_nocona;
bdver1_znver2_bdver2_znver1 -> native_amd-ons_bridges_slm_bds_zns_bts_monts_westmere_nehalem_atom_bonnell_barcelona_k8_k8-sse3_amdfam10_core2_corei7_corei7-avx_x86-64_penryn_nocona;
btver2_nocona -> native_amd-ons_bridges_slm_bds_zns_bts_monts_westmere_nehalem_atom_bonnell_barcelona_k8_k8-sse3_amdfam10_core2_corei7_corei7-avx_x86-64_penryn_nocona;
x86-64 -> native_amd-ons_bridges_slm_bds_zns_bts_monts_westmere_nehalem_atom_bonnell_barcelona_k8_k8-sse3_amdfam10_core2_corei7_corei7-avx_x86-64_penryn_nocona;

knl -> knl_knm;
knm -> knl_knm;

wells -> wells_lakes_core-avx2_skx;
lakes -> wells_lakes_core-avx2_skx;
core-avx2 -> wells_lakes_core-avx2_skx;
skx -> wells_lakes_core-avx2_skx;

# gcc
btver1 -> native_btver1_btver2_bdver2_bdver3_bdver4;
btver2 -> native_btver1_btver2_bdver2_bdver3_bdver4;
bdver2 -> native_btver1_btver2_bdver2_bdver3_bdver4;
bdver3 -> native_btver1_btver2_bdver2_bdver3_bdver4;
bdver4 -> native_btver1_btver2_bdver2_bdver3_bdver4;

znver1 -> znver1_znver2;
znver2 -> znver1_znver2;

native_btver1_btver2_bdver2_bdver3_bdver4 -> native_bts_zns_bdver2_bdver3_bdver4;
znver1_znver2 -> native_bts_zns_bdver2_bdver3_bdver4;

nanos -> nanos_edens_athlons_opterons_k8-sse3;
edens -> nanos_edens_athlons_opterons_k8-sse3;
athlons -> nanos_edens_athlons_opterons_k8-sse3;
opterons -> nanos_edens_athlons_opterons_k8-sse3;
k8-sse3 -> nanos_edens_athlons_opterons_k8-sse3;

knl -> knl_knm_slm_bonnell_silvermont_atom;
knm -> knl_knm_slm_bonnell_silvermont_atom;
slm-> knl_knm_slm_bonnell_silvermont_atom;
bonnell -> knl_knm_slm_bonnell_silvermont_atom;
silvermont -> knl_knm_slm_bonnell_silvermont_atom;
atom -> knl_knm_slm_bonnell_silvermont_atom;

amdfam10 -> amdfam10_barcelona;
barcelona -> amdfam10_barcelona;

wells -> wells_core-avx2;
core-avx2 -> wells_core-avx2;

core2 -> core2_corei7_nehalem_westmere;
corei7 -> core2_corei7_nehalem_westmere;
nehalem -> core2_corei7_nehalem_westmere;
westmere -> core2_corei7_nehalem_westmere;

x86-64 -> x86-64_bridges_core-avx-i_corei7-avx;
bridges -> x86-64_bridges_core-avx-i_corei7-avx;
core-avx-i -> x86-64_bridges_core-avx-i_corei7-avx;
corei7-avx -> x86-64_bridges_core-avx-i_corei7-avx;

bdver1 -> nanos_wells_amd-ons_bridges_edens_westmere_nehalem_atom_bonnell_barcelona_k8-sse3_amdfam10_core2_corei7_corei7-avx_x86-64_bdver1_core-avx-i_knl_knm_slm_silvermont_core-avx2;
x86-64_bridges_core-avx-i_corei7-avx -> nanos_wells_amd-ons_bridges_edens_westmere_nehalem_atom_bonnell_barcelona_k8-sse3_amdfam10_core2_corei7_corei7-avx_x86-64_bdver1_core-avx-i_knl_knm_slm_silvermont_core-avx2;
core2_corei7_nehalem_westmere -> nanos_wells_amd-ons_bridges_edens_westmere_nehalem_atom_bonnell_barcelona_k8-sse3_amdfam10_core2_corei7_corei7-avx_x86-64_bdver1_core-avx-i_knl_knm_slm_silvermont_core-avx2;
wells_core-avx2 -> nanos_wells_amd-ons_bridges_edens_westmere_nehalem_atom_bonnell_barcelona_k8-sse3_amdfam10_core2_corei7_corei7-avx_x86-64_bdver1_core-avx-i_knl_knm_slm_silvermont_core-avx2;
amdfam10_barcelona -> nanos_wells_amd-ons_bridges_edens_westmere_nehalem_atom_bonnell_barcelona_k8-sse3_amdfam10_core2_corei7_corei7-avx_x86-64_bdver1_core-avx-i_knl_knm_slm_silvermont_core-avx2;
knl_knm_slm_bonnell_silvermont_atom -> nanos_wells_amd-ons_bridges_edens_westmere_nehalem_atom_bonnell_barcelona_k8-sse3_amdfam10_core2_corei7_corei7-avx_x86-64_bdver1_core-avx-i_knl_knm_slm_silvermont_core-avx2;
nanos_edens_athlons_opterons_k8-sse3 -> nanos_wells_amd-ons_bridges_edens_westmere_nehalem_atom_bonnell_barcelona_k8-sse3_amdfam10_core2_corei7_corei7-avx_x86-64_bdver1_core-avx-i_knl_knm_slm_silvermont_core-avx2;

goldmont -> goldmont_goldmont-plus_tremont;
goldmont-plus -> goldmont_goldmont-plus_tremont;
tremont -> goldmont_goldmont-plus_tremont;

goldmont_goldmont-plus_tremont -> lakes_nocona_goldmont_goldmont-plus_tremont;
lakes -> lakes_nocona_goldmont_goldmont-plus_tremont;
nocona -> lakes_nocona_goldmont_goldmont-plus_tremont;
```

6. In each source variables have been renamed to correspond the ones in other sources.
7. The resulting sources have been compared to each other.

Discussion
----------

1. Retdec is currently not very finished. Decompilation of results by g++ is pretty incorrect and junked, decompiled listing is doing mad things not present in the original source and not doing the things present in it. Debug information is pretty unused.
2. For clang there are 2 variants of high-level code:
	* straightforward one with uint64_t body;
	* doubled, when there are 2 loops, probably to better utilize CPU units, one loop is uint64_t variant of a straightforward loop, an additional one is uint32_t one
3. For gcc thee are 3 variants, lookng at high level very similar to each other (with uint32_t loop body), differing by some details:
	* instructions order
	* bitness of variables
	* usage of additional variables
	* preferred ways to check if the highest bit is set
4. g++ code looks pretty similar to clang++ straightforward code. Differences between them are the same as between gcc variants.
