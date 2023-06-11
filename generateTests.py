#!/bin/env python

import random
import os
import subprocess

random.seed(123)

ilosc_testow = 100
ilosc_zapytan_w_tescie = 20

if not os.path.exists("tests"):
    os.mkdir("tests")

for i in range(ilosc_testow):
    n = random.randint(2, 4)  # maksymala ilosc stackji to 10
    m = random.randint(1, 3)  # maksymalna ilosc miejsc w wagonie to 7

    nazwa_pliku = "test_nr_{nr:03}".format(nr=i+1)
    nazwa_pliku_in = "tests/{nazwa}.in".format(nazwa=nazwa_pliku)
    nazwa_pliku_out = "tests/{nazwa}.out".format(nazwa=nazwa_pliku)

    with open(nazwa_pliku_in, "w+") as f:
        f.write("{n} {m} {i}\n".format(n=n, m=m, i=ilosc_zapytan_w_tescie))
        for _ in range(ilosc_zapytan_w_tescie):
            p = random.randint(1, n-1)
            k = random.randint(p+1, n)
            l = random.randint(1, m)
            f.write("{p} {k} {l}\n".format(p=p, k=k, l=l))

    with open(nazwa_pliku_in) as pin, open(nazwa_pliku_out, "w+") as pout:
        subprocess.run(["cmake-build-debug/brutalny"], stdout=pout, stdin=pin)
