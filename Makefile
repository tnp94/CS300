# make all - builds the application, build and runs the tests, and builds the documents
# make docs - builds the documents (design, requirements, testplan)
# make chocan - build the application

## CPP variables ##
CFLAGS=-g -Wall
CC=g++
IDIR=./include/
OUTDIR=./out/
ODIR=$(OUTDIR)objects/
SRCDIR=./src/
MODS= InteractiveModule ManagerModule Member Person Provider ProviderModule Service ProviderDirectory Database

## Document variables ##
DOC_OUT=./documents/
REQUIREMENTS=./documents/src/requirements.tex 
DESIGN=./documents/src/design.tex
TESTPLAN=./documents/src/testplan.tex
LATEXC=tectonic
LATEXFLAGS=--keep-logs --synctex --outdir

## Rule to build documents ##
.PHONY: docs

docs:
	$(LATEXC) $(LATEXFLAGS) $(DOC_OUT) $(REQUIREMENTS)
	$(LATEXC) $(LATEXFLAGS) $(DOC_OUT) $(DESIGN)
	$(LATEXC) $(LATEXFLAGS) $(DOC_OUT) $(TESTPLAN)

## Rules to build application ##
DEPS = $(patsubst %,$(IDIR)%.h,$(MODS)) $(IDIR)test.h

OBJ = $(patsubst %,$(ODIR)%.o,$(MODS))

$(ODIR)%.o: $(SRCDIR)%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OUTDIR)chocan: $(OBJ) $(ODIR)main.o
	$(CC) -o $@ $^ $(CFLAGS)

chocan: clean
	make $(OUTDIR)chocan

## Rules to clean objects and binary ##
.PHONY: clean

clean:
	rm -f $(ODIR)*.o $(OUTDIR)chocan 
