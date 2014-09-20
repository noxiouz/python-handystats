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

cpdef configuration_json():
    _handystats.HANDY_FINALIZE()

cpdef bytes json_dump():
    return _handystats.HANDY_JSON_DUMP().get().c_str()


cpdef counter_init(string name, int value):
    _handystats.HANDY_COUNTER_INIT(name, value)

cpdef counter_increment(string name, int value):
    _handystats.HANDY_COUNTER_INCREMENT(name, value)
