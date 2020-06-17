#!/bin/sh

# Compile
mkdir build
cd build
qmake ..
make
cd ..

# Make Folders
mkdir -p build/customtwitchtranscodeserver_debian/DEBIAN
mkdir -p build/customtwitchtranscodeserver_debian/usr/bin

# Copy files
cp control_$1 build/customtwitchtranscodeserver_debian/DEBIAN/control
cp build/CustomTwitchTranscodeServer build/customtwitchtranscodeserver_debian/usr/bin/customtwitchtranscodeserver

# Make Package
dpkg-deb --build build/customtwitchtranscodeserver_debian
mv build/customtwitchtranscodeserver_debian.deb customtwitchtranscodeserver_debian_$1.deb
