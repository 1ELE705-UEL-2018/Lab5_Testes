#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "array.h"
}

TEST(aux_array_preencher, ArrayVazio)
{
	struct array a;

	aux_array_preencher(&a, intcmp, NULL, 0);

	ASSERT_NE((void**)NULL, a.dados);
	ASSERT_EQ(0, a.tam);
	ASSERT_EQ(8, a.tam_alocado);
	ASSERT_EQ(&intcmp, a.compar);

	aux_array_limpar(&a);
}

TEST(aux_array_preencher, ArrayUmElemento)
{
	struct array a;
	int dados[1] = { 1 };
	int i;

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));

	ASSERT_NE((void**)NULL, a.dados);
	ASSERT_EQ(sizeof(dados)/sizeof(int), a.tam);
	ASSERT_EQ(8, a.tam_alocado);
	ASSERT_EQ(&intcmp, a.compar);

	for (i = 0; i < sizeof(dados)/sizeof(int); i++)
	{
		ASSERT_EQ(&dados[i], a.dados[i]);
	}

	aux_array_limpar(&a);
}

TEST(aux_array_preencher, ArrayDoisElementos)
{
	struct array a;
	int dados[2] = { 1, 2 };
	int i;

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));

	ASSERT_NE((void**)NULL, a.dados);
	ASSERT_EQ(sizeof(dados)/sizeof(int), a.tam);
	ASSERT_EQ(8, a.tam_alocado);
	ASSERT_EQ(&intcmp, a.compar);

	for (i = 0; i < sizeof(dados)/sizeof(int); i++)
	{
		ASSERT_EQ(&dados[i], a.dados[i]);
	}

	aux_array_limpar(&a);
}

TEST(aux_array_preencher, ArrayTresElementos)
{
	struct array a;
	int dados[3] = { 1, 2, 3 };
	int i;

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));

	ASSERT_NE((void**)NULL, a.dados);
	ASSERT_EQ(sizeof(dados)/sizeof(int), a.tam);
	ASSERT_EQ(8, a.tam_alocado);
	ASSERT_EQ(&intcmp, a.compar);

	for (i = 0; i < sizeof(dados)/sizeof(int); i++)
	{
		ASSERT_EQ(&dados[i], a.dados[i]);
	}


	aux_array_limpar(&a);
}

TEST(aux_array_preencher, ArrayQuatroElementos)
{
	struct array a;
	int dados[4] = { 1, 2, 3, 4 };
	int i;

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));

	ASSERT_NE((void**)NULL, a.dados);
	ASSERT_EQ(sizeof(dados)/sizeof(int), a.tam);
	ASSERT_EQ(8, a.tam_alocado);
	ASSERT_EQ(&intcmp, a.compar);

	for (i = 0; i < sizeof(dados)/sizeof(int); i++)
	{
		ASSERT_EQ(&dados[i], a.dados[i]);
	}

	aux_array_limpar(&a);
}

TEST(aux_array_preencher, ArrayOitoElementos)
{
	struct array a;
	int dados[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int i;

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));

	ASSERT_NE((void**)NULL, a.dados);
	ASSERT_EQ(sizeof(dados)/sizeof(int), a.tam);
	ASSERT_EQ(8, a.tam_alocado);
	ASSERT_EQ(&intcmp, a.compar);

	for (i = 0; i < sizeof(dados)/sizeof(int); i++)
	{
		ASSERT_EQ(&dados[i], a.dados[i]);
	}

	aux_array_limpar(&a);
}

TEST(aux_array_preencher, ArrayNoveElementos)
{
	struct array a;
	int dados[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i;

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));

	ASSERT_NE((void**)NULL, a.dados);
	ASSERT_EQ(sizeof(dados)/sizeof(int), a.tam);
	ASSERT_EQ(16, a.tam_alocado);
	ASSERT_EQ(&intcmp, a.compar);

	for (i = 0; i < sizeof(dados)/sizeof(int); i++)
	{
		ASSERT_EQ(&dados[i], a.dados[i]);
	}

	aux_array_limpar(&a);
}