#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_buscar, ListaVazia)
{
	struct lld ll;

	aux_ll_preencher(&ll, intcmp, NULL, 0, NULL);

	ASSERT_EQ(NULL, ll_buscar(&ll, NULL));

	aux_ll_limpar(&ll);
}

TEST(ll_buscar, UmElementoNaoExiste)
{
	struct lld ll;
	int dados[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	int buscado = 1;

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(NULL, ll_buscar(&ll, &buscado));

	aux_ll_limpar(&ll);
}

TEST(ll_buscar, UmElementoExiste)
{
	struct lld ll;
	int dados[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	int buscado = 0;

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[0], ll_buscar(&ll, &buscado));

	aux_ll_limpar(&ll);
}

TEST(ll_buscar, DoisElementosExistePrimeiroElemento)
{
	struct lld ll;
	int dados[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados) / sizeof(int)];

	int buscado = 0;

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados) / sizeof(int), elementos);

	ASSERT_EQ(elementos[0], ll_buscar(&ll, &buscado));

	aux_ll_limpar(&ll);
}

TEST(ll_buscar, DoisElementosExisteSegundoElemento)
{
	struct lld ll;
	int dados[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	int buscado = 1;

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[1], ll_buscar(&ll, &buscado));

	aux_ll_limpar(&ll);
}

TEST(ll_buscar, DoisElementosNaoExiste)
{
	struct lld ll;
	int dados[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	int buscado = 2;

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(NULL, ll_buscar(&ll, &buscado));

	aux_ll_limpar(&ll);
}
