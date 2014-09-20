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

from libcpp.string cimport string


cdef extern from "<memory>" namespace "std":
    cppclass shared_ptr[T]:
        T* get()

cdef extern from "handystats/operation.hpp":
    void HANDY_INIT()
    void HANDY_FINALIZE()


cdef extern from "handystats/configuration.hpp":
    void HANDY_CONFIGURATION_JSON(const char *)


cdef extern from "handystats/json_dump.hpp":
    shared_ptr[string] HANDY_JSON_DUMP()


cdef extern from "handystats/measuring_points.hpp":
    void HANDY_COUNTER_INIT(string, int)
    void HANDY_COUNTER_INCREMENT(string, int)
