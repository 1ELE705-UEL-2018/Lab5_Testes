#include <cstddef>
#include <cstdlib>

extern "C"
{
#include "ll.h"
}
#include "aux_test_functions.h"

int intcmp(void* arg1, void* arg2)
{
	int* a1 = (int*)arg1;
	int* a2 = (int*)arg2;

	return *a1 - *a2;
}

void aux_array_preencher(struct array* a, int(*compar)(void*, void*), int dados[], int tam)
{
	int i;

	a->compar = compar;
	a->tam = tam;
	if (a->tam <= 8)
	{
		a->tam_alocado = 8;
	}
	else
	{
		a->tam_alocado = 8;
		while (a->tam_alocado < a->tam)
		{
			a->tam_alocado *= 2;
		}
	}

	a->dados = (struct array_el*)malloc(a->tam_alocado * sizeof(struct array_el*));

	for (i = 0; i < tam; i++)
	{
		a->dados[i].dado = (void*)&dados[i];
	}
}

int aux_array_iguais(const struct array* a1, const struct array* a2)
{
	size_t i;

	if (a1->compar != a2->compar)
	{
		return -2;
	}

	if (a1->tam != a2->tam)
	{
		return -3;
	}

	if (a1->tam_alocado != a2->tam_alocado)
	{
		return -4;
	}

	for (i = 0; i < a1->tam; i++)
	{
		if (a1->compar(a1->dados[i].dado, a2->dados[i].dado) != 0)
		{
			return i;
		}
	}

	return -1;
}

void aux_array_limpar(struct array* a)
{
	if (a->dados != NULL)
	{
		free(a->dados);
	}
}

void aux_ll_preencher(struct lld* ll, int(*compar)(void*, void*), int dados[], int tam_lista, struct lld_el* elementos[])
{
	int i;

	ll->compar = compar;

	for (i = 0; i < tam_lista; i++)
	{
		elementos[i] = NULL;
	}

	if (tam_lista == 0)
	{
		ll->inicio = ll->fim = NULL;
		return;
	}
	else
	{
		elementos[0] = (struct lld_el*)malloc(sizeof(struct lld_el));
		elementos[tam_lista - 1] = (struct lld_el*)malloc(sizeof(struct lld_el));
		ll->inicio = elementos[0];
		ll->fim = elementos[tam_lista - 1];
	}

	if (tam_lista > 1)
	{
		if (elementos[1] == NULL)
		{
			elementos[1] = (struct lld_el*)malloc(sizeof(struct lld_el));
		}
		elementos[0]->prox = elementos[1];

		for (i = 1; i < tam_lista - 1; i++)
		{
			elementos[i]->ant = elementos[i - 1];
			elementos[i]->dado = &dados[i];
			if (elementos[i + 1] == NULL)
			{
				elementos[i + 1] = (struct lld_el*)malloc(sizeof(struct lld_el));
			}
			elementos[i]->prox = elementos[i + 1];
		}

		elementos[tam_lista - 1]->ant = elementos[tam_lista - 2];
	}

	elementos[0]->ant = NULL;
	elementos[0]->dado = &dados[0];
	elementos[tam_lista - 1]->dado = &dados[tam_lista - 1];
	elementos[tam_lista - 1]->prox = NULL;
}

int aux_ll_consistente(const struct lld* ll)
{
	struct lld_el* el;
	struct lld_el* el_ant = NULL;
	struct lld_el* el_prox = NULL;

	int i;

	if (ll->inicio && ll->inicio->ant != NULL)
	{
		return -2;
	}

	if (ll->fim && ll->fim->prox != NULL)
	{
		return -3;
	}

	for (i = 0, el = ll->inicio; el != NULL; el = el->prox)
	{
		if (el->prox && el->prox->ant != el)
		{
			return i;
		}

		i++;

		el_ant = el;
	}

	if (el_ant != ll->fim)
	{
		return -4;
	}

	return -1;
}

int aux_ll_iguais(const struct lld* ll1, const struct lld* ll2)
{
	int i = 0;

	struct lld_el *el1, *el2;

	if (ll1->compar != ll2->compar)
	{
		return -2;
	}

	el1 = ll1->inicio;
	el2 = ll2->inicio;

	while (el1 != NULL && el2 != NULL)
	{
		if (ll1->compar(el1->dado, el2->dado) != 0)
		{
			return i;
		}

		el1 = el1->prox;
		el2 = el2->prox;
		i++;
	}

	if (el1 != el2)
	{
		return -3;
	}

	return -1;
}

void aux_ll_limpar(struct lld* ll)
{
	struct lld_el* el = ll->inicio;

	while (el != NULL)
	{
		struct lld_el* aux = el->prox;
		free(el);
		el = aux;
	}
}

int memoria_foi_liberada(void* arg, int tam)
{
	int i;
	unsigned char* arg_char = (unsigned char*)arg;
	for (i = 0; i < tam; i++)
	{
		if (arg_char[i] != 0xDD)
		{
			return 0;
		}
	}

	return 1;
}

::testing::AssertionResult ArraysMatch(const struct array* a1, const struct array* a2)
{
	int res = aux_array_iguais(a1, a2);

	switch (res)
	{
		case -1:
			return ::testing::AssertionSuccess();
		case -2:
			return ::testing::AssertionFailure() << "Funcoes de comparacao diferentes";
		case -3:
			return ::testing::AssertionFailure() << "Tamanho dos arrays diferente";
		case -4:
			return ::testing::AssertionFailure() << "Tamanho da memoria alocada diferente";
		default:
			return ::testing::AssertionFailure() << "a1->dados[" << res << "] != a2->dados[" << res << "]";
	}
}

::testing::AssertionResult LinkedListConsistent(const struct lld* ll)
{
	int res = aux_ll_consistente(ll);

	switch (res)
	{
		case -1:
			return ::testing::AssertionSuccess();
		case -2:
			return ::testing::AssertionFailure() << "ll->inicio->ant != NULL";
		case -3:
			return ::testing::AssertionFailure() << "ll->fim->prox != NULL";
		case -4:
			return ::testing::AssertionFailure() << "Ultimo elemento da lista != ll->fim";
		default:
			return ::testing::AssertionFailure() << "Inconsistencia na posicao " << res << " da lista: el->prox->ant != el ou el->ant->prox != e";
	}
}

::testing::AssertionResult LinkedListsMatch(const struct lld* ll1, const struct lld* ll2)
{
	int res = aux_ll_iguais(ll1, ll2);

	switch (res)
	{
		case -1:
			return ::testing::AssertionSuccess();
		case -2:
			return ::testing::AssertionFailure() << "Funcoes de comparacao diferentes";
		case -3:
			return ::testing::AssertionFailure() << "Tamanho das listas diferente";
		default:
			return ::testing::AssertionFailure() << "Elemento na posicao " << res << " diferente entre as duas listas";
	}
}
