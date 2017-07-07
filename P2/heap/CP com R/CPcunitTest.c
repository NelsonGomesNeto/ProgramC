#include "heap.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
/* Pointer to the file used by the tests. */
static FILE* temp_file = NULL;

/* The suite initialization function.
* Opens the temporary file used by the tests.
* Returns zero on success, non-zero otherwise.
*/
int init_suit(void)
{
  if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
    return -1;
  }
  else {
    return 0;
  }
}

/* The suite cleanup function.
* Closes the temporary file used by the tests.
* Returns zero on success, non-zero otherwise.
*/
int clean_suite(void)
{
  if (0 != fclose(temp_file)) {
    return -1;
  }
  else {
    temp_file = NULL;
    return 0;
  }
}

void test_enqueueMaxHeap(void)
{
  int i, j;
  int nums[4][10] = {7, 3, 2, 1, 5, 6, 9, 4, 8, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
  int expected[4][10] = {7, 7, 7, 7, 7, 7, 9, 9, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

  Heap_t *heap;
  for (i = 0; i < 4; i ++)
  {
    heap = createHeap(10, '+');
    for (j = 0; j < 10; j ++)
    {
      enqueueHeap(heap, nums[i][j]);
      CU_ASSERT(frontHeap(heap) == expected[i][j]);
    }
    destroyHeap(heap);
  }
}

void test_dequeueMaxHeap(void)
{
  int i, j;
  int nums[4][10] = {7, 3, 2, 1, 5, 6, 9, 4, 8, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
  int expected[4][10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

  Heap_t *heap;
  for (i = 0; i < 4; i ++)
  {
    heap = createHeap(10, '+');
    for (j = 0; j < 10; j ++)
      enqueueHeap(heap, nums[i][j]);
    for (j = 0; j < 10; j ++)
    {
      CU_ASSERT(frontHeap(heap) == expected[i][j]);
      dequeueHeap(heap);
    }
    destroyHeap(heap);
  }
}

void test_enqueueMinHeap(void)
{
  int i, j;
  int nums[4][10] = {7, 3, 2, 1, 5, 6, 9, 4, 8, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
  int expected[4][10] = {7, 3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

  Heap_t *heap;
  for (i = 0; i < 4; i ++)
  {
    heap = createHeap(10, '-');
    for (j = 0; j < 10; j ++)
    {
      enqueueHeap(heap, nums[i][j]);
      CU_ASSERT(frontHeap(heap) == expected[i][j]);
    }
    destroyHeap(heap);
  }
}

void test_dequeueMinHeap(void)
{
  int i, j;
  int nums[4][10] = {7, 3, 2, 1, 5, 6, 9, 4, 8, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
  int expected[4][10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

  Heap_t *heap;
  for (i = 0; i < 4; i ++)
  {
    heap = createHeap(10, '-');
    for (j = 0; j < 10; j ++)
      enqueueHeap(heap, nums[i][j]);
    for (j = 0; j < 10; j ++)
    {
      CU_ASSERT(frontHeap(heap) == expected[i][j]);
      dequeueHeap(heap);
    }
    destroyHeap(heap);
  }
}


int main()
{
  CU_pSuite pSuite = NULL;

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
  return CU_get_error();

  /* adds a suite to the registry */
  pSuite = CU_add_suite("Enqueue Test", init_suit, clean_suite);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* adds the tests to the suite */
  if ((NULL == CU_add_test(pSuite, "test of enqueueMaxHeap()", test_enqueueMaxHeap)) ||
      (NULL == CU_add_test(pSuite, "test of enqueueMinHeap()", test_enqueueMinHeap)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  pSuite = CU_add_suite("Dequeue Test", init_suit, clean_suite);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(pSuite, "test of dequeueMaxHeap()", test_dequeueMaxHeap)) ||
      (NULL == CU_add_test(pSuite, "test of dequeueMinHeap()", test_dequeueMinHeap)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
