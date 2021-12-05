#include <stdint.h>
#include <math.h>

void vfmv_v_f_64_ref(double* vd, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs1[i];
    }
}

void vfadd_vv_64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] + vs1[i];
    }
}

void vfsub_vv_64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] - vs1[i];
    }
}

void vmflt_vv_64_ref(uint8_t* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = (vs2[i] < vs1[i]) ? (uint8_t)1 : (uint8_t)0;
    }
}

void vmfle_vv_64_ref(uint8_t* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = (vs2[i] <= vs1[i]) ? (uint8_t)1 : (uint8_t)0;
    }
}

void vmv_vv_64_ref(uint64_t* vd, uint64_t* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs1[i];
    }
}

void vfmax_vv_64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = (vs2[i]>vs1[i]) ? vs2[i] : vs1[i];
    }
}

void vand_vv_64_ref(uint64_t* vd, uint64_t* vs2, uint64_t* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] & vs1[i];
    }
}

void vor_vv_64_ref(uint64_t* vd, uint64_t* vs2, uint64_t* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] | vs1[i];
    }
}

void vmerge_vvm_64_ref(double* vd, double* vs2, double* vs1, uint8_t* vm, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vm[i] ? vs1[i] : vs2[i];
    }
}

void vfcvt_fx_f64i64_ref(double* vd, int64_t* vs2, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = (double)vs2[i];
    }
}

void vfmadd_vv_64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs1[i]*vd[i] + vs2[i];
    }
}

void vfmacc_vv_64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs1[i]*vs2[i] + vd[i];
    }
}

void vfmul_vv_64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] * vs1[i];
    }
}

void vsub_vv_64_ref(uint64_t* vd, uint64_t* vs2, uint64_t* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] - vs1[i];
    }
}

void vfsgnj_vv_64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] > 0 ? fabs(vs1[i]) : -fabs(vs1[i]);
    }
}

void vfsgnjn_vv_64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] < 0 ? fabs(vs1[i]) : -fabs(vs1[i]);
    }
}

void vfsgnjx_vv_64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = (vs2[i] > 0) ? vs1[i] : -vs1[i];
    }
}

void vdiv_vv_64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] / vs1[i];
    }
}

void vmul_vv_64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] * vs1[i];
    }
}


