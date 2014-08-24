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

#include "counter.hpp"

#include <handystats/operation.hpp>
#include <handystats/configuration.hpp>
#include <handystats/json_dump.hpp>
#include <handystats/metrics_dump.hpp>
#include <handystats/measuring_points.hpp>

PyDoc_STRVAR(init__doc__, "");
static PyObject*
init(PyObject* self, PyObject* args)
{
    HANDY_INIT();
    Py_RETURN_NONE;
}

PyDoc_STRVAR(finalize__doc__, "");
static PyObject*
finalize(PyObject* self, PyObject* args)
{
    HANDY_FINALIZE();
    Py_RETURN_NONE;
}


PyDoc_STRVAR(counter_init__doc__, "");
static PyObject*
counter_init(PyObject* self, PyObject* args)
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


PyDoc_STRVAR(counter_increment__doc__, "");
static PyObject*
counter_increment(PyObject* self, PyObject* args)
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


PyDoc_STRVAR(counter_decrement__doc__, "");
static PyObject*
counter_decrement(PyObject* self, PyObject* args)
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


PyDoc_STRVAR(counter_change__doc__, "");
static PyObject*
counter_change(PyObject* self, PyObject* args)
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



PyDoc_STRVAR(timer_init__doc__, "");
static PyObject*
timer_init(PyObject* self, PyObject* args)
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


PyDoc_STRVAR(timer_start__doc__, "");
static PyObject*
timer_start(PyObject* self, PyObject* args)
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


PyDoc_STRVAR(timer_stop__doc__, "");
static PyObject*
timer_stop(PyObject* self, PyObject* args)
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


PyDoc_STRVAR(timer_heartbeat__doc__, "");
static PyObject*
timer_heartbeat(PyObject* self, PyObject* args)
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


PyDoc_STRVAR(timer_discard__doc__, "");
static PyObject*
timer_discard(PyObject* self, PyObject* args)
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


PyDoc_STRVAR(gauge_init__doc__, "");
static PyObject*
gauge_init(PyObject* self, PyObject* args)
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


PyDoc_STRVAR(gauge_set__doc__, "");
static PyObject*
gauge_set(PyObject* self, PyObject* args)
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


PyDoc_STRVAR(configuration_file__doc__, "");
static PyObject*
configuration_file(PyObject* self, PyObject* args)
{
    const char *filename;

    if (!PyArg_ParseTuple(args, "s", &filename)) {
        return NULL;
    }

    HANDY_CONFIGURATION_FILE(filename);

    Py_RETURN_NONE;
}


PyDoc_STRVAR(configuration_json__doc__, "");
static PyObject*
configuration_json(PyObject* self, PyObject* args)
{
    const char *json_config;

    if (!PyArg_ParseTuple(args, "s", &json_config)) {
        return NULL;
    }

    HANDY_CONFIGURATION_JSON(json_config);

    Py_RETURN_NONE;
}


PyDoc_STRVAR(json_dump__doc__, "Return statistic as formated json");
static PyObject*
json_dump(PyObject* self, PyObject* args)
{
    PyObject* value = Py_BuildValue("s", HANDY_JSON_DUMP()->c_str());
    return value;
}

static PyMethodDef handystats_methods[] =
{
    {"init", init, METH_NOARGS, init__doc__},
    {"finalize", finalize, METH_NOARGS, finalize__doc__},

    /* configuration */
    {"configuration_file", configuration_file, METH_VARARGS, configuration_file__doc__},
    {"configuration_json", configuration_json, METH_VARARGS, configuration_json__doc__},

    /* counter */
    {"counter_init", counter_init, METH_VARARGS, counter_init__doc__},
    {"counter_increment", counter_increment, METH_VARARGS, counter_increment__doc__},
    {"counter_decrement", counter_decrement, METH_VARARGS, counter_decrement__doc__},
    {"counter_change", counter_change, METH_VARARGS, counter_change__doc__},

    /* timer */
    {"timer_init", timer_init, METH_VARARGS, timer_init__doc__},
    {"timer_start", timer_start, METH_VARARGS, timer_start__doc__},
    {"timer_stop", timer_stop, METH_VARARGS, timer_stop__doc__},
    {"timer_heartbeat", timer_heartbeat, METH_VARARGS, timer_heartbeat__doc__},
    {"timer_discard", timer_discard, METH_VARARGS, timer_discard__doc__},

    /* gauge */
    {"gauge_init", gauge_init, METH_VARARGS, gauge_init__doc__},
    {"gauge_set", gauge_set, METH_VARARGS, gauge_set__doc__},

    /* dump */
    {"json_dump", json_dump, METH_NOARGS, json_dump__doc__},
    {NULL, NULL, 0, NULL}
};


#ifndef PyMODINIT_FUNC
#define PyMODINIT_FUNC void
#endif

extern "C" {
    PyMODINIT_FUNC
    init_handystats(void)
    {
        PyObject* module = Py_InitModule3("_handystats", handystats_methods, NULL);

        if(PyType_Ready(&handystats_counter_type) < 0) {
            return;
        }
        Py_INCREF(&handystats_counter_type);

        PyModule_AddObject(
            module,
            "Counter",
            reinterpret_cast<PyObject*>(&handystats_counter_type)
        );
    }
}
