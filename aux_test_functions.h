#ifndef AUX_TEST_FUNCTIONS_H
#define AUX_TEST_FUNCTIONS_H

#ifdef __cplusplus
#include "gtest/gtest.h"

extern "C"
{
#endif // __cplusplus
#include "array.h"
#include "ll.h"

	int intcmp(void* arg1, void* arg2);
#ifdef __cplusplus
}
#endif // __cplusplus

void aux_array_preencher(struct array* a, int(*compar)(void*, void*), int dados[], int tam);
int aux_array_iguais(const struct array* a1, const struct array* a2);
void aux_array_limpar(struct array* a);

void aux_ll_preencher(struct lld* ll, int (*compar)(void*, void*), int dados[], int tam_lista, struct lld_el* elementos[]);
int aux_ll_iguais(const struct lld* ll1, const struct lld* ll2);
void aux_ll_limpar(struct lld* ll);

int memoria_foi_liberada(void* arg, int tam);

#ifdef __cplusplus
::testing::AssertionResult ArraysMatch(const struct array* a1,
									   const struct array* a2);
::testing::AssertionResult LinkedListsMatch(const struct lld* a1,
											const struct lld* a2);
#endif // __cplusplus

#endif // AUX_TEST_FUNCTIONS_H
