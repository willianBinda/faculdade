from numba import jit, cuda
import numpy as np

from timeit import default_timer as timer   

def RodarNaCPU(a):                                
    for i in range(10000000):
        a[i]+= 1      

@jit(target_backend='cuda')                         
def RodarNaGPU(a):
    for i in range(10000000):
        a[i]+= 1
if _name=="main_":
    n = 10000000                            
    a = np.ones(n, dtype = np.float64)
      
    inicio = timer()
    RodarNaCPU(a)
    print("Sem Placa de video:", timer()-inicio)    
      
    inicio = timer()
    RodarNaGPU(a)
    print("Com Placa de video:", timer()-inicio)