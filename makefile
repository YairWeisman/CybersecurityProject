# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
CC = g++
CFLAGS  = -g -Wall
LFLAGS  = -L/usr/lib

# All Targets
all: cyber

# Tool invocations
# Executable "hello" depends on the files hello.o and run.o.
cyber: bin/cyberpc.o bin/cyberexpert.o bin/cyberdns.o bin/cyberworm.o bin/Run.o
	@echo 'Building target: cyber'
	@echo 'Invoking: C++ Linker'
	$(CC) -o bin/cyber bin/cyberpc.o bin/cyberexpert.o bin/cyberdns.o bin/cyberworm.o bin/Run.o $(LFLAGS)
	@echo 'Finished building target: cyber'
	@echo ' '

# Depends on the source and header files
bin/cyberpc.o: src/CyberPC.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/cyberpc.o src/CyberPC.cpp

	# Depends on the source and header files
bin/cyberworm.o: src/CyberWorm.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/cyberworm.o src/CyberWorm.cpp

	# Depends on the source and header files
bin/cyberexpert.o: src/CyberExpert.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/cyberexpert.o src/CyberExpert.cpp
	
		# Depends on the source and header files
bin/cyberdns.o: src/CyberDNS.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/cyberdns.o src/CyberDNS.cpp
	
# Depends on the source and header files 
bin/Run.o: src/Run.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/Run.o src/Run.cpp

#Clean the build directory
clean: 
	rm -f bin/*
