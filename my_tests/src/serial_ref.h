#include <stdint.h>
#include <math.h>

// float move operation

void vfmv_v_f_f64_ref(double* vd, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs1[i];
    }
}

// float 2 src arith operation

void vfadd_vv_f64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] + vs1[i];
    }
}

void vfsub_vv_f64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] - vs1[i];
    }
}

void vfmul_vv_f64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] * vs1[i];
    }
}

// float 3 src arith operation
void vfmadd_vv_f64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;

    for (i=0; i<n; i++) {
        printf("vd[%4d]=%.10f, vs1[%4d]=%.10f, vs2[%4d]=%.10f", 
            i, vd[i], i, vs1[i], i, vs2[i])
        vd[i] = vs1[i]*vd[i] + vs2[i];
        printf(", vd_new[%4d]=%.10f\n", i, vd[i]);
    }
}

void vfmacc_vv_f64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        printf("vd[%4d]=%.10f, vs1[%4d]=%.10f, vs2[%4d]=%.10f", 
            i, vd[i], i, vs1[i], i, vs2[i])
        vd[i] = vs1[i]*vs2[i] + vd[i];
        printf(", vd_new[%4d]=%.10f\n", i, vd[i]);
    }
}

// float cmp operation

void vmflt_vv_f64_ref(uint8_t* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = (vs2[i] < vs1[i]) ? (uint8_t)1 : (uint8_t)0;
    }
}

void vmfle_vv_f64_ref(uint8_t* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = (vs2[i] <= vs1[i]) ? (uint8_t)1 : (uint8_t)0;
    }
}

// float other operation

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

void vfmax_vv_f64_ref(double* vd, double* vs2, double* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = (vs2[i]>vs1[i]) ? vs2[i] : vs1[i];
    }
}

void vfcvt_fx_f64i64_ref(double* vd, int64_t* vs2, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = (double)vs2[i];
    }
}

// fixed-point move operation

void vmv_v_x_i64_ref(uint64_t* vd, uint64_t* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs1[i];
    }
}

// fixed-point bit operation

void vand_vv_i64_ref(uint64_t* vd, uint64_t* vs2, uint64_t* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] & vs1[i];
    }
}

void vor_vv_i64_ref(uint64_t* vd, uint64_t* vs2, uint64_t* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] | vs1[i];
    }
}

// fixed-point arith operation

void vsub_vv_64_ref(uint64_t* vd, uint64_t* vs2, uint64_t* vs1, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vs2[i] - vs1[i];
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

// fixed-point other operation

void vmerge_vvm_64_ref(double* vd, double* vs2, double* vs1, uint8_t* vm, int n) {
    int i;
    for (i=0; i<n; i++) {
        vd[i] = vm[i] ? vs1[i] : vs2[i];
    }
}

