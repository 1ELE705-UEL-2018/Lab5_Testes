#pragma once

struct lld_el
{
	void* dado;
	struct lld_el* ant;
	struct lld_el* prox;
};

struct lld
{
	struct lld_el* inicio;
	struct lld_el* fim;
	int (*compar)(void*, void*);
};

void ll_inicializar(struct lld* ll, int (*compar)(void*, void*));
void ll_inserir_elemento_apos(struct lld* ll, struct lld_el* el, struct lld_el* eln);
void ll_inserir_apos(struct lld* ll, struct lld_el* el, void* eln);
void ll_inserir_antes(struct lld* ll, struct lld_el* el, void* eln);
void ll_remover(struct lld* ll, struct lld_el* el);
struct lld_el* ll_buscar(struct lld* ll, void* eln);
void ll_deletar(struct lld* ll);
struct lld_el* ll_indexar(struct lld* ll, int n);
void ll_inserir_posicao(struct lld* ll, int n, void* eln);
void ll_concatenar(struct lld* ll1, struct lld* ll2);
void ll_inverter(struct lld* ll);
int ll_contar(struct lld* ll);
void ll_entrelacar(struct lld* ll1, struct lld* ll2);