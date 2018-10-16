#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_deletar, ListaVazia)
{
	struct lld* ll;

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);
	
	ll = (struct lld*)malloc(sizeof(struct lld));

	aux_ll_preencher(ll, intcmp, NULL, 0, NULL);

	ll_deletar(ll);

	ASSERT_NE(0, memoria_foi_liberada(ll, sizeof(struct lld))) << "Erro: voce esqueceu de liberar a memoria da lista";

	_CrtSetDbgFlag(tmpFlagOld);
}

TEST(ll_deletar, ListaUmElemento)
{
	struct lld* ll;
	int dados[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	int i;

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	ll = (struct lld*)malloc(sizeof(struct lld));

	aux_ll_preencher(ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ll_deletar(ll);

	for (i = 0; i < sizeof(dados)/sizeof(int); i++)
	{
		ASSERT_NE(0, memoria_foi_liberada(elementos[i], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento " << i << " da lista";
	}

	ASSERT_NE(0, memoria_foi_liberada(ll, sizeof(struct lld))) << "Erro: voce esqueceu de liberar a memoria da lista";

	_CrtSetDbgFlag(tmpFlagOld);
}

TEST(ll_deletar, ListaDoisElementos)
{
	struct lld* ll;
	int dados[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	int i;

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	ll = (struct lld*)malloc(sizeof(struct lld));

	aux_ll_preencher(ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ll_deletar(ll);

	for (i = 0; i < sizeof(dados)/sizeof(int); i++)
	{
		ASSERT_NE(0, memoria_foi_liberada(elementos[i], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento " << i << " da lista";
	}

	ASSERT_NE(0, memoria_foi_liberada(ll, sizeof(struct lld))) << "Erro: voce esqueceu de liberar a memoria da lista";

	_CrtSetDbgFlag(tmpFlagOld);
}

TEST(ll_deletar, ListaTresElementos)
{
	struct lld* ll;
	int dados[3] = { 0, 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	int i;

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	ll = (struct lld*)malloc(sizeof(struct lld));

	aux_ll_preencher(ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ll_deletar(ll);

	for (i = 0; i < sizeof(dados)/sizeof(int); i++)
	{
		ASSERT_NE(0, memoria_foi_liberada(elementos[i], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento " << i << " da lista";
	}

	ASSERT_NE(0, memoria_foi_liberada(ll, sizeof(struct lld))) << "Erro: voce esqueceu de liberar a memoria da lista";

	_CrtSetDbgFlag(tmpFlagOld);
}