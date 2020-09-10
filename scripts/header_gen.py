#!/usr/bin/env python

"""
Copyright (c) 2018 Doyub Kim
I am making my contributions/submissions to this project solely in my personal
capacity and am not conveying any rights to any intellectual property of any
third parties.
"""

import filecmp
import inspect
import shutil
import os
import fnmatch

dirname = os.path.dirname(os.path.abspath(
    inspect.getfile(inspect.currentframe())))


def navigate_all_files(root_path, patterns):
    for root, dirs, files in os.walk(root_path):
        for pattern in patterns:
            for filename in fnmatch.filter(files, pattern):
                yield os.path.join(root, filename)

def get_all_files(root_path, patterns):
    ret = []
    for filepath in navigate_all_files(root_path, patterns):
        ret.append(filepath)
    return ret


def main():
    include_dir = os.path.join(dirname, "../include/engine")
    filenames = get_all_files(include_dir, ["*.h"])
    filenames.sort()
    header = os.path.join(dirname, "../include/PhyszyEngine.h")
    header_tmp = header + ".tmp"
    with open(header_tmp, "w") as header_file:
        header_file.write("#ifndef INCLUDE_PHYSZYENGINE_H_\n")
        header_file.write("#define INCLUDE_PHYSZYENGINE_H_\n")
        for filename in filenames:
            if not filename.endswith("-inl.h"):
                line = "#include <engine/%s>\n" % filename[len(include_dir)+1:]
                header_file.write(line)
        header_file.write("#endif  // INCLUDE_PHYSZYENGINE_H_\n")
    if not filecmp.cmp(header, header_tmp):
        shutil.move(header_tmp, header)
    else:
        os.remove(header_tmp)


if __name__ == "__main__":
    main()