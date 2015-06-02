#!/bin/bash

rm -rf target src/resources/lib/darwin/*
rm -f src/main/include/Sqlite_Native.h
mkdir -p target/classes
javac -d target/classes src/main/java/rete/sql/Sqlite3.java
javah -d src/main/include -cp target/classes rete.sql.Sqlite3.Native
clang -lsqlite3 -I/Library/Java/JavaVirtualMachines/jdk1.8.0_05.jdk/Contents/Home/include -I/Library/Java/JavaVirtualMachines/jdk1.8.0_05.jdk/Contents/Home/include/darwin -dynamiclib -fPIC src/main/c/sqlite3wrapper.c -o src/main/resources/lib/darwin/libsqlite3wrapper.dylib
jar cf target/jnisqlite3-0.0.1.jar -C target/classes .
rm -r target/classes
cp src/main/resources/lib/darwin/* .
javac -cp target/*:. Sqlite3Tests.java
rm test.db
java -cp target/*:. Sqlite3Tests