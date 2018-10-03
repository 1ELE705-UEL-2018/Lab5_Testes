#pragma once

struct array
{
	void** dados;
	int tam;
	int tam_alocado;
	int(*compar)(void*, void*);
};

void array_inicializar(struct array* a, int(*compar)(void*, void*));
void array_inserir_apos(struct array* a, void* el, void* eln);
void array_remover(struct array* a, void* el);
void* array_buscar(struct array* a, void* eln);