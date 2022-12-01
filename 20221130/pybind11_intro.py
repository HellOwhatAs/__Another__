import test_pybind11

print(test_pybind11.__doc__)

print(test_pybind11.add(10,12))
print(test_pybind11.add(10,12,13))
print(test_pybind11.add(1,1,1,1))
print(test_pybind11.add(1,1,1,1,1))

print(test_pybind11.sum([1,2,3]))

a=[]
test_pybind11.push_back_one(a)
print(a)

try:
    test_pybind11.throw_except()
except Exception as e:
    print(repr(e))

try:
    test_pybind11.throw_value_error()
except Exception as e:
    print(repr(e))

a=[]
test_pybind11.append0(a)
print(a)

import numpy as np
a=np.ones(10,dtype=np.int32)
test_pybind11.addr_mult2(a.__array_interface__["data"][0],a.shape[0])
print(a)

test_pybind11.eigen_mult2(a)
print(a)

test_pybind11.eigen_mult2_rowmajor(a)
print(a)

test_pybind11.multi_thread("no gil")