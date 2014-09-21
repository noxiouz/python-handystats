#
# Copyright (c) 2014 Tyurin Anton noxiouz@yandex.ru
#
# This file is part of Handystats for Python.
#
# Handystats for Python is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# Handystats for Python is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

cimport _handystats

cpdef init():
    _handystats.HANDY_INIT()

cpdef finalize():
    _handystats.HANDY_FINALIZE()

cpdef configuration_json(bytes config):
    _handystats.HANDY_CONFIGURATION_JSON(config)

cpdef bytes json_dump():
    return _handystats.HANDY_JSON_DUMP().get().c_str()


# Counter
cpdef counter_init(bytes name, int value):
    _handystats.HANDY_COUNTER_INIT(name, value)

cpdef counter_increment(bytes name, int value):
    _handystats.HANDY_COUNTER_INCREMENT(name, value)

cpdef counter_decrement(bytes name, int value):
    _handystats.HANDY_COUNTER_DECREMENT(name, value)

cpdef counter_change(bytes name, int value):
    _handystats.HANDY_COUNTER_CHANGE(name, value)


cpdef timer_init(bytes name, int instance_id):
    _handystats.HANDY_TIMER_INIT(name, instance_id)

cpdef timer_start(bytes name, int instance_id):
    _handystats.HANDY_TIMER_START(name, instance_id)

cpdef timer_stop(bytes name, int instance_id):
    _handystats.HANDY_TIMER_STOP(name, instance_id)


cdef class Counter:
    cdef _handystats.counter *thisptr
    def __cinit__(self, int value=0):
        self.thisptr = new _handystats.counter(value)

    def __dealloc__(self):
        del self.thisptr

    def increment(self, int value):
        self.thisptr.increment(value)

    def decrement(self, int value):
        self.thisptr.decrement(value)

    property value:
        def __get__(self):
            return self.thisptr.value
