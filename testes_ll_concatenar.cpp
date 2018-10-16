#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_concatenar, ListasVaziaVazia)
{
	struct lld ll1, ll2, ll_depois;

	aux_ll_preencher(&ll1, intcmp, NULL, 0, NULL);
	aux_ll_preencher(&ll2, intcmp, NULL, 0, NULL);
	aux_ll_preencher(&ll_depois, intcmp, NULL, 0, NULL);

	ll_concatenar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListConsistent(&ll1));
	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_concatenar, ListasVaziaUmElemento)
{
	struct lld ll1, ll2, ll_depois;
	int dados2[1] = { 0 }, dados_depois[1] = { 0 };
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, NULL, 0, NULL);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_concatenar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListConsistent(&ll1));
	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_concatenar, ListasUmElementoVazia)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[1] = { 0 }, dados_depois[1] = { 0 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, NULL, 0, NULL);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_concatenar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListConsistent(&ll1));
	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_concatenar, ListasUmElementoUmElemento)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[1] = { 0 }, dados2[1] = { 1 }, dados_depois[2] = { 0, 1 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_concatenar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListConsistent(&ll1));
	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_concatenar, ListasDoisElementosUmElemento)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[2] = { 0, 1 }, dados2[1] = { 2 }, dados_depois[3] = { 0, 1, 2};
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_concatenar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListConsistent(&ll1));
	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_concatenar, ListasUmElementoDoisElementos)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[1] = { 0 }, dados2[2] = { 1, 2 }, dados_depois[3] = { 0, 1, 2 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_concatenar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListConsistent(&ll1));
	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_concatenar, ListasDoisElementosDoisElementos)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[2] = { 0, 1 }, dados2[2] = { 2, 3 }, dados_depois[4] = { 0, 1, 2, 3 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_concatenar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListConsistent(&ll1));
	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_concatenar, ListasUmElementoTresElementos)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[1] = { 0 }, dados2[3] = { 1, 2, 3 }, dados_depois[4] = { 0, 1, 2, 3 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_concatenar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListConsistent(&ll1));
	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_concatenar, ListasTresElementoUmElemento)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[3] = { 0, 1, 2 }, dados2[1] = { 3 }, dados_depois[4] = { 0, 1, 2, 3 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_concatenar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListConsistent(&ll1));
	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_concatenar, ListasDoisElementosTresElementos)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[2] = { 0, 1 }, dados2[3] = { 2, 3, 4 }, dados_depois[5] = { 0, 1, 2, 3, 4 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_concatenar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListConsistent(&ll1));
	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_concatenar, ListasTresElementosDoisElementos)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[3] = { 0, 1, 2 }, dados2[2] = { 3, 4 }, dados_depois[5] = { 0, 1, 2, 3, 4 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_concatenar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListConsistent(&ll1));
	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_concatenar, ListasTresElementosTresElementos)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[3] = { 0, 1, 2 }, dados2[3] = { 3, 4, 5 }, dados_depois[6] = { 0, 1, 2, 3, 4, 5 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_concatenar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListConsistent(&ll1));
	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}