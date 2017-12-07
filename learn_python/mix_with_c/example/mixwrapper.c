#include "Python.h"
#include "mix.h"
#include <stdlib.h>
#include <stdio.h>

static PyObject *mix_reverse(PyObject *self ,PyObject *args)
{
	char *old;
	char *new;
	PyObject* ret;	
	if(!PyArg_ParseTuple(args,"s",&old))//change data of python to C
		return NULL;

	new = malloc(strlen(old)+1);
	strcpy(new,old);
	reverse(new);

	ret = (PyObject*)Py_BuildValue("s",new);	
	free(new);
	return ret;
}

static PyObject *mix_test(PyObject *self,PyObject *args)
{
	test();

	return (PyObject*)Py_BuildValue("");
}


static PyMethodDef mixMethods[]={
	{"reverse",mix_reverse,METH_VARARGS},
	{"test",mix_test,METH_VARARGS},
	
};


void initmix(void)
{
	Py_InitModule("mix",mixMethods);
}
