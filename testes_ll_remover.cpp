#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_remover, ListaUmElemento)
{
	struct lld ll, ll_depois;
	int dados[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, NULL, 0, NULL);

	ll_remover(&ll, ll.inicio);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[0], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_remover, ListaDoisElementosRemovePrimeiro)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 },  dados_depois[1] = { 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.inicio);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[0], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}

TEST(ll_remover, ListaDoisElementosRemoveUltimo)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.fim);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[1], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}

TEST(ll_remover, ListaTresElementosRemovePrimeiro)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.inicio);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[0], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}

TEST(ll_remover, ListaTresElementosRemoveUltimo)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.fim);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[2], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}

TEST(ll_remover, ListaTresElementosRemoveMeio)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 0, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.inicio->prox);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[1], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}
