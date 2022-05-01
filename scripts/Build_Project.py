import os
import subprocess

VS_BUILD_PATH = os.environ["VS_BUILD_PATH"][8:-1]
VS_BUILD_PATH = "C:\\\\" + VS_BUILD_PATH

ret = subprocess.call(["cmd.exe", "/c", VS_BUILD_PATH,
                       "Jengin.sln", "/property:Configuration={}".format("debug")])
