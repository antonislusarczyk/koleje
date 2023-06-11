#!/bin/env python

import subprocess

for i in range(100):

    nazwa_pliku = "test_nr_{nr:03}".format(nr=i+1)
    nazwa_pliku_in = "tests/{nazwa}.in".format(nazwa=nazwa_pliku)
    nazwa_pliku_out = "tests/{nazwa}.out".format(nazwa=nazwa_pliku)

    with open(nazwa_pliku_in) as pin, open(nazwa_pliku_out) as pout:
        programik = subprocess.Popen(["cmake-build-debug/koleje"], stdout=subprocess.PIPE, stdin=pin)
        out, _ = programik.communicate()
        out = out.decode("utf-8").replace('\n', '')
        with open(nazwa_pliku_out) as pout:
            wyjscie_brutalnego = pout.read().replace('\n', '')

            if wyjscie_brutalnego != out:
                print("nie dziala test nr {n}".format(n=i+1))
                print("otrzymano:")
                print(out)
                print("oczekiwano:")
                print(wyjscie_brutalnego)
                exit(1)

                # print("specyficzny przypadek co nie dziala")

