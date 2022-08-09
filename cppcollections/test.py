from cppcollections import bxjj
import random
a=bxjj(200)
for i in range(200):
    x,y=random.randint(0,199),random.randint(0,199)
    a.hb(x,y)
print(a.result())