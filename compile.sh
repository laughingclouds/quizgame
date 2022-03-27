echo -n "Recursively finding files...  ";

FILES=$(python3 grabber.py)

echo "Done.";
echo "Compiling...\n\n";

mkdir -p builddir &&
g++ $FILES -o builddir/main;