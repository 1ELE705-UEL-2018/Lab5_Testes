#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "array.h"
}

TEST(array_remover, ArrayUmElemento)
{
	struct array a, a_depois;
	int dados[1] = { 0 };

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));
	aux_array_preencher(&a_depois, intcmp, NULL, 0);

	array_remover(&a, &a.dados[0]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}

TEST(array_remover, ArrayDoisElementosRemovePrimeiro)
{
	struct array a, a_depois;
	int dados[2] = { 0, 1 }, dados_depois[1] = { 1 };

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));
	aux_array_preencher(&a_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int));

	array_remover(&a, &a.dados[0]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}

TEST(array_remover, ArrayDoisElementosRemoveUltimo)
{
	struct array a, a_depois;
	int dados[2] = { 0, 1 }, dados_depois[1] = { 0 };

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));
	aux_array_preencher(&a_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int));

	array_remover(&a, &a.dados[1]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}

TEST(array_remover, ArrayTresElementosRemovePrimeiro)
{
	struct array a, a_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 1, 2 };

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));
	aux_array_preencher(&a_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int));

	array_remover(&a, &a.dados[0]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}

TEST(array_remover, ArrayTresElementosRemoveUltimo)
{
	struct array a, a_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 0, 1 };

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));
	aux_array_preencher(&a_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int));

	array_remover(&a, &a.dados[2]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}

TEST(array_remover, ArrayTresElementosRemoveMeio)
{
	struct array a, a_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 0, 2 };

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));
	aux_array_preencher(&a_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int));

	array_remover(&a, &a.dados[1]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}

TEST(array_remover, ArrayNoveElementosRemoveQuatroPrimeiros)
{
	struct array a, a_depois;
	int dados[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 }, dados_depois[5] = { 4, 5, 6, 7, 8 };

	aux_array_preencher(&a, intcmp, dados, sizeof(dados)/sizeof(int));
	aux_array_preencher(&a_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int));

	array_remover(&a, &a.dados[0]);
	array_remover(&a, &a.dados[0]);
	array_remover(&a, &a.dados[0]);
	array_remover(&a, &a.dados[0]);

	ASSERT_TRUE(ArraysMatch(&a, &a_depois));

	aux_array_limpar(&a);
	aux_array_limpar(&a_depois);
}