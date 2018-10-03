#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(aux_array_iguais, ArraysVaziosComparIgual)
{
	struct array a1, a2;

	aux_array_preencher(&a1, intcmp, NULL, 0);
	aux_array_preencher(&a2, intcmp, NULL, 0);

	ASSERT_EQ(-1, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysVaziosComparDiferente)
{
	struct array a1, a2;

	aux_array_preencher(&a1, intcmp, NULL, 0);
	aux_array_preencher(&a2, NULL, NULL, 0);

	ASSERT_EQ(-2, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);

}

TEST(aux_array_iguais, ArraysUmElementoIguais)
{
	struct array a1, a2;
	int dados1[1] = { 1 }, dados2[1] = { 1 };

	aux_array_preencher(&a1, intcmp, dados1, sizeof(dados1)/sizeof(int));
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(-1, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysUmElementoDiferentes)
{
	struct array a1, a2;
	int dados1[1] = { 0 }, dados2[1] = { 1 };

	aux_array_preencher(&a1, intcmp, dados1, sizeof(dados1)/sizeof(int));
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(0, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysDoisElementosIguais)
{
	struct array a1, a2;
	int dados1[2] = { 0, 1 }, dados2[2] = { 0, 1 };

	aux_array_preencher(&a1, intcmp, dados1, sizeof(dados1)/sizeof(int));
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(-1, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysDoisElementosDiferentesPrimeiro)
{
	struct array a1, a2;
	int dados1[2] = { 1, 1 }, dados2[2] = { 0, 1 };

	aux_array_preencher(&a1, intcmp, dados1, sizeof(dados1)/sizeof(int));
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(0, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysDoisElementosDiferentesSegundo)
{
	struct array a1, a2;
	int dados1[2] = { 0, 0 }, dados2[2] = { 0, 1 };

	aux_array_preencher(&a1, intcmp, dados1, sizeof(dados1)/sizeof(int));
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(1, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysTresElementosIguais)
{
	struct array a1, a2;
	int dados1[3] = { 0, 1, 2 }, dados2[3] = { 0, 1, 2 };

	aux_array_preencher(&a1, intcmp, dados1, sizeof(dados1)/sizeof(int));
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(-1, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysTresElementosDiferentesPrimeiro)
{
	struct array a1, a2;
	int dados1[3] = { 1, 1, 2 }, dados2[3] = { 0, 1, 2 };

	aux_array_preencher(&a1, intcmp, dados1, sizeof(dados1)/sizeof(int));
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(0, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysTresElementosDiferentesSegundo)
{
	struct array a1, a2;
	int dados1[3] = { 0, 2, 2 }, dados2[3] = { 0, 1, 2 };

	aux_array_preencher(&a1, intcmp, dados1, sizeof(dados1)/sizeof(int));
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(1, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysTresElementosDiferentesTerceiro)
{
	struct array a1, a2;
	int dados1[3] = { 0, 1, 0 }, dados2[3] = { 0, 1, 2 };

	aux_array_preencher(&a1, intcmp, dados1, sizeof(dados1)/sizeof(int));
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(2, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysVazioUmElemento)
{
	struct array a1, a2;
	int dados2[3] = { 0, 1, 2 };

	aux_array_preencher(&a1, intcmp, NULL, 0);
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(-3, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysUmElementoDoisElementos)
{
	struct array a1, a2;
	int dados1[1] = { 0 }, dados2[2] = { 0, 0 };

	aux_array_preencher(&a1, intcmp, dados1, sizeof(dados1)/sizeof(int));
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(-3, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysUmElementoTresElementos)
{
	struct array a1, a2;
	int dados1[1] = { 0 }, dados2[3] = { 0, 0, 0 };

	aux_array_preencher(&a1, intcmp, dados1, sizeof(dados1)/sizeof(int));
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(-3, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysDoisElementosTresElementos)
{
	struct array a1, a2;
	int dados1[2] = { 0, 0 }, dados2[3] = { 0, 0, 0 };

	aux_array_preencher(&a1, intcmp, dados1, sizeof(dados1)/sizeof(int));
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(-3, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}

TEST(aux_array_iguais, ArraysOitoElementosDiferentesNoTamanhoAlocado)
{
	struct array a1, a2;
	int dados1[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 }, dados2[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };

	aux_array_preencher(&a1, intcmp, dados1, sizeof(dados1)/sizeof(int));
	aux_array_preencher(&a2, intcmp, dados2, sizeof(dados2)/sizeof(int));

	a1.tam--;

	ASSERT_EQ(-4, aux_array_iguais(&a1, &a2));

	aux_array_limpar(&a1);
	aux_array_limpar(&a2);
}