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


// from prime_field.c
struct fp{
    mpz_t x0;
};
void fp_init(struct fp *X);
void fp_clear(struct fp *X);
void fp_printf(const struct fp X);
void fp_set(struct fp *S, const struct fp X);
void make_state(gmp_randstate_t state);
void fp_random(struct fp *X, const mpz_t p, gmp_randstate_t state);
int fp_cmp(const struct fp X, const struct fp Y);
void fp_neg(struct fp *S, struct fp X, const mpz_t p);
void fp_add(struct fp *S, const struct fp X, const struct fp Y, const mpz_t p);
void fp_sub(struct fp *S, const struct fp X, const struct fp Y, const mpz_t p);
void fp_mul(struct fp *S, const struct fp X, const struct fp Y, const mpz_t p);
void fp_inv(struct fp *S, const struct fp X, const mpz_t p);
void fp_pow(struct fp *S, const struct fp X, const mpz_t s, const mpz_t p);
int fp_legendre(const struct fp a, const mpz_t p);
void fp_sqrt(struct fp *b, struct fp a, mpz_t p, gmp_randstate_t state);


// from secondary_expansion.c
struct fp2{
    struct fp x0;   // 定数
    struct fp x1;   // ω
};
void fp2_init(struct fp2 *X);
void fp2_clear(struct fp2 *X);
void fp2_printf(const struct fp2 X);
void fp2_set(struct fp2 *S, const struct fp2 X);
void fp2_random(struct fp2 *X, const mpz_t p, gmp_randstate_t state);
int fp2_cmp(const struct fp2 X, const struct fp2 Y);
void fp2_neg(struct fp2 *S, struct fp2 X, const mpz_t p);
void fp2_add(struct fp2 *S, const struct fp2 X, const struct fp2 Y, const mpz_t p);
void fp2_sub(struct fp2 *S, const struct fp2 X, const struct fp2 Y, const mpz_t p);
void fp2_mul(struct fp2 *S, const struct fp2 X, const struct fp2 Y, const mpz_t p);
void fp2_square(struct fp2 *S, const struct fp2 X, const mpz_t p);
void fp2_inv(struct fp2 *S, const struct fp2 X, const mpz_t p);
void fp2_pow(struct fp2 *S, const struct fp2 X, const mpz_t s, const mpz_t p);
void fp2_Frobenius(struct fp2 *S, const struct fp2 X, const mpz_t p);
int fp2_legendre(const struct fp2 X, const mpz_t p);
void fp2_sqrt(struct fp2 *S, const struct fp2 X, const mpz_t p, gmp_randstate_t state);


// from secondary_expansion_ellipse.c
struct efp2{
    struct fp2 x;
    struct fp2 y;
    int inf;
};
void efp2_init(struct efp2 *X);
void efp2_clear(struct efp2 *X);
void efp2_set(struct efp2 *X, struct efp2 Y);
void efp2_random(struct efp2 A, struct fp2 b, mpz_t p,gmp_randstate_t state);
void efp2_ecd(struct efp2 *R, struct efp2 P, mpz_t p);
void efp2_eca(struct efp2 *R, struct efp2 P, struct efp2 Q, mpz_t p);
void efp2_scm(struct efp2 R, struct efp2 P, mpz_t s, mpz_t p);


// from sixth_expansion.c
struct fp6{
    struct fp2 x0;   // 定数
    struct fp2 x1;   // ω
    struct fp2 x2;   // ω^2
};
void fp6_init(struct fp6 *X);
void fp6_clear(struct fp6 *X);
void fp6_printf(const struct fp6 X);
void fp6_set(struct fp6 *S, struct fp6 temp);
void fp6_random(struct fp6 *X, const mpz_t p, gmp_randstate_t state);
int fp6_cmp(const struct fp6 X, const struct fp6 Y);
void a1_xi(struct fp2 *S, struct fp2 X, const mpz_t p);
void fp6_neg(struct fp6 *S, struct fp6 X, const mpz_t p);
void fp6_add(struct fp6 *S, const struct fp6 X, const struct fp6 Y, const mpz_t p);
void fp6_sub(struct fp6 *S, const struct fp6 X, const struct fp6 Y, const mpz_t p);
void fp6_mul(struct fp6 *S, const struct fp6 X, const struct fp6 Y, const mpz_t p);
void fp6_square(struct fp6 *S, const struct fp6 X, const mpz_t p);
void make_epsilon(mpz_t epsilon, const mpz_t p);
void fp6_Frobenius(struct fp6 *S, const struct fp6 X, const mpz_t p);
void fp6_inv(struct fp6 *S, const struct fp6 X, const mpz_t p);
void fp6_pow(struct fp6 *S, const struct fp6 X, const mpz_t s, const mpz_t p);
int fp6_legendre(const struct fp6 X, const mpz_t p);
void fp6_sqrt(struct fp6 *S, const struct fp6 X, const mpz_t p, gmp_randstate_t state);


