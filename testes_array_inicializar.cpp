#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "array.h"
}

TEST(array_inicializar, Inicializar)
{
	struct array a = { NULL, 0, 0, NULL };

	array_inicializar(&a, intcmp);

	ASSERT_NE((struct array_el*)NULL, a.dados);
	ASSERT_EQ(0, a.tam);
	ASSERT_EQ(8, a.tam_alocado);
	ASSERT_EQ(&intcmp, a.compar);

	aux_array_limpar(&a);
}
