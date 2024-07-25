import setuptools
from setuptools import setup
from setuptools.extension import Extension
from Cython.Build import cythonize
import numpy


setup(
    name="coffsets",
    version="0.0.1",
    author="ke xiong",
    author_email="635261081@qq.com",
    description="cython offset reader for mda",
    long_description_content_type="text/markdown",
    packages=setuptools.find_packages(),
    # directives={'linetrace': False, 'language_level': 3},

    ext_modules = cythonize([Extension("xyz", ["xyz.pyx"], 
            include_dirs=[numpy.get_include(), "./include"],
            language="c++",
            extra_compile_args=['-std=c++11',],
            # define_macros=[('NPY_NO_DEPRECATED_API', 'NPY_1_7_API_VERSION')],
            )]),

    classifiers=[
        "Programming Language :: Python :: 3",
    ],  
    python_requires='>=3.6',
    install_requires=[
        "numpy",
        "cython"
  ]
)