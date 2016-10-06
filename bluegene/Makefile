#
# Makefile
#
# @author "Alexey Salnikov" <salnikov@cs.msu.su>
#

CC= mpixlc_r
CFLAGS= -I/bgsys/drivers/ppcfloor/arch/include
SOURCE= hello_bgp.c
OPTIMIZE= -O3
OPENMP_FLAGS= -qsmp=omp

BINARIES= hello_mpi_only hello_mpi_openmp

all: $(BINARIES)


hello_mpi_only: $(SOURCE)
	$(CC) $(CFLAGS) $(OPTIMIZE) -o $@ $^

hello_mpi_openmp: $(SOURCE)
	 $(CC) $(CFLAGS) $(OPENMP_FLAGS) $(OPTIMIZE) -o $@ $^

clean:
	rm -f $(BINARIES)




