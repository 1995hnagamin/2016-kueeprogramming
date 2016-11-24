Vector do_fw_subst(Matrix, Vector);
Vector do_bw_subst(Matrix, Vector);

typedef struct {
  Matrix L;
  Matrix U;
} LU_result;

void lu_res_free(LU_result);
LU_result do_LU_decomposition(Matrix);
Vector solve_linear_system(Matrix, Vector);
