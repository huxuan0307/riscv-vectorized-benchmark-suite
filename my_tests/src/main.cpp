#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "utils.h" 
#include "serial_ref.h"
#include "vector_ref.h"

/*************************************************************************
*GET_TIME
*returns a long int representing the time
*************************************************************************/

#include <time.h>
#include <sys/time.h>

long long get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}
// Returns the number of seconds elapsed between the two specified times
float elapsed_time(long long start_time, long long end_time) {
        return (float) (end_time - start_time) / (1000 * 1000);
}
/*************************************************************************/

void axpy_intrinsics(double a, double *dx, double *dy, int n); 

// Ref version
void axpy_ref(double a, double *dx, double *dy, int n) {
   int i;
   for (i=0; i<n; i++) {
      dy[i] += a*dx[i];
   }
}

void init_vector(double *pv, long n, double value)
{
   for (int i=0; i<n; i++) pv[i]= value;
//   int gvl = __builtin_epi_vsetvl(n, __epi_e64, __epi_m1);
//   __epi_1xi64 v_value   = __builtin_epi_vbroadcast_1xi64(value, gvl);
//   for (int i=0; i<n; ) {
//    gvl = __builtin_epi_vsetvl(n - i, __epi_e64, __epi_m1);
//      __builtin_epi_vstore_1xf64(&dx[i], v_res, gvl);
//     i += gvl;
//   }
}

uint32_t rand32bit() {
    return rand() | (rand() %2==0 ? 0x80000000 : 0);
}

uint64_t rand64bit() {
    return (((uint64_t)rand32bit()) << 32) | rand32bit();
}

void init_vector(double* pv, int64_t n)
{
    for (int64_t i=0; i<n; i++)
        pv[i] = (double)1000*((double)rand()/((double)RAND_MAX)*2-1);
}

void init_vector(float* pv, int64_t n)
{
    for (int64_t i=0; i<n; i++)
        pv[i] = (float)1000*((float)rand()/((float)RAND_MAX)*2-1);
}

void init_vector(int64_t* pv, uint64_t n)
{
    for (int64_t i=0; i<n; i++) {
        uint64_t tmp = rand64bit();
        pv[i] = *(int64_t*)(&tmp);
    }
}

void init_vector(uint64_t* pv, uint64_t n) {
    for (int64_t i=0; i<n; i++)
        pv[i] = rand64bit();
}

void init_vector(int32_t* pv, uint64_t n) {
    for (int64_t i=0; i<n; i++) {
        uint32_t tmp = rand32bit();
        pv[i] = *(int32_t*)(&tmp);
    }
}

void init_vector(uint32_t* pv, uint64_t n) {
    for (int64_t i=0; i<n; i++)
        pv[i] = rand32bit();
}

void init_vector(bool* pv, uint64_t n) {
    for (int64_t i=0; i<n; i++)
        pv[i] = rand() %2 == 0;
}

template<typename TypeRet, typename TypeSrc1, typename TypeSrc2>
void test_3src_op(
    void (*ref_func)(TypeRet*, TypeSrc1*, TypeSrc2*, int), 
    void (*vector_func)(TypeRet*, TypeSrc1*, TypeSrc2*, int),
    uint64_t test_size = 1024
) {

    long long start,end;
    
    start = get_time();
    
    const auto n = test_size;
    /* Allocate the source and result vectors */
    TypeSrc1 *vs1    = (TypeSrc1*)  malloc(n*sizeof(TypeSrc1));
    TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
    TypeRet  *vd_old = (TypeRet*)   malloc(n*sizeof(TypeRet));
    TypeRet  *vd     = (TypeRet*)   malloc(n*sizeof(TypeRet));
    TypeRet  *vd_ref = (TypeRet*)   malloc(n*sizeof(TypeRet));
    
    init_vector(vs1, n);
    init_vector(vs2, n);
    init_vector(vd_old,  n);
    copy_result(vd_ref, vd_old, n);
    copy_result(vd, vd_old, n);

    end = get_time();
    printf("init_vector time: %f\n", elapsed_time(start, end));

    printf ("doing reference calculate\n");
    start = get_time();

    ref_func(vd_ref, vs2, vs1, n);

    end = get_time();
    printf("reference time: %f\n", elapsed_time(start, end));

    printf ("doing vector calculate\n");
    start = get_time();
    vector_func(vd, vs2, vs1, n);
    end = get_time();
    printf("vector time: %f\n", elapsed_time(start, end));
    
    printf ("done\n");
    test_result(vd, vd_ref, n);

    free(vs1); free(vs2); free(vd); free(vd_ref);
}

