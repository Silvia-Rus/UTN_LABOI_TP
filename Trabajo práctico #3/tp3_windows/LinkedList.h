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

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void); //devuelve puntero  una lista
int ll_len(LinkedList* this);//aqui compruebo cuando mide unaa lista (para iterar)
Node* test_getNode(LinkedList* this, int nodeIndex);//NO USAR AHORA
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);//NO USAR AHORA
int ll_add(LinkedList* this, void* pElement);//incroporar un empleado a la lista. le pasamos puntero a al lista devuelto por el new y el elemento qque queremos guardar le pasamos un pntero a empleados
void* ll_get(LinkedList* this, int index);//para pedirlos datos. Recibe la posición del empleado y nos devuelve un puntero a void que lo guardamos a puntero empleado
int ll_set(LinkedList* this, int index,void* pElement);//gurdar un elemento en un algún lugar concreto de la lista (en caso de que exista)
int ll_remove(LinkedList* this,int index);//le decimos una posición de la lista y borra lo que hay
int ll_clear(LinkedList* this);//borra todos los elementos de la lista, solo pide la lista
int ll_deleteLinkedList(LinkedList* this);//borra de la memoria la lista muy jarto
int ll_indexOf(LinkedList* this, void* pElement);//en qué posición está un elemento concretp
int ll_isEmpty(LinkedList* this);//para saber si un posici´n de la lista está vacía
int ll_push(LinkedList* this, int index, void* pElement);//permite elegr un lugar para agregar un elemento tipo insertando
void* ll_pop(LinkedList* this,int index);//sacar un elemento y devuelve el puntero ahi
int ll_contains(LinkedList* this, void* pElement);//no la vamos a usar por ahora
int ll_containsAll(LinkedList* this,LinkedList* this2);//no la vamos a usar por ahora
LinkedList* ll_subList(LinkedList* this,int from,int to);//hacer una sublista de una lista original
LinkedList* ll_clone(LinkedList* this);//duplicar la lista en memoria
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//para ordenar
