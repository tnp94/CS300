# make all - builds the application, build and runs the tests, and builds the documents
# make docs - builds the documents (design, requirements, testplan)
# make chocan - build the application
# make test - builds and runs the tests

## Document variables ##
DOC_OUT=./documents/
REQUIREMENTS=./documents/src/requirements.tex 
DESIGN=./documents/src/design.tex
TESTPLAN=./documents/src/testplan.tex
LATEXC=tectonic
LATEXFLAGS=--keep-logs --synctex --outdir

## CPP variables ##
CC=g++
CFLAGS=-g -Wall -fmax-errors=5
IDIR=./include/
OUTDIR=./out/
ODIR=$(OUTDIR)objects/
SRCDIR=./src/
TESTDIR=./test/
TESTSRC=$(TESTDIR)src/
TESTIDIR=$(TESTDIR)include/
MODS= InteractiveModule ManagerModule Member Person Provider ProviderModule Service ProviderDirectory Database

## Rule to build documents ##
.PHONY: docs

docs:
	$(LATEXC) $(LATEXFLAGS) $(DOC_OUT) $(REQUIREMENTS)
	$(LATEXC) $(LATEXFLAGS) $(DOC_OUT) $(DESIGN)
	$(LATEXC) $(LATEXFLAGS) $(DOC_OUT) $(TESTPLAN)

## Rules to build application ##
DEPS = $(patsubst %,$(IDIR)%.h,$(MODS))

OBJ = $(patsubst %,$(ODIR)%.o,$(MODS))

$(ODIR)%.o: $(SRCDIR)%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OUTDIR)chocan: $(OBJ) $(ODIR)main.o
	$(CC) -o $@ $^ $(CFLAGS)

chocan:
	make $(OUTDIR)chocan

## Rule to build and run tests ##
TESTDEPS = $(TESTIDIR)test.h $(DEPS)

TESTOBJ = $(OBJ) $(patsubst %,$(TESTDIR)%.o,$(MODS)) $(TESTDIR)main.o

$(TESTDIR)%.o: $(TESTSRC)%.cpp $(TESTDEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TESTDIR)test: $(OBJ) $(TESTOBJ)
	$(CC) -o $@ $^ $(CFLAGS)

test: $(TESTDIR)test
	$(TESTDIR)test
	make cleantest

## Rules to clean objects and binary ##
.PHONY: clean

clean:
	rm -f $(ODIR)*.o $(OUTDIR)chocan 
	make cleantest

.PHONY: cleantest

cleantest:
	rm -f $(TESTDIR)*.o $(TESTDIR)test
