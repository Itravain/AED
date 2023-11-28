import sys
import time 

sys.setrecursionlimit(10**6)
a = 3
b = 12

def fatorial(numero):
  if (numero == 1): return 1

  return numero*fatorial(numero-1)

start = time.perf_counter()
print(fatorial(1000))
print(time.perf_counter() - start)