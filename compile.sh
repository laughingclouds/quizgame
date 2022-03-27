echo -n "Recursively finding files...  ";

FILES=$(python3 grabber.py)

echo "Done.";
echo "Compiling...\n\n";

ARGS="-std=c++17 -Wall -Wextra"
mkdir -p builddir &&
g++ $ARGS $FILES -lsqlite3 -o builddir/main;