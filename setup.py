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

from setuptools import setup, Extension

__author__ = 'Anton Tiurin'
__copyright__ = 'Copyright 2014'
__credits__ = []
__license__ = 'LGPLv3+'
__version__ = '0.1.1'
__maintainer__ = 'Anton Tiurin'
__email__ = 'noxiouz@yandex.ru'
__status__ = 'Production'
__title__ = 'handystats'
__url__ = 'https://github.com/noxiouz/python-handystats'
__description__ = 'Python binding for handystats library'
d = 'https://github.com/noxiouz/python-handystats/archive/master.zip'

setup(
    name=__title__,
    version=__version__,
    author=__author__,
    author_email=__email__,
    maintainer=__maintainer__,
    maintainer_email=__email__,
    url=__url__,
    download_url=d,
    description=__description__,
    long_description=open('./README.md').read(),
    packages=['handystats'],
    ext_modules=[Extension("handystats/_handystats",
                 ["src/handystats.cpp",
                  "src/counter.cpp"],
                 include_dirs=["include"],
                 extra_compile_args=["-std=c++0x", "-Wall"],
                 libraries=['handystats'])],
    classifiers=['Development Status :: 4 - Beta',
                 'Intended Audience :: Developers',
                 'Programming Language :: Python',
                 'Programming Language :: Python :: 2.6',
                 'Programming Language :: Python :: 2.7',
                 # 'Programming Language :: Python :: 3.2',
                 # 'Programming Language :: Python :: 3.3',
                 # 'Programming Language :: Python :: 3.4',
                 'Programming Language :: Python :: Implementation :: CPython',
                 'Operating System :: OS Independent',
                 'Topic :: Utilities',
                 'License :: OSI Approved :: GNU Lesser General Public License v3 or later (LGPLv3+)'],
    platforms=['Independent'],
    license=open('./LICENSE').read(),
    zip_safe=False,
    tests_require=open('./tests/requirements.txt').read(),
    test_suite='nose.collector'
)
