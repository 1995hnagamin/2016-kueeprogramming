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

void vec_free(Vector);

void mat_free(Matrix);

Vector vec_init(size_t, Element const *);

Matrix mat_init(size_t, size_t, Element const *);
#define MAT_INIT(m, n, arr) mat_init(m, n, &(arr[0][0]))

void vec_print(Vector);

void mat_print(Matrix);

Vector mult_mat_by_vec(Matrix, Vector);

Matrix mult_mat_by_mat(Matrix, Matrix);

