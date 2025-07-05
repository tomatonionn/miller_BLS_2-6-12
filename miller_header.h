#ifndef MILLER_HEADER_H
#define MILLER_HEADER_H
#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


// from fp.c
typedef struct{
    mpz_t x0;
}fp_t;
void fp_init(fp_t *X);
void fp_clear(fp_t *X);
void fp_printf(char *str, const fp_t X);
void fp_println(char *str, const fp_t X);
void fp_set(fp_t *S, const fp_t X);
void fp_random(fp_t *X, const mpz_t p);
int fp_cmp(const fp_t X, const fp_t Y);
void fp_neg(fp_t *S, fp_t X, const mpz_t p);
void fp_add(fp_t *S, const fp_t X, const fp_t Y, const mpz_t p);
void fp_sub(fp_t *S, const fp_t X, const fp_t Y, const mpz_t p);
void fp_mul(fp_t *S, const fp_t X, const fp_t Y, const mpz_t p);
void fp_inv(fp_t *S, const fp_t X, const mpz_t p);
void fp_pow(fp_t *S, const fp_t X, const mpz_t s, const mpz_t p);
int fp_legendre(const fp_t a, const mpz_t p);
void fp_sqrt(fp_t *b, fp_t a, mpz_t p);


// from fp2.c
typedef struct{
    fp_t x0;   // 定数
    fp_t x1;   // ω
}fp2_t;
void fp2_init(fp2_t *X);
void fp2_clear(fp2_t *X);
void fp2_printf(char *str, const fp2_t X);
void fp2_println(char *str, const fp2_t X);
void fp2_set(fp2_t *S, const fp2_t X);
void fp2_random(fp2_t *X, const mpz_t p);
int fp2_cmp(const fp2_t X, const fp2_t Y);
void fp2_neg(fp2_t *S, fp2_t X, const mpz_t p);
void fp2_add(fp2_t *S, const fp2_t X, const fp2_t Y, const mpz_t p);
void fp2_sub(fp2_t *S, const fp2_t X, const fp2_t Y, const mpz_t p);
void fp2_mul(fp2_t *S, const fp2_t X, const fp2_t Y, const mpz_t p);
void fp2_square(fp2_t *S, const fp2_t X, const mpz_t p);
void fp2_inv(fp2_t *S, const fp2_t X, const mpz_t p);
void fp2_pow(fp2_t *S, const fp2_t X, const mpz_t s, const mpz_t p);
void fp2_Frobenius(fp2_t *S, const fp2_t X, const mpz_t p);
int fp2_legendre(const fp2_t X, const mpz_t p);
void fp2_sqrt(fp2_t *S, const fp2_t X, const mpz_t p);


// from efp2.c
typedef struct{
    fp2_t x;
    fp2_t y;
    int inf;
}efp2_t;
void efp2_init(efp2_t *X);
void efp2_clear(efp2_t *X);
void efp2_set(efp2_t *X, efp2_t Y);
void efp2_random(efp2_t A, fp2_t b, mpz_t p);
void efp2_ecd(efp2_t *R, efp2_t P, mpz_t p);
void efp2_eca(efp2_t *R, efp2_t P, efp2_t Q, mpz_t p);
void efp2_scm(efp2_t R, efp2_t P, mpz_t s, mpz_t p);


// from fp6.c
typedef struct{
    fp2_t x0;   // 定数
    fp2_t x1;   // ω
    fp2_t x2;   // ω^2
}fp6_t;
void fp6_init(fp6_t *X);
void fp6_clear(fp6_t *X);
void fp6_printf(char *str, const fp6_t X);
void fp6_println(char *str, const fp6_t X);
void fp6_set(fp6_t *S, fp6_t temp);
void fp6_random(fp6_t *X, const mpz_t p);
int fp6_cmp(const fp6_t X, const fp6_t Y);
void a1_xi(fp2_t *S, fp2_t X, const mpz_t p);
void fp6_neg(fp6_t *S, fp6_t X, const mpz_t p);
void fp6_add(fp6_t *S, const fp6_t X, const fp6_t Y, const mpz_t p);
void fp6_sub(fp6_t *S, const fp6_t X, const fp6_t Y, const mpz_t p);
void fp6_mul(fp6_t *S, const fp6_t X, const fp6_t Y, const mpz_t p);
void fp6_square(fp6_t *S, const fp6_t X, const mpz_t p);
void make_epsilon(mpz_t epsilon, const mpz_t p);
void fp6_Frobenius(fp6_t *S, const fp6_t X, const mpz_t p);
void fp6_inv(fp6_t *S, const fp6_t X, const mpz_t p);
void fp6_pow(fp6_t *S, const fp6_t X, const mpz_t s, const mpz_t p);
int fp6_legendre(const fp6_t X, const mpz_t p);
void fp6_sqrt(fp6_t *S, const fp6_t X, const mpz_t p);


