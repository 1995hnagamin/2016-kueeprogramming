typedef double Element;

typedef struct {
  size_t size;
  Element *ptr;
} Vector;

typedef struct {
  size_t rows;
  size_t columns;
  Element **ptr;
} Matrix;

Vector vec_alloc(size_t);

Matrix mat_alloc(size_t, size_t);

Vector vec_copy(Vector);

Matrix mat_copy(Matrix);

void vec_free(Vector);

void mat_free(Matrix);

Vector vec_init(size_t, Element const *);

Matrix mat_init(size_t, size_t, Element const *);
#define MAT_INIT(m, n, arr) mat_init(m, n, &(arr[0][0]))

Vector vec_init_by_const(size_t, Element);

void vec_print(Vector);

void mat_print(Matrix);

Vector mult_mat_by_vec(Matrix, Vector);

Matrix mult_mat_by_mat(Matrix, Matrix);

Matrix mult_mat_by_scalar(Matrix, Element);

void mult_mat_by_scalar_dstly(Matrix *, Element);

Matrix add_mat_rows(Matrix, size_t,  Element, size_t);

void add_mat_rows_dstly(Matrix *, size_t,  Element, size_t);

Matrix mult_mat_row_by_scalar(Matrix, size_t, Element);

void mult_mat_row_by_scalar_dstly(Matrix *, size_t, Element);

Matrix transpose_mat(Matrix);