template<typename TypeRet, typename TypeSrc1, typename TypeSrc2>
void test_2src_op(
    void (*ref_func)(TypeRet*, TypeSrc2*, TypeSrc1*, int), 
    void (*vector_func)(TypeRet*, TypeSrc2*, TypeSrc1*, int),
    uint64_t test_size = 1024
) {

    long long start,end;
    
    start = get_time();
    
    const auto n = test_size;
    /* Allocate the source and result vectors */
    TypeSrc1 *vs1    = (TypeSrc1*)  malloc(n*sizeof(TypeSrc1));
    TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
    TypeRet  *vd     = (TypeRet*)   malloc(n*sizeof(TypeRet));
    TypeRet  *vd_ref = (TypeRet*)   malloc(n*sizeof(TypeRet));
    
    init_vector(vs1, n);
    init_vector(vs2, n);

    end = get_time();
    printf("init_vector time: %f\n", elapsed_time(start, end));

    printf ("doing reference calculate\n");
    start = get_time();

    ref_func(vd_ref, vs2, vs1, n);

    end = get_time();
    printf("reference time: %f\n", elapsed_time(start, end));

    printf ("doing vector calculate\n");
    start = get_time();
    vector_func(vd, vs2, vs1, n);
    end = get_time();
    printf("vector time: %f\n", elapsed_time(start, end));
    
    printf ("done\n");
    test_result(vd, vd_ref, n);

    free(vs1); free(vs2); free(vd); free(vd_ref);
}

template<typename TypeRet, typename TypeSrc1>
void test_1src_op(
    void (*ref_func)(TypeRet*, TypeSrc1*, int), 
    void (*vector_func)(TypeRet*, TypeSrc1*, int),
    uint64_t test_size = 1024
) {

    long long start,end;
    
    start = get_time();
    
    const auto n = test_size;
    /* Allocate the source and result vectors */
    TypeSrc1 *vs1    = (TypeSrc1*)  malloc(n*sizeof(TypeSrc1));
    TypeRet  *vd     = (TypeRet*)   malloc(n*sizeof(TypeRet));
    TypeRet  *vd_ref = (TypeRet*)   malloc(n*sizeof(TypeRet));
    
    init_vector(vs1, n);

    end = get_time();
    printf("init_vector time: %f\n", elapsed_time(start, end));

    printf ("doing reference calculate\n");
    start = get_time();

    ref_func(vd_ref, vs1, n);

    end = get_time();
    printf("reference time: %f\n", elapsed_time(start, end));

    printf ("doing vector calculate\n");
    start = get_time();
    vector_func(vd, vs1, n);
    end = get_time();
    printf("vector time: %f\n", elapsed_time(start, end));
    
    printf ("done\n");
    test_result(vd, vd_ref, n);

    free(vs1); free(vd); free(vd_ref);
}

