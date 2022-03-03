"""
Convenience script for recursively walking the source directory 
and printing the paths of all the ``.cpp`` files.
To be used by **meson.build** file.
"""
from os import walk as osWalk
from os.path import join as joinPath

def main():
    SRC_DIR = './quiz-game'
    for root, _, files in osWalk(SRC_DIR):
        for fileName in files:
            if fileName.endswith(".cpp"):
                # end=" " is important! Because meson.build
                # reads a space separated list of file names
                print(joinPath(root, fileName), end=" ")

if __name__ == "__main__":
    main()