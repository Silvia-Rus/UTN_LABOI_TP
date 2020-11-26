/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main(void)
{
	//no descomentar todo antes de ponerse a hacer. Ir descomentando una a una.
	//hacerlas en el orden que salen porque si no se rompe porque usan las de arriba.
	//en testing hay un archivo para probar cada una de las funciones.
	//en el main de testing están las opciones de lo que se quiere testear

	startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort


/*startTesting(1);  // ll_newLinkedList: crea una lista y me permite manejar elementos de un tipo
 					Cada vez que llamo a NewLinkedList creo una lista nueva.

 startTesting(5);  // ll_add: agrega un elemento a la lista al final de la lista. Ahí le meye UN PUNTERO a un empleado (o whatever).
 	 	 	 	 	 pero puede ser de cualquier tipo el puntero (es void). Así lo puedo usar en cualquier programa esta función.

 startTesting(6);  // ll_get: devuelve un elemento de la lista en una posición determinada (dándole un índice).

 startTesting(7);  // ll_set: al contrario que add, puedo añadir algo en un lugar en el que ya había algo.
 	 	 	 	 	 no es añadir uno nuevo al final. Por eso hay que darle una posición del índice QUE TIENE QUE EXISTIR.
					La longitud de la lista no varía porque estás cambiando un valor por otro. Al contrario de add que añade uno abajo.

 startTesting(2);  // ll_len //devuelve el tamaño de la lista. sirve para recorrerla.

 startTesting(19); // ll_sort //ordena los elementos de la lista.
					ay que pasarle una función a la que llamamos "función criterio" que compara los elementos.
					ll_sort no compara, lo hace una función externa.

startTesting(9);  // ll_clear -- te la deja a 0, comoo recién creada.

startTesting(10); // ll_deleteLinkedList -- una vez se borra no se puede usar nunca más.
libera la memoria que pidió al crearse

startTesting(12); // ll_isEmpty -devuelve si la lista esá vacía o sea ll_len es igual 0:


	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode



	startTesting(8);  // ll_remove


	startTesting(11); // ll_indexOf

	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	 */
    return 0;
}

