// from fp12.c 
typedef struct{
    fp6_t x0;
    fp6_t x1;
}fp12_t;
void fp12_init(fp12_t *X);
void fp12_clear(fp12_t *X);
void fp12_printf(char *str, const fp12_t X);
void fp12_println(char *str, const fp12_t X);
void fp12_set(fp12_t *S, fp12_t temp);
void fp12_random(fp12_t *X, const mpz_t p);
int fp12_cmp(const fp12_t X, const fp12_t Y);
void fp12_neg(fp12_t *S, fp12_t X, const mpz_t p);
void fp12_add(fp12_t *S, const fp12_t X, const fp12_t Y, const mpz_t p);
void fp12_sub(fp12_t *S, const fp12_t X, const fp12_t Y, const mpz_t p);
void fp12_mul(fp12_t *S, const fp12_t X, const fp12_t Y, const mpz_t p);
void fp12_square(fp12_t *S, const fp12_t X, const mpz_t p);
void fp12_Frobenius(fp12_t *S, const fp12_t X, const mpz_t p);
void fp12_inv(fp12_t *S, const fp12_t X, const mpz_t p);
void fp12_pow(fp12_t *S, const fp12_t X, const mpz_t s, const mpz_t p);
int fp12_legendre(const fp12_t X, const mpz_t p);
void fp12_sqrt(fp12_t *S, const fp12_t X, const mpz_t p);


// from efp12.c 
typedef struct{
    fp12_t x;
    fp12_t y;
    int inf;
}efp12_t;
void efp12_init(efp12_t *X);
void efp12_clear(efp12_t *X);
void efp12_printf(char *str, const efp12_t X);
void efp12_println(char *str, const efp12_t X);
void efp12_set(efp12_t *X, efp12_t Y);
void efp12_random(efp12_t *A, fp_t b, mpz_t p);
void efp12_ecd(efp12_t *R, efp12_t P, mpz_t p);
void efp12_eca(efp12_t *R, efp12_t P, efp12_t Q, mpz_t p);
void efp12_scm(efp12_t *R, efp12_t P, mpz_t s, mpz_t p);


// from miller.c 
typedef struct{
    fp_t x;
    fp_t y;
    int inf;
}efp_t;
void efp_random(efp_t *A, fp_t b, mpz_t p);
void efp_ecd(efp_t *R, efp_t P, mpz_t p);
void efp_eca(efp_t *R, efp_t P, efp_t Q, mpz_t p);
void efp_scm(efp_t *R, efp_t P, mpz_t s, mpz_t p);
void gen_z(mpz_t z);
void print_params(mpz_t z, mpz_t prime, mpz_t r, mpz_t t);
void gen_params(mpz_t z, mpz_t prime, mpz_t r, mpz_t t);
void l_TT(fp12_t *S, efp12_t Q, efp12_t T, mpz_t p);
void l_TT_twist(fp12_t *S, efp12_t Q, efp12_t T, mpz_t p);
void l_TP(fp12_t *S, efp12_t P, efp12_t Q, efp12_t T, mpz_t p);
void optimal_ate_miller(fp12_t *ans, mpz_t s, efp12_t p, efp12_t q, mpz_t prime);
// void optimal_ate_miller(fp12_t *f, mpz_t z, efp12_t P, efp12_t Q, mpz_t p);
void final_exponentiation(fp12_t *S, fp12_t f, mpz_t r, mpz_t p);
void easy_final_exponentiation(fp12_t *S, fp12_t f, mpz_t r, mpz_t p);
void hard_final_exponentiation(fp12_t *S, fp12_t f, mpz_t r, mpz_t p, mpz_t z);
void rank_number(mpz_t E, int n, mpz_t t, mpz_t p);
// void generate1(efp12_t *P, fp_t b, mpz_t z, mpz_t r, mpz_t p);
void generate1(efp12_t *P, fp_t b, mpz_t E, mpz_t r, mpz_t p);
void generate2(efp12_t *Q, fp_t b, mpz_t E, mpz_t r, mpz_t p);
void efp12_ecd_twist(efp12_t *R, efp12_t P, mpz_t p);
void bilinearity(efp12_t P, efp12_t Q, mpz_t a, mpz_t b, mpz_t z, mpz_t r, mpz_t p);

#endif
