#include "miller_header.h"

int Mcounter = 0;

// BLS
int main (void){
    clock_t start, end;
    double cpu_time_used;

    // パラメータ定義
    printf("start\n");

    mpz_t z;mpz_t p;mpz_t r;mpz_t t;
    mpz_inits(z, p, r, t, NULL);
    gen_params(z, p, r, t);
    print_params(z, p, r, t);
    printf("\n");

    mpz_t E;mpz_init(E);
    rank_number(E, 12, t, p);
    gmp_printf("有利点数:%Zd\n\n", E);

    fp_t b;mpz_init(b.x0);
    mpz_set_str(b.x0, "2806781539090543763928146397551071025921865095800381583843579968964127551432039332258992094003963260740981125881345582810061579481053866112", 10);

    // efp12_t test;efp12_init(&test);
    // start = clock();
    // efp12_random(&test, b, p);
    // end = clock();
    // cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // printf("処理時間: %f 秒\n", cpu_time_used);

    // efp12_println("test : ", test);
    // mpz_t exp;mpz_init_set_str(exp, "4", 10);
    // start = clock();
    // efp12_scm(&test, test, exp, p);
    // end = clock();
    // efp12_println("test : ", test);

    // cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // printf("処理時間: %f 秒\n", cpu_time_used);    

    // fp12_t tmp1, tmp2;fp12_init(&tmp1);fp12_init(&tmp2);
    // fp12_random(&tmp1, p);
    // fp12_random(&tmp2, p);
    // fp12_println("tmp1 : ", tmp1);
    // fp12_println("tmp2 : ", tmp2);
    // start = clock();
    // fp12_inv(&tmp1, tmp1, p);
    // end = clock();

    // cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // printf("処理時間: %f 秒\n", cpu_time_used);

    // efp12_t P, Q;
    // efp12_init(&P);
    // efp12_init(&Q);

    // efp12_random(&P, b, p);
    // efp12_println("P : ", P);
    // fp12_Frobenius(&Q.x, P.x, p);
    // fp12_Frobenius(&Q.y, P.y, p);
    // fp12_Frobenius(&Q.x, Q.x, p);
    // fp12_Frobenius(&Q.y, Q.y, p);
    // efp12_println("(P^p)^p", Q);




    efp12_t R;efp12_init(&R);

    efp12_t P;efp12_init(&P);
    generate1(&P, b, z, r, p);
    efp12_println("P : ",  P);

    efp12_t Q;fp12_init(&Q.x);fp12_init(&Q.y);Q.inf = 0;
    generate2(&Q, b, E, r, p);
    efp12_println("Q : ", Q);
    
    fp12_t S;fp12_init(&S);
    fp12_t f;fp12_init(&f);


    // // 時間測定
    // struct timespec ts;
    // struct tm tm;
    // long double start_sec, start_nsec, end_sec, end_nsec, exe_time_buf0;
    // clock_gettime(CLOCK_REALTIME, &ts);
    // start_sec = ts.tv_sec;
    // start_nsec = ts.tv_nsec;
    // int loop = 1000;
    // for (int i = 0; i < loop; i ++){
    //     optimal_ate_miller(&f, z, P, Q, p);
    //     // final_exponentiation(&S, f, r, p);
    //     hard_final_exponentiation(&S, f, r, p, z);
    // }
    // clock_gettime(CLOCK_REALTIME, &ts);
    // end_sec = ts.tv_sec;
    // end_nsec = ts.tv_nsec;
    // exe_time_buf0 = ((end_sec - start_sec) + (end_nsec - start_nsec) / 1000000000.0)*1000.0/loop;
    // printf("Execution time!! : %Lf[ms]\n", exe_time_buf0);


    // // 乗算回数測定
    // int Maverage;
    // // ミラー
    // Mcounter = 0;
    // for (int i = 0; i < loop; i ++){
    //     optimal_ate_miller(&f, z, P, Q, p);
    // }
    // Maverage = Mcounter / loop;
    // printf("ミラーの掛け算の回数 : %d\n", Maverage);

    // // 最終べき
    // Mcounter = 0;
    // for (int i = 0; i < loop; i ++){
    //     // final_exponentiation(&S, f, r, p);
    //     hard_final_exponentiation(&S, f, r, p, z);
    // }
    // Maverage = Mcounter / loop;
    // printf("最終べき掛け算の回数 : %d\n", Maverage);


    optimal_ate_miller(&f, z, P, Q, p);
    fp12_println("miller : ", f);

    // final_exponentiation(&S, f, r, p);
    // easy_final_exponentiation(&S, f, r, p);
    hard_final_exponentiation(&S, f, r, p, z);
    fp12_println("PARE : ", S);



    // fp12_t f;fp12_init(&f);
    optimal_ate_miller(&f, z, P, Q, p);
    fp12_println("miller : ", f);


    Mcounter = 0;
    // fp12_t S;fp12_init(&S);
    final_exponentiation(&S, f, r, p);
    fp12_println("PARE : ", S);


    mpz_t s1, s2;mpz_inits(s1, s2, NULL);
    mpz_set_str(s1, "100", 10);
    mpz_set_str(s2, "200", 10);
    bilinearity(P, Q, s1, s2, z, r, p);

    printf("\ntest\n");
    fp12_t W;fp12_init(&W);
    fp12_random(&W, p);
    fp12_println("", W);
}