int main(int argc, char *argv[])
{
    // vfadd
    if (1) {
        printf("\n*****vfadd_vv_f64 test*****\n");
        test_2src_op<double, double, double>(vfadd_vv_f64_ref, vfadd_vv_f64_vec);
    }
    // vfsub
    if (1) {
        printf("\n*****vfsub_vv_f64 test*****\n");
        test_2src_op<double, double, double>(vfsub_vv_f64_ref, vfsub_vv_f64_vec);
    }
    // vfmul
    if (1) {
        printf("\n*****vfmul_vv_f64 test*****\n");
        test_2src_op<double, double, double>(vfmul_vv_f64_ref, vfmul_vv_f64_vec);
    }
    // vfmadd
    if (1) {
        printf("\n*****vfmadd_vv_f64 test*****\n");
        test_3src_op<double, double, double>(vfmadd_vv_f64_ref, vfmadd_vv_f64_vec);
    }
    // vfmacc
    if (1) {
        printf("\n*****vfmacc_vv_f64 test*****\n");
        test_3src_op<double, double, double>(vfmacc_vv_f64_ref, vfmacc_vv_f64_vec);
    }
    // vmflt
    if (1) {
        printf("\n*****vmflt_vv_f64 test*****\n");
        test_2src_op<int64_t, double, double>(vmflt_vv_f64_ref, vmflt_vv_f64_vec);
    }
    // vmfle
    if (1) {
        printf("\n*****vmfle_vv_f64 test*****\n");
        test_2src_op<int64_t, double, double>(vmfle_vv_f64_ref, vmfle_vv_f64_vec);
    }
    // vfsgnj
    if (1) {
        printf("\n*****vfsgnj_vv_f64 test*****\n");
        test_2src_op<double, double, double>(vfsgnj_vv_f64_ref, vfsgnj_vv_f64_vec);
    }
    // vfsgnjn
    if (1) {
        printf("\n*****vfsgnjn_vv_f64 test*****\n");
        test_2src_op<double, double, double>(vfsgnjn_vv_f64_ref, vfsgnjn_vv_f64_vec);
    }
    // vfsgnjx
    if (1) {
        printf("\n*****vfsgnjx_vv_f64 test*****\n");
        test_2src_op<double, double, double>(vfsgnjx_vv_f64_ref, vfsgnjx_vv_f64_vec);
    }
    // vfmax
    if (1) {
        printf("\n*****vfmax_vv_f64 test*****\n");
        test_2src_op<double, double, double>(vfmax_vv_f64_ref, vfmax_vv_f64_vec);
    }
    // vfcvt_x_f_v
    if (1) {
        printf("\n*****vfcvt_x_f_v_i32 test*****\n");
        test_1src_op<int32_t, float>(vfcvt_x_f_v_i32_ref, vfcvt_x_f_v_i32_vec);
    }
    if (1) {
        printf("\n*****vfcvt_x_f_v_i64 test*****\n");
        test_1src_op<int64_t, double>(vfcvt_x_f_v_i64_ref, vfcvt_x_f_v_i64_vec);
    }
    // vfcvt_f_x_v
    if (1) {
        printf("\n*****vfcvt_f_x_v_f32 test*****\n");
        test_1src_op<float, int32_t>(vfcvt_f_x_v_f32_ref, vfcvt_f_x_v_f32_vec);
    }
    if (1) {
        printf("\n*****vfcvt_f_x_v_f64 test*****\n");
        test_1src_op<double, int64_t>(vfcvt_f_x_v_f64_ref, vfcvt_f_x_v_f64_vec);
    }
    // vdiv_vv
    if (1) {
        printf("\n*****vdiv_vv_i64 test*****\n");
        test_2src_op<int64_t, int64_t, int64_t>(vdiv_vv_i64_ref, vdiv_vv_i64_vec);
    }
    if (1) {
        printf("\n*****vdiv_vv_i32 test*****\n");
        test_2src_op<int32_t, int32_t, int32_t>(vdiv_vv_i32_ref, vdiv_vv_i32_vec);
    }
    // vmul_vv
    if (1) {
        printf("\n*****vmul_vv_i64 test*****\n");
        test_2src_op<int64_t, int64_t, int64_t>(vmul_vv_i64_ref, vmul_vv_i64_vec);
    }
    if (1) {
        printf("\n*****vmul_vv_i32 test*****\n");
        test_2src_op<int32_t, int32_t, int32_t>(vmul_vv_i32_ref, vmul_vv_i32_vec);
    }
    // vsub_vv
    if (1) {
        printf("\n*****vsub_vv_i64 test*****\n");
        test_2src_op<int64_t, int64_t, int64_t>(vsub_vv_ref<int64_t>, vsub_vv_i64_vec);
    }
    if (1) {
        printf("\n*****vsub_vv_i32 test*****\n");
        test_2src_op<int32_t, int32_t, int32_t>(vsub_vv_ref<int32_t>, vsub_vv_i32_vec);
    }
    
    // vmerge_vvm
    if (1) {
        printf("\n*****vmerge_vvm test*****\n");
        test_3src_op<int64_t, int64_t, int64_t, bool>(vmerge_vvm_ref<int64_t>, vmerge_vvm_vec<int64_t>);
    }


    return 0;
}
