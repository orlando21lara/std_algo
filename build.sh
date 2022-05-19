# /bin/bash

# Changing directory is unnecessary if the script is run in its current directory, but just in case
project_directory=$(dirname $0)
cd ${project_directory}
mkdir build
cd build
cmake ../	    # Configure the project
cmake --build ./    # Build the project



