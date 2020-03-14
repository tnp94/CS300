#!/bin/bash

echo "Compiling for testing..."
g++ -c -o out/objects/InteractiveModule.o src/InteractiveModule.cpp -g -Wall -fmax-errors=5 -DTEST
g++ -c -o out/objects/ManagerModule.o src/ManagerModule.cpp -g -Wall -fmax-errors=5 -DTEST
g++ -c -o out/objects/Member.o src/Member.cpp -g -Wall -fmax-errors=5 -DTEST
g++ -c -o out/objects/Person.o src/Person.cpp -g -Wall -fmax-errors=5 -DTEST
g++ -c -o out/objects/Provider.o src/Provider.cpp -g -Wall -fmax-errors=5 -DTEST
g++ -c -o out/objects/ProviderModule.o src/ProviderModule.cpp -g -Wall -fmax-errors=5 -DTEST
g++ -c -o out/objects/Service.o src/Service.cpp -g -Wall -fmax-errors=5 -DTEST
g++ -c -o out/objects/ProviderDirectory.o src/ProviderDirectory.cpp -g -Wall -fmax-errors=5 -DTEST
g++ -c -o out/objects/Database.o src/Database.cpp -g -Wall -fmax-errors=5 -DTEST
g++ -c -o out/objects/main.o src/main.cpp -g -Wall -fmax-errors=5 -DTEST
g++ -o out/chocan out/objects/InteractiveModule.o out/objects/ManagerModule.o out/objects/Member.o out/objects/Person.o out/objects/Provider.o out/objects/ProviderModule.o out/objects/Service.o out/objects/ProviderDirectory.o out/objects/Database.o out/objects/main.o -g -Wall -fmax-errors=5 -DTEST

echo "Compiling complete. Running tests..."

OUTPUT=$(./out/chocan)
echo "$OUTPUT"
