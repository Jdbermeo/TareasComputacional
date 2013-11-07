# -*- coding: utf-8 -*-
# <nbformat>3.0</nbformat>

# <codecell>
# <codecell>

#!/usr/bin/python
# -*- coding: latin-1 -*-
import math
import matplotlib.pyplot as plt
import numpy as np

T = np.loadtxt("g.dat")

plt.scatter(T[:,1],T[:,2])
plt.show()


