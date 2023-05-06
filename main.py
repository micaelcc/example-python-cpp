import subprocess
import os
import time
import signal

CPP_FILE_NAME = "main.cpp"
GCC_COMPILE_COMMAND = "g++ -o main " + CPP_FILE_NAME + " -lGL -lglut"

path = os.path.dirname(os.path.abspath(__file__))
os.chdir(path)


def hasFileChanged():
    modify_time = os.path.getmtime(CPP_FILE_NAME)

    current_time = time.time()

    time_diff = current_time - modify_time

    # 0.2 s
    if time_diff <= 0.20:
        return True

    return False


def recompile():
    command = GCC_COMPILE_COMMAND.split()
    subprocess.call(command)


recompile()

process = subprocess.Popen(["./main"])

while True:
    if hasFileChanged():
        os.kill(process.pid, signal.SIGINT)

        recompile()
        process = subprocess.Popen(["./main"])

        time.sleep(1)
