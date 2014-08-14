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

#ifndef _PYTHON_HANDYSTATS_OBJECTS
#include <Python.h>

#include <handystats/metrics/counter.hpp>

extern PyTypeObject handystats_counter_type;

using namespace handystats;

struct handystats_counter_t {
    public:
        PyObject_HEAD

        static PyObject* construct(PyTypeObject* type, PyObject * args, PyObject * kwargs);
        static void destruct(handystats_counter_t* type);

        static PyObject* increment(handystats_counter_t* self, PyObject * args);
        static PyObject* decrement(handystats_counter_t* self, PyObject * args);

    	metrics::counter m_counter;
};


#define _PYTHON_HANDYSTATS_OBJECTS
#endif


