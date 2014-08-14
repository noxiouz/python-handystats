/*
 * Copyright (c) 2014 Anton Tyurin <noxiouz@yandex.ru>
 *
 * This file is part of Handystats for Python.
 *
 * Handystats for Python is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Handystats for Python is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <Python.h>
#include <structmember.h>

#include "counter.hpp"

using namespace handystats;

PyObject*
handystats_counter_t::construct(PyTypeObject * type, PyObject *args, PyObject * kwargs) {
    (void) args;
    (void) kwargs;

    handystats_counter_t * self = reinterpret_cast<handystats_counter_t*>(type->tp_alloc(type, 0));
    self->m_counter = metrics::counter();
    return reinterpret_cast<PyObject*>(self);
}


void
handystats_counter_t::destruct(handystats_counter_t* self) {
    self->ob_type->tp_free(self);
}


PyDoc_STRVAR(handystats_counter_t_increment__doc__, "");
PyObject*
handystats_counter_t::increment(handystats_counter_t * self, PyObject * args) {

    metrics::counter::value_type value = 1;

    if (!PyArg_ParseTuple(args, "i", &value)) {
        return NULL;
    }

    self->m_counter.increment(value);
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handystats_counter_t_decrement__doc__, "");
PyObject*
handystats_counter_t::decrement(handystats_counter_t * self, PyObject * args) {
    metrics::counter::value_type value = 1;

    if (!PyArg_ParseTuple(args, "i", &value)) {
        return NULL;
    }

    self->m_counter.decrement(value);
    Py_RETURN_NONE;
}


static PyMethodDef handystats_counter_methods[] = {
    {"increment", (PyCFunction)handystats_counter_t::increment, METH_VARARGS, handystats_counter_t_increment__doc__},
    {"decrement", (PyCFunction)handystats_counter_t::decrement, METH_VARARGS, handystats_counter_t_decrement__doc__},
    { NULL, NULL, 0, NULL }
};

static PyMemberDef handystats_counter_members[] = {
    {"value", T_LONG, offsetof(handystats_counter_t, m_counter), 0, "value"},
    {NULL}  /* Sentinel */
};


PyTypeObject handystats_counter_type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0, /* ob_size */
    "Counter", /* tp_name */
    sizeof(handystats_counter_t), /* tp_basicsize */
    0, /* tp_itemsize */
    (destructor)handystats_counter_t::destruct, /* tp_dealloc */
    0, /* tp_print */
    0, /* tp_getattr */
    0, /* tp_setattr */
    0, /* tp_compare */
    0, /* tp_repr */
    0, /* tp_as_number */
    0, /* tp_as_sequence */
    0, /* tp_as_mapping */
    0, /* tp_hash */
    0, /* tp_call */
    0, /* tp_str */
    0, /* tp_getattro */
    0, /* tp_setattro */
    0, /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /* tp_flags */
    "Counter", /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0, /* tp_richcompare */
    0, /* tp_weaklistoffset */
    0, /* tp_iter */
    0, /* tp_iternext */
    handystats_counter_methods, /* tp_methods */
    handystats_counter_members, /* tp_members */
    0, /* tp_getset */
    0, /* tp_base */
    0, /* tp_dict */
    0, /* tp_descr_get */
    0, /* tp_descr_set */
    0, /* tp_dictoffset */
    0,//(initproc)client_object_t::initialize, /* tp_init */
    0, /* tp_alloc */
    handystats_counter_t::construct /* tp_new */
};
