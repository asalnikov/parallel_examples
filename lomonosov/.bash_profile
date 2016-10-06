# .bash_profile

# Get the aliases and functions
if [ -f ~/.bashrc ]; then
	. ~/.bashrc
fi

# User specific environment and startup programs

PATH=$PATH:$HOME/bin

module load openmpi/1.8.4-icc
module load intel/15.0.090
module load slurm/2.5.6



export PATH
