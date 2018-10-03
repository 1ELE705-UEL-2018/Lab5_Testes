#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "array.h"
}

TEST(array_inserir_apos, ArrayVazioInsereUmElemento)
{
	struct array a, a_depois;
	int dados[1] = { 0 }, dados_depois[1] = { 0 };

	aux_array_preencher(&a, intcmp, NULL, 0);
	aux_array_preencher(&a_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int));

	array_inserir_apos(&a, NULL, &dados[0]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}

TEST(array_inserir_apos, ArrayUmElementoInsereInicio)
{
	struct array a, a_depois;
	int dados[2] = { 0, 1 }, dados_depois[2] = { 0, 1 };

	aux_array_preencher(&a, intcmp, dados+1, sizeof(dados)/sizeof(int) - 1);
	aux_array_preencher(&a_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int));

	array_inserir_apos(&a, NULL, &dados[0]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}

TEST(array_inserir_apos, ArrayUmElementoInsereFim)
{
	struct array a, a_depois;
	int dados[2] = { 0, 1 }, dados_depois[2] = { 0, 1 };

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int) - 1);
	aux_array_preencher(&a_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int));

	array_inserir_apos(&a, &a.dados[0], &dados[1]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}

TEST(array_inserir_apos, ArrayDoisElementosInsereInicio)
{
	struct array a, a_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[3] = { 0, 1, 2 };

	aux_array_preencher(&a, intcmp, dados+1, sizeof(dados)/sizeof(int) - 1);
	aux_array_preencher(&a_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int));

	array_inserir_apos(&a, NULL, &dados[0]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}

TEST(array_inserir_apos, ArrayDoisElementosInsereMeio)
{
	struct array a, a_depois;
	int dados[3] = { 0, 2, 1 }, dados_depois[3] = { 0, 1, 2 };

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int) - 1);
	aux_array_preencher(&a_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int));

	array_inserir_apos(&a, &a.dados[0], &dados[2]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}

TEST(array_inserir_apos, ArraySeteElementosInsereInicio)
{
	struct array a, a_depois;
	int dados[8] = { 0, 1, 2, 3, 4, 5, 6, 7 }, dados_depois[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };

	aux_array_preencher(&a, intcmp, dados+1, sizeof(dados)/sizeof(int) - 1);
	aux_array_preencher(&a_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int));

	array_inserir_apos(&a, NULL, &dados[0]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}

TEST(array_inserir_apos, ArrayOitoElementosInsereInicio)
{
	struct array a, a_depois;
	int dados[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 }, dados_depois[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

	aux_array_preencher(&a, intcmp, dados+1, sizeof(dados)/sizeof(int) - 1);
	aux_array_preencher(&a_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int));

	array_inserir_apos(&a, NULL, &dados[0]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}