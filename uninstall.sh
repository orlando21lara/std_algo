# /bin/bash

# Changing directory is unnecessary if the script is run in its current directory, but just in case
project_directory=$(dirname $0)
cd ${project_directory}
cd build/
make uninstall	    # Delete all the files that were installed
echo "The directories will remain but the contents were deleted"



