from MDAnalysis import Universe
import time 

t0 = time.time()
uni = Universe("/home/tempest/datasets/traj/pyiron-pos-1.xyz")
print(uni.trajectory)
t1 = time.time()

print("Time taken: ", t1-t0)

def aaa():
    t0 = time.time()
    uni = Universe("/home/tempest/datasets/traj/pyiron-pos-1.xyz")
    print(uni.trajectory)
    t1 = time.time()
