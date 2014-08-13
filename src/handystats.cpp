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
    using namespace handystats::metrics;

    const char *name;
    /* int64_t  L */
    counter::value_type value = counter::value_type();

    if (!PyArg_ParseTuple(args, "s|L:value", &name, &value)) {
        return NULL;
    }

    HANDY_COUNTER_INIT(name, value);

    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_counter_increment__doc__, "");
static PyObject*
handy_counter_increment(PyObject* self, PyObject* args)
{
    using namespace handystats::metrics;

    const char *name;
    counter::value_type value = 1;

    if (!PyArg_ParseTuple(args, "s|i", &name, &value)) {
        return NULL;
    }

    HANDY_COUNTER_INCREMENT(name, value);
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_counter_decrement__doc__, "");
static PyObject*
handy_counter_decrement(PyObject* self, PyObject* args)
{
    using namespace handystats::metrics;

    const char *name;
    counter::value_type value = 1;

    if (!PyArg_ParseTuple(args, "s|i", &name, &value)) {
        return NULL;
    }

    HANDY_COUNTER_DECREMENT(name, value);
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_counter_change__doc__, "");
static PyObject*
handy_counter_change(PyObject* self, PyObject* args)
{
    using namespace handystats::metrics;

    const char *name;
    counter::value_type value = 0;

    if (!PyArg_ParseTuple(args, "si", &name, &value)) {
        return NULL;
    }

    HANDY_COUNTER_CHANGE(name, value);
    Py_RETURN_NONE;
}



PyDoc_STRVAR(handy_timer_init__doc__, "");
static PyObject*
handy_timer_init(PyObject* self, PyObject* args)
{
    using namespace handystats::metrics;

    const char *name;

    // uint_64t as "K"
    timer::instance_id_type instance_id = timer::DEFAULT_INSTANCE_ID;

    /*
    ToDo: move PyArg_ParseTuple(...)
          to implemnettion function
    */
    if (!PyArg_ParseTuple(args, "s|K", &name, &instance_id)) {
        return NULL;
    }

    HANDY_TIMER_INIT(name, instance_id);
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_timer_start__doc__, "");
static PyObject*
handy_timer_start(PyObject* self, PyObject* args)
{
    using namespace handystats::metrics;

    const char *name;

    // uint_64t as "K"
    timer::instance_id_type instance_id = timer::DEFAULT_INSTANCE_ID;

    /*
    ToDo: move PyArg_ParseTuple(...)
          to implemnettion function
    */
    if (!PyArg_ParseTuple(args, "s|K", &name, &instance_id)) {
        return NULL;
    }

    HANDY_TIMER_START(name, instance_id);
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_timer_stop__doc__, "");
static PyObject*
handy_timer_stop(PyObject* self, PyObject* args)
{
    using namespace handystats::metrics;

    const char *name;

    // uint_64t as "K"
    timer::instance_id_type instance_id = timer::DEFAULT_INSTANCE_ID;

    /*
    ToDo: move PyArg_ParseTuple(...)
          to implemnettion function
    */
    if (!PyArg_ParseTuple(args, "s|K", &name, &instance_id)) {
        return NULL;
    }

    HANDY_TIMER_STOP(name, instance_id);
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_timer_heartbeat__doc__, "");
static PyObject*
handy_timer_heartbeat(PyObject* self, PyObject* args)
{
    using namespace handystats::metrics;

    const char *name;

    // uint_64t as "K"
    timer::instance_id_type instance_id = timer::DEFAULT_INSTANCE_ID;

    /*
    ToDo: move PyArg_ParseTuple(...)
          to implemnettion function
    */
    if (!PyArg_ParseTuple(args, "s|K", &name, &instance_id)) {
        return NULL;
    }

    HANDY_TIMER_HEARTBEAT(name, instance_id);
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_timer_discard__doc__, "");
static PyObject*
handy_timer_discard(PyObject* self, PyObject* args)
{
    using namespace handystats::metrics;

    const char *name;

    // uint_64t as "K"
    timer::instance_id_type instance_id = timer::DEFAULT_INSTANCE_ID;

    /*
    ToDo: move PyArg_ParseTuple(...)
          to implemnettion function
    */
    if (!PyArg_ParseTuple(args, "s|K", &name, &instance_id)) {
        return NULL;
    }

    HANDY_TIMER_DISCARD(name, instance_id);
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_gauge_init__doc__, "");
static PyObject*
handy_gauge_init(PyObject* self, PyObject* args)
{
    using namespace handystats::metrics;

    const char *name;

    // double as "d"
    gauge::value_type instance_id;
     /*
        ToDo: move PyArg_ParseTuple(...)
          to implementation function, add time parser
    */
    if (!PyArg_ParseTuple(args, "sd", &name, &instance_id)) {
        return NULL;
    }

    HANDY_GAUGE_INIT(name, instance_id);
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_gauge_set__doc__, "");
static PyObject*
handy_gauge_set(PyObject* self, PyObject* args)
{
    using namespace handystats::metrics;

    const char *name;

    // double as "d"
    gauge::value_type instance_id;
     /*
        ToDo: move PyArg_ParseTuple(...)
          to implementation function, add time parser
    */
    if (!PyArg_ParseTuple(args, "sd", &name, &instance_id)) {
        return NULL;
    }

    HANDY_GAUGE_SET(name, instance_id);
    Py_RETURN_NONE;
}


PyDoc_STRVAR(handy_json_dump__doc__, "Return statistic as formated json");
static PyObject*
handy_json_dump(PyObject* self, PyObject* args)
{
    PyObject* value = Py_BuildValue("s", HANDY_JSON_DUMP()->c_str());
    return value;
}

/*
    ToDo: No GIL
*/
static PyMethodDef handystats_methods[] =
{
    {"handy_init", handy_init, METH_NOARGS, handy_init__doc__},
    {"handy_finalize", handy_finalize, METH_NOARGS, handy_finalize__doc__},

    /* counter */
    {"handy_counter_init", handy_counter_init, METH_VARARGS, handy_counter_init__doc__},
    {"handy_counter_increment", handy_counter_increment, METH_VARARGS, handy_counter_increment__doc__},
    {"handy_counter_decrement", handy_counter_decrement, METH_VARARGS, handy_counter_decrement__doc__},
    {"handy_counter_change", handy_counter_change, METH_VARARGS, handy_counter_change__doc__},

    /* timer */
    {"handy_timer_init", handy_timer_init, METH_VARARGS, handy_timer_init__doc__},
    {"handy_timer_start", handy_timer_start, METH_VARARGS, handy_timer_start__doc__},
    {"handy_timer_stop", handy_timer_stop, METH_VARARGS, handy_timer_stop__doc__},
    {"handy_timer_heartbeat", handy_timer_heartbeat, METH_VARARGS, handy_timer_heartbeat__doc__},
    {"handy_timer_discard", handy_timer_discard, METH_VARARGS, handy_timer_discard__doc__},

    /* gauge */
    {"handy_gauge_init", handy_gauge_init, METH_VARARGS, handy_gauge_init__doc__},
    {"handy_gauge_set", handy_gauge_set, METH_VARARGS, handy_gauge_set__doc__},

    /* dump */
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
