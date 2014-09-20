from setuptools import setup, Extension
from Cython.Build import cythonize

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
    ext_modules=cythonize([Extension("handystats/_handystats",
                                     ["handystats/_handystats.pyx"],
                                     language="c++",
                                     extra_compile_args=["-std=c++0x",
                                                         "-Wall"],
                                     libraries=['handystats'])]),
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
