
#include "../../common/vector_defines.h"

void vfadd_vv_f64_vec(double* vd, double* vs2, double* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        // gvl = __builtin_epi_vsetvl(n - i, __epi_e64, __epi_m1);
        gvl = vsetvl_e64m1(n - i)
        __epi_1xf64 v_vs1 = vle64_v_f64m1(&vs1[i]);
        __epi_1xf64 v_vs2 = vle64_v_f64m1(&vs2[i]);

        __epi_1xf64 v_res = vfadd_vv_f64m1(v_vs2, v_vs1);
        
        vse64_v_f64m1(&vd[i], v_res);
        i += gvl;
    }

    FENCE();
}