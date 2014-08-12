/*
 * Copyright (c) 2012 Anton Tyurin <noxiouz@yandex.ru>
 *
 * This file is part of Handystats for Python.
 *
 * Tokentarser is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Tokenparser is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <Python.h>

#include <handystats/operation.hpp>
#include <handystats/json_dump.hpp>
#include <handystats/metrics_dump.hpp>
#include <handystats/measuring_points.hpp>

PyDoc_STRVAR(handy_init__doc__, "");
static PyObject*
handy_init(PyObject* self, PyObject* args)
{
    HANDY_INIT();
    Py_RETURN_NONE;
}

PyDoc_STRVAR(handy_finalize__doc__, "");
static PyObject*
handy_finalize(PyObject* self, PyObject* args)
{
    HANDY_FINALIZE();
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_counter_init__doc__, "");
static PyObject*
handy_counter_init(PyObject* self, PyObject* args)
{
    const char *name;
    int value;

    if (!PyArg_ParseTuple(args, "s|i:value", &name, &value)) {
        return NULL;
    }

    HANDY_COUNTER_INIT(name, value);

    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_counter_increment__doc__, "");
static PyObject*
handy_counter_increment(PyObject* self, PyObject* args)
{
    const char *name;
    int value;

    if (!PyArg_ParseTuple(args, "si", &name, &value)) {
        return NULL;
    }

    HANDY_COUNTER_INCREMENT(name, value);
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_counter_decrement__doc__, "");
static PyObject*
handy_counter_decrement(PyObject* self, PyObject* args)
{
    const char *name;
    int value;

    if (!PyArg_ParseTuple(args, "si", &name, &value)) {
        return NULL;
    }

    HANDY_COUNTER_DECREMENT(name, value);
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_counter_change__doc__, "");
static PyObject*
handy_counter_change(PyObject* self, PyObject* args)
{
    const char *name;
    int value;

    if (!PyArg_ParseTuple(args, "si", &name, &value)) {
        return NULL;
    }

    HANDY_COUNTER_CHANGE(name, value);
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_json_dump__doc__, "Return statistic as formated json");
static PyObject*
handy_json_dump(PyObject* self, PyObject* args)
{
    PyObject* value = Py_BuildValue("s", HANDY_JSON_DUMP()->c_str());
    return value;
}


static PyMethodDef handystats_methods[] =
{
    {"handy_init", handy_init, METH_NOARGS, handy_init__doc__},
    {"handy_finalize", handy_finalize, METH_NOARGS, handy_finalize__doc__},
    {"handy_counter_init", handy_counter_init, METH_VARARGS, handy_counter_init__doc__},
    {"handy_counter_increment", handy_counter_increment, METH_VARARGS, handy_counter_increment__doc__},
    {"handy_counter_decrement", handy_counter_decrement, METH_VARARGS, handy_counter_decrement__doc__},
    {"handy_counter_change", handy_counter_change, METH_VARARGS, handy_counter_change__doc__},
    {"handy_json_dump", handy_json_dump, METH_NOARGS, handy_json_dump__doc__},
    {NULL, NULL, 0, NULL}
};


extern "C" {
    void
    init_handystats(void)
    {
        (void) Py_InitModule3("_handystats", handystats_methods, NULL);
    }
}