// from twelfth_expansion.c 
struct fp12{
    struct fp6 x0;
    struct fp6 x1;
};
void fp12_init(struct fp12 *X);
void fp12_clear(struct fp12 *X);
void fp12_printf(const struct fp12 X);
void fp12_set(struct fp12 *S, struct fp12 temp);
void fp12_random(struct fp12 *X, const mpz_t p, gmp_randstate_t state);
int fp12_cmp(const struct fp12 X, const struct fp12 Y);
void fp12_neg(struct fp12 *S, struct fp12 X, const mpz_t p);
void fp12_add(struct fp12 *S, const struct fp12 X, const struct fp12 Y, const mpz_t p);
void fp12_sub(struct fp12 *S, const struct fp12 X, const struct fp12 Y, const mpz_t p);
void fp12_mul(struct fp12 *S, const struct fp12 X, const struct fp12 Y, const mpz_t p);
void fp12_square(struct fp12 *S, const struct fp12 X, const mpz_t p);
void fp12_Frobenius(struct fp12 *S, const struct fp12 X, const mpz_t p);
void fp12_inv(struct fp12 *S, const struct fp12 X, const mpz_t p);
void fp12_pow(struct fp12 *S, const struct fp12 X, const mpz_t s, const mpz_t p);
int fp12_legendre(const struct fp12 X, const mpz_t p);
void fp12_sqrt(struct fp12 *S, const struct fp12 X, const mpz_t p, gmp_randstate_t state);


// from twelfth_expansion_BLS_ellipse.c 
struct efp12{
    struct fp12 x;
    struct fp12 y;
    int inf;
};
void efp12_init(struct efp12 *X);
void efp12_clear(struct efp12 *X);
void efp12_printf(const struct efp12 X);
void efp12_set(struct efp12 *X, struct efp12 Y);
void efp12_random(struct efp12 *A, struct fp b, mpz_t p, gmp_randstate_t state);
void efp12_ecd(struct efp12 *R, struct efp12 P, mpz_t p);
void efp12_eca(struct efp12 *R, struct efp12 P, struct efp12 Q, mpz_t p);
void efp12_scm(struct efp12 *R, struct efp12 P, mpz_t s, mpz_t p);


// from miller.c 
struct efp{
    struct fp x;
    struct fp y;
    int inf;
};
void efp_random(struct efp *A, struct fp b, mpz_t p, gmp_randstate_t state);
void efp_ecd(struct efp *R, struct efp P, mpz_t p);
void efp_eca(struct efp *R, struct efp P, struct efp Q, mpz_t p);
void efp_scm(struct efp *R, struct efp P, mpz_t s, mpz_t p);
void gen_z(mpz_t z);
void print_params(mpz_t z, mpz_t prime, mpz_t r, mpz_t t);
void gen_params(mpz_t z, mpz_t prime, mpz_t r, mpz_t t);
void l_TT(struct fp12 *S, struct efp12 Q, struct efp12 T, mpz_t p);
void l_TT_twist(struct fp12 *S, struct efp12 Q, struct efp12 T, mpz_t p);
void l_TP(struct fp12 *S, struct efp12 P, struct efp12 Q, struct efp12 T, mpz_t p);
void optimal_ate_miller(struct fp12 *ans, mpz_t s, struct efp12 p, struct efp12 q, mpz_t prime);
// void optimal_ate_miller(struct fp12 *f, mpz_t z, struct efp12 P, struct efp12 Q, mpz_t p);
void final_exponentiation(struct fp12 *S, struct fp12 f, mpz_t r, mpz_t p);
void easy_final_exponentiation(struct fp12 *S, struct fp12 f, mpz_t r, mpz_t p);
void hard_final_exponentiation(struct fp12 *S, struct fp12 f, mpz_t r, mpz_t p, mpz_t z);
void rank_number(mpz_t E, int n, mpz_t t, mpz_t p);
void generate1(struct efp12 *P, struct fp b, mpz_t z, mpz_t r, mpz_t p, gmp_randstate_t state);
void generate2(struct efp12 *Q, struct fp b, mpz_t E, mpz_t r, mpz_t p, gmp_randstate_t state);
void efp12_ecd_twist(struct efp12 *R, struct efp12 P, mpz_t p);
void bilinearity(struct efp12 P, struct efp12 Q, mpz_t a, mpz_t b, mpz_t z, mpz_t r, mpz_t p);

#endif