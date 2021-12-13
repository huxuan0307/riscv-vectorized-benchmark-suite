
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

void vfmul_vv_f64_vec(double* vd, double* vs2, double* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e64m1(n - i);
        _MMR_f64 v_vs1 = vle64_v_f64m1(&vs1[i], gvl);
        _MMR_f64 v_vs2 = vle64_v_f64m1(&vs2[i], gvl);
        _MMR_f64 v_res = vfmul_vv_f64m1(v_vs2, v_vs1, gvl);
        vse64_v_f64m1(&vd[i], v_res, gvl);
        i += gvl;
    }

    FENCE();
}

void vfmadd_vv_f64_vec(double* vd, double* vs2, double* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e64m1(n - i);
        _MMR_f64 v_vs1 = vle64_v_f64m1(&vs1[i], gvl);
        _MMR_f64 v_vs2 = vle64_v_f64m1(&vs2[i], gvl);
        _MMR_f64 v_vd  = vle64_v_f64m1(&vd[i],  gvl);
        _MMR_f64 v_res = vfmadd_vv_f64m1(v_vd, v_vs1, v_vs2, gvl);
        vse64_v_f64m1(&vd[i], v_res, gvl);
        i += gvl;
    }

    FENCE();
}

void vfmacc_vv_f64_vec(double* vd, double* vs2, double* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e64m1(n - i);
        _MMR_f64 v_vs1 = vle64_v_f64m1(&vs1[i], gvl);
        _MMR_f64 v_vs2 = vle64_v_f64m1(&vs2[i], gvl);
        _MMR_f64 v_vd  = vle64_v_f64m1(&vd[i],  gvl);
        _MMR_f64 v_res = vfmacc_vv_f64m1(v_vd, v_vs1, v_vs2, gvl);
        vse64_v_f64m1(&vd[i], v_res, gvl);
        i += gvl;
    }

    FENCE();
}

void vmflt_vv_f64_vec(int64_t* vd, double* vs2, double* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e64m1(n - i);
        _MMR_f64 v_vs1 = vle64_v_f64m1(&vs1[i], gvl);
        _MMR_f64 v_vs2 = vle64_v_f64m1(&vs2[i], gvl);
        _MMR_MASK_i64 v_res = vmflt_vv_f64m1_b64(v_vs1, v_vs2, gvl);
        vse64_v_i64m1(&vd[i], v_res, gvl);
        i += gvl;
    }

    FENCE();
}

void vmfle_vv_f64_vec(int64_t* vd, double* vs2, double* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e64m1(n - i);
        _MMR_f64 v_vs1 = vle64_v_f64m1(&vs1[i], gvl);
        _MMR_f64 v_vs2 = vle64_v_f64m1(&vs2[i], gvl);
        _MMR_MASK_i64 v_res = vmfle_vv_f64m1_b64(v_vs1, v_vs2, gvl);
        vse64_v_i64m1(&vd[i], v_res, gvl);
        i += gvl;
    }

    FENCE();
}

void vfsgnj_vv_f64_vec(double* vd, double* vs2, double* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e64m1(n - i);
        _MMR_f64 v_vs1 = vle64_v_f64m1(&vs1[i], gvl);
        _MMR_f64 v_vs2 = vle64_v_f64m1(&vs2[i], gvl);
        _MMR_f64 v_res = vfsgnj_vv_f64m1(v_vs2, v_vs1, gvl);
        vse64_v_f64m1(&vd[i], v_res, gvl);
        i += gvl;
    }

    FENCE();
}

void vfsgnjn_vv_f64_vec(double* vd, double* vs2, double* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e64m1(n - i);
        _MMR_f64 v_vs1 = vle64_v_f64m1(&vs1[i], gvl);
        _MMR_f64 v_vs2 = vle64_v_f64m1(&vs2[i], gvl);
        _MMR_f64 v_res = vfsgnjn_vv_f64m1(v_vs2, v_vs1, gvl);
        vse64_v_f64m1(&vd[i], v_res, gvl);
        i += gvl;
    }

    FENCE();
}

void vfsgnjx_vv_f64_vec(double* vd, double* vs2, double* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e64m1(n - i);
        _MMR_f64 v_vs1 = vle64_v_f64m1(&vs1[i], gvl);
        _MMR_f64 v_vs2 = vle64_v_f64m1(&vs2[i], gvl);
        _MMR_f64 v_res = vfsgnjx_vv_f64m1(v_vs2, v_vs1, gvl);
        vse64_v_f64m1(&vd[i], v_res, gvl);
        i += gvl;
    }

    FENCE();
}

void vfmax_vv_f64_vec(double* vd, double* vs2, double* vs1, int n) {
    int i;

    long gvl = vsetvl_e64m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e64m1(n - i);
        _MMR_f64 v_vs1 = vle64_v_f64m1(&vs1[i], gvl);
        _MMR_f64 v_vs2 = vle64_v_f64m1(&vs2[i], gvl);
        _MMR_f64 v_res = vfmax_vv_f64m1(v_vs2, v_vs1, gvl);
        vse64_v_f64m1(&vd[i], v_res, gvl);
        i += gvl;
    }

    FENCE();
}

void vfcvt_x_f_v_i32_vec(int32_t* vd, float* vs2, int n) {
    int i;

    long gvl = vsetvl_e32m1(n);
    
    for (i = 0; i < n;) {
        gvl = vsetvl_e32m1(n - i);
        _MMR_f32 v_vs2 = vle32_v_f32m1(&vs2[i], gvl);
        _MMR_i32 v_res = vfcvt_x_f_v_i32m1(v_vs2, gvl);
        vse32_v_i32m1(&vd[i], v_res, gvl);
        i += gvl;
    }

    FENCE();
}