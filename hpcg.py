import os

rank = int(os.environ["OMPI_COMM_WORLD_RANK"])

if rank == 0:
	os.system("gdb bin/test")
else:
	os.system("./bin/test")
