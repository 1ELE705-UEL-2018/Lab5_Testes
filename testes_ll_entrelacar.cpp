#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_entrelacar, ListasVaziaVazia)
{
	struct lld ll1, ll2, ll_depois;

	aux_ll_preencher(&ll1, intcmp, NULL, 0, NULL);
	aux_ll_preencher(&ll2, intcmp, NULL, 0, NULL);
	aux_ll_preencher(&ll_depois, intcmp, NULL, 0, NULL);

	ll_entrelacar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_entrelacar, ListasVaziaUmElemento)
{
	struct lld ll1, ll2, ll_depois;
	int dados2[1] = { 0 }, dados_depois[1] = { 0 };
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, NULL, 0, NULL);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_entrelacar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_entrelacar, ListasUmElementoVazia)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[1] = { 0 }, dados_depois[1] = { 0 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, NULL, 0, NULL);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_entrelacar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_entrelacar, ListasUmElementoUmElemento)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[1] = { 0 }, dados2[1] = { 1 }, dados_depois[2] = { 0, 1 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_entrelacar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_entrelacar, ListasDoisElementosUmElemento)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[2] = { 0, 2 }, dados2[1] = { 1 }, dados_depois[3] = { 0, 1, 2 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_entrelacar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_entrelacar, ListasUmElementoDoisElementos)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[1] = { 0 }, dados2[2] = { 1, 2 }, dados_depois[3] = { 0, 1, 2 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_entrelacar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_entrelacar, ListasDoisElementosDoisElementos)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[2] = { 0, 2 }, dados2[2] = { 1, 3 }, dados_depois[4] = { 0, 1, 2, 3 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_entrelacar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_entrelacar, ListasUmElementoTresElementos)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[1] = { 0 }, dados2[3] = { 1, 2, 3 }, dados_depois[4] = { 0, 1, 2, 3 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_entrelacar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_entrelacar, ListasTresElementoUmElemento)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[3] = { 0, 2, 3 }, dados2[1] = { 1 }, dados_depois[4] = { 0, 1, 2, 3 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_entrelacar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_entrelacar, ListasDoisElementosTresElementos)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[2] = { 0, 2 }, dados2[3] = { 1, 3, 4 }, dados_depois[5] = { 0, 1, 2, 3, 4 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_entrelacar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_entrelacar, ListasTresElementosDoisElementos)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[3] = { 0, 2, 4 }, dados2[2] = { 1, 3 }, dados_depois[5] = { 0, 1, 2, 3, 4 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_entrelacar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_entrelacar, ListasTresElementosTresElementos)
{
	struct lld ll1, ll2, ll_depois;
	int dados1[3] = { 0, 2, 4 }, dados2[3] = { 1, 3, 5 }, dados_depois[6] = { 0, 1, 2, 3, 4, 5 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_entrelacar(&ll1, &ll2);

	ASSERT_TRUE(LinkedListsMatch(&ll1, &ll_depois));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll_depois);
}