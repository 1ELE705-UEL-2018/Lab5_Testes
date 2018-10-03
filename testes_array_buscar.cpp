#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "array.h"
}

TEST(array_buscar, ArrayVazio)
{
	struct array a;

	aux_array_preencher(&a, intcmp, NULL, 0);

	ASSERT_EQ(NULL, array_buscar(&a, NULL));

	aux_array_limpar(&a);
}

TEST(array_buscar, UmElementoNaoExiste)
{
	struct array a;
	int dados[1] = { 0 };
	int buscado = 1;

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));

	ASSERT_EQ(NULL, array_buscar(&a, &buscado));

	aux_array_limpar(&a);
}

TEST(array_buscar, UmElementoExiste)
{
	struct array a;
	int dados[1] = { 0 };
	int buscado = 0;

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));

	ASSERT_EQ(&a.dados[0], array_buscar(&a, &buscado));

	aux_array_limpar(&a);
}

TEST(array_buscar, DoisElementosExisteSegundoElemento)
{
	struct array a;
	int dados[2] = { 0, 1};
	int buscado = 1;

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));

	ASSERT_EQ(&a.dados[1], array_buscar(&a, &buscado));

	aux_array_limpar(&a);
}

TEST(array_buscar, DoisElementosNaoExiste)
{
	struct array a;
	int dados[2] = { 0, 1 };
	int buscado = 2;

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));

	ASSERT_EQ(NULL, array_buscar(&a, &buscado));

	aux_array_limpar(&a);
}