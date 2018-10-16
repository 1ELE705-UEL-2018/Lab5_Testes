#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_inverter, ListaVazia)
{
	struct lld ll, ll_depois;

	aux_ll_preencher(&ll, intcmp, NULL, 0, NULL);
	aux_ll_preencher(&ll_depois, intcmp, NULL, 0, NULL);

	ll_inverter(&ll);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inverter, ListaUmElemento)
{
	struct lld ll, ll_depois;
	int dados[1] = { 0 }, dados_depois[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inverter(&ll);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inverter, ListaDoisElementosDiferentes)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[2] = { 1, 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inverter(&ll);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inverter, ListaDoisElementosIguais)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 0 }, dados_depois[2] = { 0, 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inverter(&ll);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inverter, ListaTresElementos)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[3] = { 2, 1, 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inverter(&ll);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inverter, ListaQuatroElementos)
{
	struct lld ll, ll_depois;
	int dados[4] = { 0, 1, 2, 3 }, dados_depois[4] = { 3, 2, 1, 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inverter(&ll);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}