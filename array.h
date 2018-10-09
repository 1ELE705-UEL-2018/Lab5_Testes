#pragma once

struct array_el
{
	void* dado;
};

struct array
{
	struct array_el* dados;
	size_t tam;
	size_t tam_alocado;
	int(*compar)(void*, void*);
};

void array_inicializar(struct array* a, int(*compar)(void*, void*));
void array_inserir_apos(struct array* a, struct array_el* el, void* eln);
void array_remover(struct array* a, struct array_el* el);
struct array_el* array_buscar(struct array* a, void* eln);