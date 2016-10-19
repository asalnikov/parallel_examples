#
# Makefile
#
# @author "Alexey Salnikov" <salnikov@cs.msu.su>
#

CC= mpicc
CFLAGS=
SOURCE= hello.c
OPTIMIZE= -O3
OPENMP_FLAGS= -fopenmp
LIBS= -lm

BINARIES= hello_mpi_only hello_mpi_openmp

all: $(BINARIES)


hello_mpi_only: $(SOURCE)
	$(CC) $(CFLAGS) $(OPTIMIZE) -o $@ $^ $(LIBS)

hello_mpi_openmp: $(SOURCE)
	 $(CC) $(CFLAGS) $(OPENMP_FLAGS) $(OPTIMIZE) -o $@ $^ $(LIBS)

clean:
	rm -f $(BINARIES)




