
#include <stdint.h>
#include "../../common/vector_defines.h"

void vfadd_vv_f64_vec(double* vd, double* vs2, double* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e64m1(n - i);
        _MMR_f64 v_vs1 = vle64_v_f64m1(&vs1[i], gvl);
        _MMR_f64 v_vs2 = vle64_v_f64m1(&vs2[i], gvl);
        _MMR_f64 v_res = vfadd_vv_f64m1(v_vs2, v_vs1, gvl);
        vse64_v_f64m1(&vd[i], v_res, gvl);
        i += gvl;
    }

    FENCE();
}

void vfsub_vv_f64_vec(double* vd, double* vs2, double* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e64m1(n - i);
        _MMR_f64 v_vs1 = vle64_v_f64m1(&vs1[i], gvl);
        _MMR_f64 v_vs2 = vle64_v_f64m1(&vs2[i], gvl);
        _MMR_f64 v_res = vfsub_vv_f64m1(v_vs2, v_vs1, gvl);
        vse64_v_f64m1(&vd[i], v_res, gvl);
        i += gvl;
    }

    FENCE();
}

void vfmv_v_f_f64_vec(double* vd, double* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e64m1(n - i);
        _MMR_f64 v_vs1 = vle64_v_f64m1(&vs1[i], gvl);
        _MMR_f64 v_res = vfmv_v_f_f64m1(v_vs1, gvl);
        vse64_v_f64m1(&vd[i], v_res, gvl);
        i += gvl;
    }
    FENCE();
}

void vmv_v_x_i64_vec(uint64_t* vd, uint64_t* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e64m1(n - i);
        _MMR_i64 v_vs1 = vle64_v_i64m1(&vs1[i], gvl);
        _MMR_i64 v_res = vfmv_v_f_f64m1(v_vs1, gvl);
        vse64_v_i64m1(&vd[i], v_res, gvl);
        i += gvl;
    }
    FENCE();
}