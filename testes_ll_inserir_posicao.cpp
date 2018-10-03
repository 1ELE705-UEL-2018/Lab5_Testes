#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_inserir_posicao, ListaUmElementoInsereFim)
{
	struct lld ll, ll_depois;
	int dados[1] = { 0 }, dados_depois[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];
	int a_inserir = 1;

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inserir_posicao(&ll, 0, &a_inserir);

	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inserir_posicao, ListaDoisElementoInsereMeio)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 2 }, dados_depois[3] = { 0, 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];
	int a_inserir = 1;

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inserir_posicao(&ll, 0, &a_inserir);

	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inserir_posicao, ListaDoisElementoInsereFim)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[3] = { 0, 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];
	int a_inserir = 2;

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inserir_posicao(&ll, 1, &a_inserir);

	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inserir_posicao, ListaTresElementoInsereSegundo)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 2, 3 }, dados_depois[4] = { 0, 1, 2, 3 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];
	int a_inserir = 1;

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inserir_posicao(&ll, 0, &a_inserir);

	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inserir_posicao, ListaTresElementoInsereTerceiro)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 3 }, dados_depois[4] = { 0, 1, 2, 3 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];
	int a_inserir = 2;

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inserir_posicao(&ll, 1, &a_inserir);

	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_inserir_posicao, ListaTresElementoInsereQuarto)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[4] = { 0, 1, 2, 3 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];
	int a_inserir = 3;

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_inserir_posicao(&ll, 2, &a_inserir);

	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}