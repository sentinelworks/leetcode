#!/usr/bin/python3

import click
import subprocess

file_head ='''
#include <bits/stdc++.h>
using namespace std;

'''

file_tail = '''
int main()
{
    Solution sol;

    return 0;
}
'''

@click.command()
@click.argument('source')
@click.option('--name', default="leetcode_test.cc", 
              help='The file name of the generated source code.')
def compile(source, name):
    """compile the code in SOURCE file."""
    print(f"The generated CPP file name {name}, take from original source code in {source}.")
    with open(name, "w") as file:
        file.write(file_head);
        with open(source, "r") as code:
            lines = code.readlines()
            file.writelines(lines);

        file.write(file_tail);

    subprocess.run(["g++", name]) 


if __name__ == '__main__':
    compile()

