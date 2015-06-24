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
    _handystats.HANDY_CONFIG_JSON(config)

cpdef bytes json_dump():
    return _handystats.HANDY_JSON_DUMP()


# Counter
cpdef counter_init(bytes name, int64_t value):
    _handystats.HANDY_COUNTER_INIT(move(name), value)

cpdef counter_increment(bytes name, int64_t value):
    _handystats.HANDY_COUNTER_INCREMENT(move(name), value)

cpdef counter_decrement(bytes name, int64_t value):
    _handystats.HANDY_COUNTER_DECREMENT(move(name), value)

cpdef counter_change(bytes name, int64_t value):
    _handystats.HANDY_COUNTER_CHANGE(move(name), value)


cpdef timer_init(bytes name, int64_t instance_id):
    _handystats.HANDY_TIMER_INIT(move(name), instance_id)

cpdef timer_start(bytes name, int64_t instance_id):
    _handystats.HANDY_TIMER_START(move(name), instance_id)

cpdef timer_stop(bytes name, int64_t instance_id):
    _handystats.HANDY_TIMER_STOP(move(name), instance_id)


cdef class Counter:
    cdef _handystats.counter *thisptr
    def __cinit__(self):
        self.thisptr = new _handystats.counter()

    def __dealloc__(self):
        del self.thisptr

    def increment(self, int64_t value):
        self.thisptr.increment(value)

    def decrement(self, int64_t value):
        self.thisptr.decrement(value)
