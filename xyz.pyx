# distutils: language=c++
cimport cython
cimport numpy
from libcpp cimport bool
from libcpp.vector cimport vector
from libcpp.string cimport string

import re
import numpy

cdef extern from "coffset.h":
    
    vector[long long] _get_offsets(string filename)


# use _get_offset and get a numpy array

cdef numpy.ndarray[long long, ndim=1, mode="c"] get_offsets(string filename):

    cdef vector[long long] offsets = _get_offsets(filename)
    #print(offsets) # debug
    # numpy array should be a int64 array
    offsets_np = numpy.asarray(offsets)
    #cdef numpy.ndarray[long long, ndim=1, mode="c"] offsets_np = numpy.ndarray(offsets, dtype=numpy.int64)
    
    return offsets_np


cdef class coffsets(object):

    @staticmethod
    def get_offsets(filename):

        # TODO: when file not found, core will be dumped, need to handle this

        # print(filename)
        # print(type(filename))
        return get_offsets(<string> filename.encode('utf-8'))

    @staticmethod
    def hello(a):

        return get_offsets("/home/tempest/datasets/traj/pyiron-pos-1.xyz")