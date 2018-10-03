#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_inserir_apos, ListaVazia)
{
	struct lld ll, ll_depois;
	int dados[1] = { 0 }, dados_depois[1] = { 0 };
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, NULL, 0, NULL);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inserir_apos(&ll, NULL, &dados[0]);

	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inserir_apos, ListaUmElementoInsereInicio)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int) - 1];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados+1, sizeof(dados)/sizeof(int) - 1, elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inserir_apos(&ll, NULL, &dados[0]);

	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inserir_apos, ListaUmElementoInsereFim)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int) - 1];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int) - 1, elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inserir_apos(&ll, ll.inicio, &dados[1]);

	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inserir_apos, ListaDoisElementosInsereInicio)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[3] = { 0, 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int) - 1];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados+1, sizeof(dados)/sizeof(int) - 1, elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inserir_apos(&ll, NULL, &dados[0]);

	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inserir_apos, ListaDoisElementosInsereMeio)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 2, 1 }, dados_depois[3] = { 0, 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int) - 1];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int) - 1, elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inserir_apos(&ll, ll.inicio, &dados[2]);

	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}
