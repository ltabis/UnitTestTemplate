#!/usr/bin/env python3

import os
import sys
import subprocess
import confReader

# Stack class
class Stack:
    # init the class
    def __init__(self, *args):
        self.stack = []
        [self.stack.append(arg.split(" ")) for arg in args]

    # get size of the stack
    def size(self):
        return len(self.stack)

    # check if empty
    def empty(self):
        return len(self.stack) == 0

    # Pop the first element
    def pop(self):
        if len(self.stack) != 0:
            self.stack.pop()

    # Push an element
    def push(self, value):
        self.stack.append(value.split(" "))

    def top(self):
        return self.stack[-1] if len(self.stack) != 0 else None

def wait(process):

    # Wait for process to end
    while True:
        return_code = process.poll()
        if return_code is not None:
            if return_code != 0:
                print("[\033[91mCI/CD ERROR\033[0m]: Failed to push modifications", file=sys.stderr)
                exit(1)
            break

# Compiling src files
def execute_command(stack):

    # Executing command line
    print("\033[94mRunning\033[0m \"" + str(stack.top()) +  "\" ...")
    process = subprocess.Popen(stack.top(),
                           stdout=subprocess.PIPE,
                           universal_newlines=True)

    # Waiting for the process to end
    while True:

        # Getting the return code
        return_code = process.poll()
        if return_code is not None:
            if return_code != 0:
                print("[\033[91mCI/CD ERROR\033[0m]: the last operation \"\033[94m" + str(stack.top()) + "\033[0m\" returned " + str(return_code), file=sys.stderr)
                exit(1)
            stack.pop()
            break

def commit_files():

    # Add all files
    process = subprocess.Popen(["git", "add", "--all"],
                           stdout=subprocess.PIPE,
                           universal_newlines=True)
    wait(process)
    print()

    # Get commit message and branch
    commit = input("Please specify your \033[94mcommit message\033[0m: ")
    branch = input("Please specify the \033[94mbranch\033[0m: ")
    process = subprocess.Popen(["git", "commit", "-m", commit],
                           stdout=subprocess.PIPE,
                           universal_newlines=True)
    wait(process)

    # Push modification    
    process = subprocess.Popen(["git", "push", "origin", branch],
                           stdout=subprocess.PIPE,
                           universal_newlines=True)
    wait(process)

# Main function
def main():
    conf = confReader.ConfigReader("/etc/pipeline.conf")
    steps = conf.get_all()
    stack = Stack()

    # fill stack
    for step in steps:
        stack.push(step)

    # Emptying stack of commands
    while stack.empty() != True:
        execute_command(stack)

    commit_files()

# Launch main
if __name__ == "__main__":
    main()